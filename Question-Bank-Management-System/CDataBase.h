#pragma once
class CDataBase
{
	CDataBase();
	~CDataBase();
public:
	static inline char* CStringToChar(CString& cstr);
	static inline CString CharToCString(const char* str);
	static inline CString AddSingleQuotesToCString(const CString& cstr);
	static inline CString AddParenthesesToCstring(const CString& cstr);
};

