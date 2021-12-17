#pragma once
#include "afxdialogex.h"


// CAddChoiceDlg 对话框

class CAddChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddChoiceDlg)

public:
	CAddChoiceDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAddChoiceDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_ADDQ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
