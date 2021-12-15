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

public:
	MYSQL_RES* res{};
	MYSQL_ROW row{};
	MYSQL mysqlCon{};
	CDataBase();
	~CDataBase();
	int ExecuteSql(CString& sCommand);
	static inline char* CStringToChar(CString& cstr);
	static inline CString CharToCString(const char* str);
	static inline CString AddSingleQuotesToCString(const CString& cstr);
	static inline CString AddParenthesesToCstring(const CString& cstr);
	BOOL SearchUserName(const CString& user_name);
};
