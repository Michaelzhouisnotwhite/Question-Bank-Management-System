// CMainWindow.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CMainWindow.h"


// CMainWindow 对话框

IMPLEMENT_DYNAMIC(CMainWindow, CDialogEx)

CMainWindow::CMainWindow(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DLG, pParent)
{

}

CMainWindow::~CMainWindow()
{
}

void CMainWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainWindow, CDialogEx)
END_MESSAGE_MAP()


// CMainWindow 消息处理程序


BOOL CMainWindow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
