// CChoiceDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CChoiceDlg.h"


// CChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CChoiceDlg, CDialogEx)

CChoiceDlg::CChoiceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHOICE_ADD_DLG, pParent)
{

}

CChoiceDlg::~CChoiceDlg()
{
}

void CChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChoiceDlg, CDialogEx)
	ON_EN_CHANGE(IDC_RICHEDIT21, &CChoiceDlg::OnEnChangeRichedit21)
	ON_EN_CHANGE(IDC_EDIT1, &CChoiceDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CChoiceDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CChoiceDlg 消息处理程序


void CChoiceDlg::OnEnChangeRichedit21()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL CChoiceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	AfxInitRichEdit2();
	AfxInitRichEdit();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CChoiceDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CChoiceDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
