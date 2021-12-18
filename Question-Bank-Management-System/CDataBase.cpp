#include "pch.h"
#include "CDataBase.h"
#include "CDoc.h"
#pragma comment(lib,"libmysql.lib")

BOOL OpenExeFile(LPCWSTR mode, LPCWSTR filename)
{
	SHELLEXECUTEINFO shell = {sizeof(shell)};
	shell.fMask = SEE_MASK_FLAG_DDEWAIT;
	shell.lpVerb = mode;
	shell.lpFile = filename;
	shell.nShow = SW_SHOWNORMAL;
	BOOL ret = ShellExecuteEx(&shell);
	return ret;
}


/**
 * \brief 关闭数据库
 */
CDataBase::~CDataBase()
{
	delete[] db_user;
	delete[] db_pswd;
	delete[] db_host;
	delete[] db_database;
	mysql_close(&mysqlCon);
}

/**
 * \brief 执行sql语句
 * \param sCommand sql语句
 * \return 是否执行成狗
 */
int CDataBase::ExecuteSql(const CString& sCommand)
{
	auto command = CStringToChar(sCommand);
	int ress = mysql_query(&mysqlCon, command);
	delete[] command;
	return ress;
}

int CDataBase::ExecuteRealSql(const CString& sCommand)
{
	auto command = CStringToChar(sCommand);
	int ress = mysql_real_query(&mysqlCon, command, static_cast<unsigned long>(strlen(command)));
	delete[] command;
	return ress;
}

/**
 * \brief 连接数据库
 */
CDataBase::CDataBase()
{
	// OpenExeFile(L"open", L"getconfigration.exe");
	CDoc cd("config_output");
	db_user = CStringToChar(cd.cstr_list[0]);
	db_pswd = CStringToChar(cd.cstr_list[1]);
	db_host = CStringToChar(cd.cstr_list[2]);
	db_database = CStringToChar(cd.cstr_list[3]);

	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, db_host, db_user, db_pswd, db_database, db_port, nullptr, 0))
	{
		AfxMessageBox(L"访问数据库失败!");
	}
	else
	{
		// mysql_query(&mysqlCon, "SET character set UTF8"); //设置字符集
		mysql_set_character_set(&mysqlCon, "GBK");
	}
}

inline char* CDataBase::CStringToChar(const CString& cstr)
{
	unsigned len = WideCharToMultiByte(CP_ACP, 0, cstr, cstr.GetLength(), nullptr, 0, nullptr, nullptr);
	auto mb_char = new char[static_cast<long>(len + 1)];
	WideCharToMultiByte(CP_ACP, 0, cstr, cstr.GetLength(), mb_char, static_cast<int>(len), nullptr, nullptr);
	mb_char[len] = '\0';
	return mb_char;
}

CString CDataBase::CharToCString(const char* str)
{
	return CString(str);
}


/**
 * \brief 在两边添加单引号
 */
inline CString CDataBase::AddSingleQuotesToCString(const CString& cstr)
{
	return L"\'" + cstr + L"\'";
}

// 两边添加括号
inline CString CDataBase::AddParenthesesToCstring(const CString& cstr)
{
	return L"(" + cstr + L")";
}

/**
 * \brief 查询用户名是否存在
 * \param user_id 待查id
 * \param user_psw 密码
 * \return 是否查询正确
 */
int CDataBase::SearchUserIdPsw(const CString& user_id, const CString& user_psw)
{
	CString select = L"select teacher_id, teacher_psw FROM " + login_table + L" where teacher_id=";

	const CString& where = user_id;
	CString sCombine = select + where;

	int return_code;
	int ress = ExecuteSql(sCombine);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		if (mysql_num_rows(res) == 0)
		{
			return_code = USERNAME_WRONG;
		}
		else
		{
			// return_code = USERNAME_RIGHT;
			MYSQL_ROW row = mysql_fetch_row(res);

			char* psw = row[1];
			if (CharToCString(psw) == user_psw)
			{
				return_code = PSW_RIGHT;
			}
			else
			{
				return_code = PSW_WRONG;
			}
		}
		mysql_free_result(res);
	}
	else
	{
		return_code = EXICUTE_ERROR;
	}
	return return_code;
}
