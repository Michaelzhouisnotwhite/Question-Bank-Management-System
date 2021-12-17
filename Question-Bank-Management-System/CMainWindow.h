#pragma once
#include "afxdialogex.h"


// CMainWindow 对话框

class CMainWindow final: public CDialogEx
{
	DECLARE_DYNAMIC(CMainWindow)

public:
	CMainWindow(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMainWindow();


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog() override;
};
