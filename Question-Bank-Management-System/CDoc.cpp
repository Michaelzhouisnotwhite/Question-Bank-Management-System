#include "pch.h"
#include "CDoc.h"


CDoc::CDoc(const std::string& filename)
{
	
	stdFile.Open(CString(filename.c_str()), CStdioFile::modeRead);
	CString buffer;
	while (stdFile.ReadString(buffer))
	{
		cstr_list.push_back(buffer);
	}
}
