#pragma once
template<class T>
CString GetEditText(T* edit)
{
	CString tmp;
	edit->GetWindowTextW(tmp);
	return tmp;
}

inline char* StrCopy(char* src)
{
	auto len = sizeof(src);
	auto dst = new char[len + 1];
	dst[len] = '\0';
	for (uint64_t i = 0; i < len; i++)
	{
		*(dst + i) = *(src + i);
	}
	return dst;
}

inline CString Int2CString(const uint64_t src)
{
	CString str;
	str.Format(_T("%llu"), src);
	return str;
}