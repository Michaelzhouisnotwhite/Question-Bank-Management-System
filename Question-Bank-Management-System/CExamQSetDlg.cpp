// CExamQSetDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CExamQSetDlg.h"


// CExamQSetDlg 对话框

IMPLEMENT_DYNAMIC(CExamQSetDlg, CDialogEx)

CExamQSetDlg::CExamQSetDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_EXAM_SET, pParent)
{

}

CExamQSetDlg::~CExamQSetDlg()
{
}

void CExamQSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CHOICE, m_EditChoice);
	DDX_Control(pDX, IDC_EDIT_COMPLETION, m_EditComplete);
	DDX_Control(pDX, IDC_EDIT_JUDGE, m_EditJudge);
	DDX_Control(pDX, IDC_EDIT_SHORT_Q, m_EditShortAnswer);
}


BEGIN_MESSAGE_MAP(CExamQSetDlg, CDialogEx)
	ON_BN_CLICKED(IDOK2, &CExamQSetDlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// CExamQSetDlg 消息处理程序


BOOL CExamQSetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CExamQSetDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nChoice = EditGetText(&m_EditChoice);
	m_nCompete = EditGetText(&m_EditComplete);
	m_nJudge = EditGetText(&m_EditJudge);
	m_nShortAnswer = EditGetText(&m_EditShortAnswer);
	CDialogEx::OnOK();
}

CString CExamQSetDlg::EditGetText(const CEdit* edit)
{
	CString tmp;
	edit->GetWindowTextW(tmp);
	return tmp;
}
