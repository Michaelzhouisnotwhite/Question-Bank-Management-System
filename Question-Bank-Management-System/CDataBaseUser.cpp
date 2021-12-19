#include "pch.h"
#include "CDataBaseUser.h"

CDataBaseUser::CDataBaseUser()
{
}

CDataBaseUser::CDataBaseUser(const CString id): teacher_id(id)
{
}

CDataBaseUser::~CDataBaseUser()
{
}

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
