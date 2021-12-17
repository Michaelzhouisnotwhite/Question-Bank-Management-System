﻿
// LoginDlg.h: 头文件
//

#pragma once
#include "CDataBase.h"


// CLoginDlg 对话框
class CLoginDlg : public CDialogEx
{
// 构造
public:
	CLoginDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DIALOG};
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditTeacherId();
	afx_msg void OnBnClickedOk();

	afx_msg void OnStnClickedStaticLogPic();
	afx_msg void OnStnClickedStaticTitle();
//	unsigned long m_nID;
	CString m_sPsw;
	CString m_sId;
};
