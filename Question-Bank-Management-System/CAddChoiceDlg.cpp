// CAddChoiceDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CAddChoiceDlg.h"


// CAddChoiceDlg 对话框

IMPLEMENT_DYNAMIC(CAddChoiceDlg, CDialogEx)

CAddChoiceDlg::CAddChoiceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_ADDQ, pParent)
{

}

CAddChoiceDlg::~CAddChoiceDlg()
{
}

void CAddChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddChoiceDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddChoiceDlg 消息处理程序
