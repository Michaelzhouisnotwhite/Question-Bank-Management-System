// CAddQDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CAddQDlg.h"


// CAddQDlg 对话框

IMPLEMENT_DYNAMIC(CAddQDlg, CDialogEx)

CAddQDlg::CAddQDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_ADDQ, pParent)
{
}

CAddQDlg::~CAddQDlg()
{
}

void CAddQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddQDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CAddQDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CAddQDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CAddQDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddQDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddQDlg 消息处理程序


void CAddQDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CAddQDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	is_judge = 1;
	CDialogEx::OnOK();
}


void CAddQDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	is_complete = 1;
	CDialogEx::OnOK();
}


void CAddQDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	is_choice = 1;
	CDialogEx::OnOK();
}
