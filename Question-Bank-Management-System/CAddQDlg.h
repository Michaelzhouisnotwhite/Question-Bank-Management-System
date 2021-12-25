#pragma once
#include "afxdialogex.h"


// CAddQDlg 对话框

class CAddQDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddQDlg)

public:
	CAddQDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAddQDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ADDQ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();

	int is_choice =0;
	int is_complete =0;
	int is_judge =0;
};
