#pragma once
#include <vector>

#include "CDataBase.h"

class CDataBaseUser final : public CDataBase
{
public:
	CString teacher_id{};
	CDataBaseUser();
	explicit CDataBaseUser(CString id);
	~CDataBaseUser() override;

	std::vector<CString> authority_class;
	std::vector<std::vector<CString>> query_buffer;

	std::vector<std::vector<CString>> query_buffer_2;

	struct ExamQueryBuffer
	{
		std::vector<std::vector<CString>> choice_content;
		std::vector<std::vector<CString>> complete_content;
		std::vector<std::vector<CString>> judge_content;
		std::vector<std::vector<CString>> short_answer_content;
		void clear();
		// ExamQueryBuffer(const  CPaperPreviewDlg::ExamQueryBuffer& m_exam_query_buffer);
		ExamQueryBuffer() = default;
	};

	ExamQueryBuffer m_exam_query_buffer;

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

	int UpdataChoice(CString q_id, CString q_content, std::vector<CString> option_list, CString key);
	int UpdateComplete(CString q_id, CString q_content, std::vector<CString> answer_list);
	int UpdataJudge(CString q_id, CString q_content, CString key);

	int GenSubQtype(CString nums, CString q_type, CString q_class);
	CString GetSqlOfEachType(CString nums, CString q_type, CString q_class);

	int InsertExamnation(CString q_class, CString exam_content);

	CString GetClassId(CString qclass);
	CString GetNewExamId();

	int InsertQuestion();
	int DeleteQuestion();

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
