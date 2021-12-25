#pragma once
#include <vector>

#include "CDataBaseUser.h"
#include "afxdialogex.h"


// CPaperPreviewDlg 对话框

class CPaperPreviewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPaperPreviewDlg)

public:
	CPaperPreviewDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CPaperPreviewDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PREVIEW_PAPER_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOut();

	struct ExamQueryBuffer
	{
		std::vector<std::vector<CString>> choice_content;
		std::vector<std::vector<CString>> complete_content;
		std::vector<std::vector<CString>> judge_content;
		std::vector<std::vector<CString>> short_answer_content;
		void clear();
		// ReSharper disable once CppNonExplicitConvertingConstructor
		ExamQueryBuffer(const CDataBaseUser::ExamQueryBuffer& m_exam_query_buffer);
		ExamQueryBuffer() = default;
	};

	ExamQueryBuffer m_exam_query_buffer;
	BOOL OnInitDialog() override;
	void PrintExamBuffer();
	CRichEditCtrl m_EditPreview;

	CString q_class;
	CDataBaseUser *cdbu;
};
