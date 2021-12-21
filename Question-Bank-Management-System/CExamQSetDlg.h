#pragma once
#include "afxdialogex.h"


// CExamQSetDlg 对话框

class CExamQSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CExamQSetDlg)

public:
	CExamQSetDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CExamQSetDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_EXAM_SET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk2();

	CString m_nChoice;
	CString m_nCompete;
	CString m_nJudge;
	CString m_nShortAnswer;
	CEdit m_EditChoice;
	CEdit m_EditComplete;
	CEdit m_EditJudge;
	CEdit m_EditShortAnswer;

	static CString EditGetText(const CEdit * edit);
};
