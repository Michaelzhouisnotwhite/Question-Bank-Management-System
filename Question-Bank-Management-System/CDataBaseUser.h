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

	std::vector<CString> authority_class;
	std::vector<std::vector<CString>> query_buffer;
	std::vector<CString> query_feild;

	struct DataBaseParam
	{
		CString authority_class =
			L"SELECT DISTINCT course.course_name FROM (chapter ,	course_questiontype) INNER JOIN course ON chapter.course_id = course.course_id INNER JOIN tc ON tc.course = course.course_id INNER JOIN teacher ON tc.teacher = teacher.teacher_id\n";
		CString view =
			L"(chapter ,	course_questiontype) INNER JOIN course ON chapter.course_id = course.course_id INNER JOIN tc ON tc.course = course.course_id INNER JOIN teacher ON tc.teacher = teacher.teacher_id\n";
	};

	DataBaseParam m_dbParam;
	int FindAuthorityClass();
	int FilterChoice(CString q_type, CString q_chapter, CString q_class);
	int FilterComplete(CString q_type, CString q_chapter, CString q_class);
	int FilterJudge(CString q_type, CString q_chapter, CString q_class);
	int AddQ(CString q_type, CString q_chapter, CString q_class, CString q_answer);
	static char* StrCopy(char* src);
	
	int FindChapter(const CString& qclass);
};

inline char* CDataBaseUser::StrCopy(char* src)
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
