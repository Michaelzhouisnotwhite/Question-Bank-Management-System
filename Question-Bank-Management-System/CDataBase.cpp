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
 * \brief 连接数据库
 */
// CDataBase::CDataSource()
// {
// 	mysql_init(&mysqlCon);
// 	if (!mysql_real_connect(&mysqlCon, host, user, pswd, database, port, nullptr, 0))
// 	{
// 		AfxMessageBox(L"访问数据库失败!");
// 	}
// 	else
// 	{
// 		// mysql_query(&mysqlCon, "SET character set UTF8"); //设置字符集
// 		mysql_set_character_set(&mysqlCon, "GBK");
// 	}
// }

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
int CDataBase::ExecuteSql(CString& sCommand)
{
	auto command = CStringToChar(sCommand);
	int ress = mysql_query(&mysqlCon, command);
	delete[] command;
	return ress;
}

CDataBase::CDataBase()
{
	// OpenExeFile(L"open", L"getconfigration.exe");
	CDoc cd("config_output");
	db_user = CStringToChar(cd.cstr_list[0]);
	db_pswd = CStringToChar(cd.cstr_list[1]);
	db_host = CStringToChar(cd.cstr_list[2]);
	// db_database = CStringToChar(cd.cstr_list[3]);

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

/**
 * \brief 在两边添加单引号
 */
inline char* CDataBase::CStringToChar(CString& cstr)
{
	unsigned len = WideCharToMultiByte(CP_ACP, 0, cstr, cstr.GetLength(),NULL, 0,NULL,NULL);
	auto pFileName = new char[static_cast<long>(len + 1)];
	WideCharToMultiByte(CP_ACP, 0, cstr, cstr.GetLength(), pFileName, len,NULL,NULL);
	pFileName[len] = '\0';
	return pFileName;
}

CString CDataBase::CharToCString(const char* str)
{
	return CString(str);
}

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
 * \param user_name 待查用户名
 * \return 是否查询正确
 */
BOOL CDataBase::SearchUserName(const CString& user_name)
{
	CString select = _T("select user_name  FROM login_info  where user_name=");
	CString where = L"\'" + user_name + L"\'";
	CString sCombine = select + where;

	int ress = ExecuteSql(sCombine);
	if (ress == 0)
	{
		res = mysql_store_result(&mysqlCon);
		if (mysql_num_rows(res) == 0)
		{
			return FALSE;
		}
		row = mysql_fetch_row(res);
		// this->user_name = user_name;
		return TRUE;
	}


	return -1;
}
