#pragma once
#include "afxdialogex.h"


// CChoiceDlg 对话框

class CChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChoiceDlg)

public:
	CChoiceDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChoiceDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHOICE_ADD_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeRichedit21();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
};
