#pragma once
#include "afxdialogex.h"


// CJudgmentDlg 对话框

class CJudgmentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJudgmentDlg)

public:
	CJudgmentDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CJudgmentDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JUDGEMENT_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	BOOL OnInitDialog() override;


	void InitDlg();
	BOOL m_isReadable = TRUE;
	CRichEditCtrl m_edit;
	CButton m_radio_right;
	CButton m_radio_wrong;

	CString m_sText;
	CString m_sAnswer;
	CString m_sqid;

	void Set(CString content, CString answer);
	void SetQId(CString q_id);
	afx_msg void OnBnClickedCancel();
};
