#pragma once
#include <vector>

#include "CDataBase.h"

class CDataBaseUser final : CDataBase
{
public:
	CString teacher_id{};
	CDataBaseUser();
	explicit CDataBaseUser(CString id);
	~CDataBaseUser() override;

	std::vector<std::vector<char*>> filter_feilds;
	int FindAuthority();
	int Filter(CString q_type, CString q_chapter, CString q_class);
	int AddQ(CString q_type, CString q_chapter, CString q_class, CString q_answer);
	static char* StrCopy(char* src);
};

inline char* CDataBaseUser::StrCopy(char* src)
{
	auto len = sizeof(src);
	auto dst = new char[len + 1];
	dst[len] = '\0';
	for (auto i = 0; i < len; i++)
	{
		*(dst + i) = *(src + i);
	}
	return dst;
}
