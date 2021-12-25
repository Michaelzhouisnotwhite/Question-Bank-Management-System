#include "pch.h"
#include "CDataBaseUser.h"

#include "utils.hpp"


CDataBaseUser::CDataBaseUser()
{
}

CDataBaseUser::CDataBaseUser(const CString id): teacher_id(id)
{
}

CDataBaseUser::~CDataBaseUser()
{
}

void CDataBaseUser::ExamQueryBuffer::clear()
{
	choice_content.clear();
	complete_content.clear();
	judge_content.clear();
	short_answer_content.clear();
}

// CDataBaseUser::ExamQueryBuffer::ExamQueryBuffer(const CPaperPreviewDlg::ExamQueryBuffer& m_exam_query_buffer)
// {
// 	choice_content = m_exam_query_buffer.choice_content;
// 	complete_content = m_exam_query_buffer.complete_content;
// 	judge_content = m_exam_query_buffer.judge_content;
// 	short_answer_content = m_exam_query_buffer.short_answer_content;
// }

int CDataBaseUser::FindAuthorityClass()
{
	authority_class.clear();
	CString table_name;
	CString command =
		m_dbParam.authority_class +
		L"WHERE teacher.teacher_id = " + teacher_id;
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		uint64_t rows = mysql_num_rows(res);
		for (uint64_t i = 0; i < rows; i++)
		{
			MYSQL_ROW row = mysql_fetch_row(res);

			authority_class.push_back(CharToCString(row[0]));
		}

		mysql_free_result(res);
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::FilterChoice(const CString q_type, const CString q_chapter, const CString q_class)
{
	query_buffer.clear();
	query_feild.clear();
	CString command =
		L"SELECT\n\
question.question_id,\n\
choice_question.choice_content,\n\
choice_question.option1,\n\
choice_question.option2,\n\
choice_question.option3,\n\
choice_question.option4,\n\
choice_question.choice_answer\n\
FROM\n\
(question ,\n\
tc)\n\
INNER JOIN choice_question ON choice_question.choice_id = question.question_id\n\
INNER JOIN chapter ON question.question_chapter_id = chapter.chapter_id\n\
INNER JOIN course ON tc.course = course.course_id AND chapter.course_id = course.course_id\n\
INNER JOIN course_questiontype ON course_questiontype.Cqtype_course_id = course.course_id\n\
INNER JOIN question_type ON question.question_type_id = question_type.question_type_id AND course_questiontype.Cqtype_Qtype_id = question_type.question_type_id\n\
WHERE tc.teacher = " + teacher_id + L"\n\
  AND chapter.chapter_name = " + AddSingleQuotesToCString(q_chapter) + L"\n\
  AND course.course_name = " + AddSingleQuotesToCString(q_class) + L"\n\
  AND question_type.question_name = " + AddSingleQuotesToCString(q_type);
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		uint64_t fields = mysql_num_fields(res);
		uint64_t rows = mysql_num_rows(res);
		for (uint64_t i = 0; i < fields; i++)
		{
			MYSQL_FIELD* field = mysql_fetch_field(res);
			query_feild.push_back(CharToCString(field->name));
		}

		for (uint64_t i = 0; i < rows; i++)
		{
			std::vector<CString> tmp_row;
			MYSQL_ROW row = mysql_fetch_row(res);
			for (size_t j = 0; j < query_feild.size(); j++)
			{
				tmp_row.push_back(CharToCString(row[j]));
			}
			query_buffer.push_back(tmp_row);
		}

		mysql_free_result(res);
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::FilterComplete(const CString q_type, const CString q_chapter, const CString q_class)
{
	query_buffer.clear();
	query_feild.clear();
	CString command =
		L"SELECT question.question_id,\n\
       completion_question.completion_content,\n\
       completion_question.completion_answer1,\n\
       completion_question.completion_answer2,\n\
       completion_question.completion_answer3,\n\
       completion_question.completion_answer4,\n\
       completion_question.completion_answer5\n\
FROM (question ,\n\
    tc)\n\
         INNER JOIN chapter ON question.question_chapter_id = chapter.chapter_id\n\
         INNER JOIN course ON tc.course = course.course_id AND chapter.course_id = course.course_id\n\
         INNER JOIN course_questiontype ON course_questiontype.Cqtype_course_id = course.course_id\n\
         INNER JOIN question_type ON question.question_type_id = question_type.question_type_id AND\n\
                                     course_questiontype.Cqtype_Qtype_id = question_type.question_type_id\n\
         INNER JOIN completion_question ON completion_question.completion_id = question.question_id\n\
WHERE tc.teacher = " + teacher_id + L"\n\
  AND chapter.chapter_name = " + AddSingleQuotesToCString(q_chapter) + L"\n\
  AND course.course_name = " + AddSingleQuotesToCString(q_class) + L"\n\
  AND question_type.question_name = " + AddSingleQuotesToCString(q_type);
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		uint64_t fields = mysql_num_fields(res);
		uint64_t rows = mysql_num_rows(res);
		for (uint64_t i = 0; i < fields; i++)
		{
			MYSQL_FIELD* field = mysql_fetch_field(res);
			query_feild.push_back(CharToCString(field->name));
		}

		for (uint64_t i = 0; i < rows; i++)
		{
			std::vector<CString> tmp_row;
			MYSQL_ROW row = mysql_fetch_row(res);
			for (size_t j = 0; j < query_feild.size(); j++)
			{
				tmp_row.push_back(CharToCString(row[j]));
			}
			query_buffer.push_back(tmp_row);
		}

		mysql_free_result(res);
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::FilterJudge(CString q_type, CString q_chapter, CString q_class)
{
	query_buffer.clear();
	query_feild.clear();
	CString command =
		L"SELECT question.question_id,\n\
       judgment_question.judgment_content,\n\
       judgment_question.judgment_answer\n\
FROM (question ,\n\
    tc)\n\
         INNER JOIN chapter ON question.question_chapter_id = chapter.chapter_id\n\
         INNER JOIN course ON tc.course = course.course_id AND chapter.course_id = course.course_id\n\
         INNER JOIN course_questiontype ON course_questiontype.Cqtype_course_id = course.course_id\n\
         INNER JOIN question_type ON question.question_type_id = question_type.question_type_id AND\n\
                                     course_questiontype.Cqtype_Qtype_id = question_type.question_type_id\n\
         INNER JOIN judgment_question ON judgment_question.judgment_id = question.question_id\n\
WHERE tc.teacher = " + teacher_id + L"\n\
  AND chapter.chapter_name = " + AddSingleQuotesToCString(q_chapter) + L"\n\
  AND course.course_name = " + AddSingleQuotesToCString(q_class) + L"\n\
  AND question_type.question_name = " + AddSingleQuotesToCString(q_type);
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		uint64_t fields = mysql_num_fields(res);
		uint64_t rows = mysql_num_rows(res);
		for (uint64_t i = 0; i < fields; i++)
		{
			MYSQL_FIELD* field = mysql_fetch_field(res);
			query_feild.push_back(CharToCString(field->name));
		}

		for (uint64_t i = 0; i < rows; i++)
		{
			std::vector<CString> tmp_row;
			MYSQL_ROW row = mysql_fetch_row(res);
			for (size_t j = 0; j < query_feild.size(); j++)
			{
				tmp_row.push_back(CharToCString(row[j]));
			}
			query_buffer.push_back(tmp_row);
		}

		mysql_free_result(res);
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::AddQ(CString q_type, CString q_chapter, CString q_class, CString q_answer)
{
	return 0;
}

int CDataBaseUser::FindChapter(const CString& qclass)
{
	query_buffer.clear();
	CString command = L"select distinct chapter_name from" + AddParenthesesToCstring(m_dbParam.view) +
		L"Where course_name = " + AddSingleQuotesToCString(qclass);
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		uint64_t rows = mysql_num_rows(res);
		for (uint64_t i = 0; i < rows; i++)
		{
			MYSQL_ROW row = mysql_fetch_row(res);

			query_buffer.push_back({CharToCString(row[0])});
		}

		mysql_free_result(res);
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::UpdataChoice(CString q_id, CString q_content, std::vector<CString> option_list, CString key)
{
	CString command =
		L"UPDATE choice_question\n\
SET \n\
choice_question.choice_answer = " + AddSingleQuotesToCString(key) + L",\n\
choice_question.choice_content = " + AddSingleQuotesToCString(q_content) + L",\n\
choice_question.option1 = " + AddSingleQuotesToCString(option_list[0]) + L",\n\
choice_question.option2 = " + AddSingleQuotesToCString(option_list[1]) + L",\n\
choice_question.option3 = " + AddSingleQuotesToCString(option_list[2]) + L",\n\
choice_question.option4 = " + AddSingleQuotesToCString(option_list[3]) + L"\n\
WHERE choice_question.choice_id = " + q_id;
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::UpdateComplete(CString q_id, CString q_content, std::vector<CString> answer_list)
{
	CString command = L"UPDATE\n\
completion_question\n\
SET \n\
completion_content= " + AddSingleQuotesToCString(q_content) + L",\n\
completion_answer1=" + AddSingleQuotesToCString(answer_list[0]) + L",\n\
completion_answer2=" + AddSingleQuotesToCString(answer_list[1]) + L",\n\
completion_answer3=" + AddSingleQuotesToCString(answer_list[2]) + L",\n\
completion_answer4=" + AddSingleQuotesToCString(answer_list[3]) + L",\n\
completion_answer5=" + AddSingleQuotesToCString(answer_list[4]) + L"\n\
WHERE completion_id = " + q_id;
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::UpdataJudge(CString q_id, CString q_content, CString key)
{
	key = key == L"1" ? L"对" : L"错";
	CString command =
		L"UPDATE \n\
judgment_question\n\
SET \n\
judgment_content=" + AddSingleQuotesToCString(q_content) + L",\n\
judgment_answer=" + AddSingleQuotesToCString(key) + L"\n\
WHERE judgment_id = " + q_id;
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

int CDataBaseUser::GenSubQtype(CString nums, CString q_type, CString q_class)
{
	query_buffer_2.clear();
	CString command = GetSqlOfEachType(nums, q_type, q_class);

	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		uint64_t rows = mysql_num_rows(res);
		for (uint64_t i = 0; i < rows; i++)
		{
			MYSQL_ROW row = mysql_fetch_row(res);
			std::vector<CString> tmp;
			for (int j = 0; j < mysql_num_fields(res); j++)
			{
				tmp.push_back(CharToCString(row[j]));
			}
			query_buffer_2.push_back(tmp);
		}
		if (q_type == L"选择题")
		{
			m_exam_query_buffer.choice_content = query_buffer_2;
		}
		else if (q_type == L"填空题")
		{
			m_exam_query_buffer.complete_content = query_buffer_2;
		}
		else if (q_type == L"判断题")
		{
			m_exam_query_buffer.judge_content = query_buffer_2;
		}
		else
		{
			m_exam_query_buffer.short_answer_content = query_buffer_2;
		}

		mysql_free_result(res);
		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

CString CDataBaseUser::GetSqlOfEachType(CString nums, CString q_type, CString q_class)
{
	CString command;
	if (q_type == L"选择题")
	{
		command =
			L"SELECT\n\
choice_question.choice_content,\n\
choice_question.option1,\n\
choice_question.option2,\n\
choice_question.option3,\n\
choice_question.option4,\n\
question.question_id,\n\
choice_question.choice_answer\n\
FROM\n\
(question ,\n\
tc)\n\
INNER JOIN choice_question ON choice_question.choice_id = question.question_id\n\
INNER JOIN chapter ON question.question_chapter_id = chapter.chapter_id\n\
INNER JOIN course ON tc.course = course.course_id AND chapter.course_id = course.course_id\n\
INNER JOIN course_questiontype ON course_questiontype.Cqtype_course_id = course.course_id\n\
INNER JOIN question_type ON question.question_type_id = question_type.question_type_id AND course_questiontype.Cqtype_Qtype_id = question_type.question_type_id\n\
WHERE tc.teacher = " + teacher_id + L"\n\
  AND course.course_name = " + AddSingleQuotesToCString(q_class) + L"\n\
  AND question_type.question_name = " + AddSingleQuotesToCString(q_type) +
			L"\norder by rand() limit " + nums;
	}
	else if (q_type == L"填空题")
	{
		command = L"SELECT\n\
completion_question.completion_content,\n\
question.question_id,\n\
completion_question.completion_answer1,\n\
completion_question.completion_answer2,\n\
completion_question.completion_answer3,\n\
completion_question.completion_answer4,\n\
completion_question.completion_answer5\n\
FROM\n\
course\n\
INNER JOIN chapter ON chapter.course_id = course.course_id\n\
INNER JOIN question ON question.question_chapter_id = chapter.chapter_id\n\
INNER JOIN tc ON tc.course = course.course_id\n\
INNER JOIN question_type ON question.question_type_id = question_type.question_type_id\n\
INNER JOIN completion_question ON completion_question.completion_id = question.question_id\n\
WHERE tc.teacher = " + teacher_id + L"\n\
AND course.course_name = " + AddSingleQuotesToCString(q_class) + L"\n\
  AND question_type.question_name = " + AddSingleQuotesToCString(q_type) +
			L"\norder by rand() limit " + nums;
	}
	else if (q_type == L"判断题")
	{
		command = L"SELECT\n\
judgment_question.judgment_content,\n\
question.question_id,\n\
judgment_question.judgment_answer\n\
FROM\n\
course\n\
INNER JOIN chapter ON chapter.course_id = course.course_id\n\
INNER JOIN question ON question.question_chapter_id = chapter.chapter_id\n\
INNER JOIN tc ON tc.course = course.course_id\n\
INNER JOIN judgment_question ON judgment_question.judgment_id = question.question_id\n\
INNER JOIN question_type ON question.question_type_id = question_type.question_type_id\n\
WHERE\n\
tc.teacher = " + teacher_id + L"\n\
AND course.course_name =  " + AddSingleQuotesToCString(q_class) + L"\n\
  AND question_type.question_name = " + AddSingleQuotesToCString(q_type) +
			L"\norder by rand() limit " + nums;
	}
	return command;
}

int CDataBaseUser::InsertExamnation(CString q_class, CString exam_content)
{
	CString command = L"insert into examination (course_id, examination_content) values ";
	CString subcommand = command +
		AddParenthesesToCstring(GetClassId(q_class) + L", " + AddSingleQuotesToCString(exam_content));
	int ress = ExecuteSql(subcommand);
	if (ress == 0)
	{
		CString cmd = L"INSERT examination_question VALUES";
		std::vector<CString> sql_list;
		for (const auto& value : m_exam_query_buffer.judge_content)
		{
			CString values = AddParenthesesToCstring(GetNewExamId() + L", " + value[1]);
			sql_list.push_back(cmd + values);
		}

		for (const auto& value : m_exam_query_buffer.complete_content)
		{
			CString values = AddParenthesesToCstring(GetNewExamId() + L", " + value[1]);
			sql_list.push_back(cmd + values);
		}
		for (const auto& value : m_exam_query_buffer.choice_content)
		{
			CString values = AddParenthesesToCstring(GetNewExamId() + L", " + value[5]);
			sql_list.push_back(cmd + values);
		}

		for (const CString& str : sql_list)
		{
			int sub_ress = ExecuteSql(str);
			if (sub_ress)
			{
				return EXICUTE_ERROR;
			}
		}

		return EXICUTE_SUCCESS;
	}
	return EXICUTE_ERROR;
}

CString CDataBaseUser::GetClassId(const CString qclass)
{
	CString command = L"select course_id from course where course_name = " + AddSingleQuotesToCString(qclass);
	int ress = ExecuteSql(command);
	if (ress)
	{
		return Int2CString(EXICUTE_ERROR);
	}
	MYSQL_RES* res = mysql_store_result(&mysqlCon);
	MYSQL_ROW row = mysql_fetch_row(res);
	return CharToCString(row[0]);
}

CString CDataBaseUser::GetNewExamId()
{
	CString command = L"select examination_id from examination order by examination_time DESC limit 1";
	int ress = ExecuteSql(command);
	if (ress)
	{
		return Int2CString(EXICUTE_ERROR);
	}
	MYSQL_RES* res = mysql_store_result(&mysqlCon);
	MYSQL_ROW row = mysql_fetch_row(res);
	return CharToCString(row[0]);
}
