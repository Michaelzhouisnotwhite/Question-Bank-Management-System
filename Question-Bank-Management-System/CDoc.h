#pragma once
#include <string>
#include <vector>

class CDoc
{
	CStdioFile stdFile;
public:
	std::vector<CString> cstr_list;
	explicit CDoc(const std::string& filename);
};

