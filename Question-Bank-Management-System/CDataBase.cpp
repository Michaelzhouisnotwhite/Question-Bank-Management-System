#include "pch.h"
#include "CDataBase.h"
/**
 * \brief 在两边添加单引号
 */
inline char* CDataBase::CStringToChar(CString& cstr)
{
	unsigned len = WideCharToMultiByte(CP_ACP, 0, cstr, cstr.GetLength(),NULL, 0,NULL,NULL);
	auto pFileName = new char[static_cast<long>(len + 1)];
	WideCharToMultiByte(CP_ACP,0,cstr,cstr.GetLength(),pFileName,len,NULL,NULL);
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

