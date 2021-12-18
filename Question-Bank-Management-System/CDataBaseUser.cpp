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
	for (auto value : filter_feilds)
	{
		for (auto i : value)
		{
			delete[] i;
		}
	}
}

int CDataBaseUser::FindAuthority()
{
	CString table_name;
	CString command = L"\
		SELECT DISTINCT\n\
		chapter.chapter_name,\n\
		course.course_name,\n\
		FROM\n\
		chapter ,\n\
		course_questiontype\n\
		INNER JOIN course ON chapter.course_id = course.course_id AND course_questiontype.Cqtype_course_id = course.course_id\n\
		INNER JOIN tc ON tc.course = course.course_id\n\
		INNER JOIN teacher ON tc.course = teacher.teacher_id\n\
		WHERE\n\
		teacher.teacher_id=" + teacher_id;
	int ress = this->ExecuteSql(command);
	if (ress == 0)
	{
		MYSQL_RES* res = mysql_store_result(&mysqlCon);
		uint64_t rows = mysql_num_rows(res);
		for (uint64_t i = 0; i < rows; i++)
		{
			MYSQL_ROW row = mysql_fetch_row(res);
			
			filter_feilds.push_back({StrCopy(row[0]), StrCopy(row[1])});
		}
		
		mysql_free_result(res);
	}
	else
	{
		return EXICUTE_ERROR;
	}
}

int CDataBaseUser::Filter(CString q_type, CString q_chapter, CString q_class)
{
	return 0;
}

int CDataBaseUser::AddQ(CString q_type, CString q_chapter, CString q_class, CString q_answer)
{
	return 0;
}
