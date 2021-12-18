#pragma once
#include <mysql.h>

BOOL OpenExeFile(LPCWSTR mode, LPCWSTR filename);

class CDataBase
{
	char* db_user = nullptr;
	char* db_pswd = nullptr;
	char* db_host = nullptr;
	char* db_database = nullptr;
	unsigned int db_port = 3306;
	const CString login_table = L"teacher";

public:
	static constexpr int USERNAME_WRONG = 1;
	static constexpr int USERNAME_RIGHT = 2;
	static constexpr int PSW_WRONG = 3;
	static constexpr int PSW_RIGHT = 4;
	static constexpr int EXICUTE_ERROR=-1;


	MYSQL mysqlCon{};
	CDataBase();

	virtual ~CDataBase();

	int ExecuteSql(const CString& sCommand);
	int ExecuteRealSql(const CString& sCommand);

	static inline char* CStringToChar(const CString& cstr);
	static inline CString CharToCString(const char* str);
	static inline CString AddSingleQuotesToCString(const CString& cstr);
	static inline CString AddParenthesesToCstring(const CString& cstr);
	int SearchUserIdPsw(const CString& user_id, const CString& user_psw);

};
