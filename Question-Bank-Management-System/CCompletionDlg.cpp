// CCompletionDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CCompletionDlg.h"

#include "utils.hpp"


// CCompletionDlg 对话框

IMPLEMENT_DYNAMIC(CCompletionDlg, CDialogEx)

CCompletionDlg::CCompletionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMPLETE_DLG, pParent)
{
	m_EditA_list = {&m_EditA1, &m_EditA2, &m_EditA3, &m_EditA4, &m_EditA5};
}

CCompletionDlg::~CCompletionDlg()
{
}

void CCompletionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditA1);
	DDX_Control(pDX, IDC_EDIT3, m_EditA2);
	DDX_Control(pDX, IDC_EDIT2, m_EditA3);
	DDX_Control(pDX, IDC_EDIT4, m_EditA4);
	DDX_Control(pDX, IDC_EDIT5, m_EditA5);
	DDX_Control(pDX, IDC_RICHEDIT21, m_EditQ);
}


BEGIN_MESSAGE_MAP(CCompletionDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCompletionDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCompletionDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CCompletionDlg 消息处理程序


void CCompletionDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!m_isReadable)
	{
		// CString tmp;
		// m_EditA2.GetWindowTextW(tmp);
		m_EditQ.GetWindowTextW(m_sContent);
		m_sAnswer_list = {
			GetEditText<CEdit>(m_EditA_list[0]), GetEditText<CEdit>(m_EditA_list[1]), GetEditText<CEdit>(m_EditA_list[2]),
			GetEditText<CEdit>(m_EditA_list[3]), GetEditText<CEdit>(m_EditA_list[4])
		};
	}
	CDialogEx::OnOK();
}


void CCompletionDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

void CCompletionDlg::Set(const CString& sContent, const std::vector<CString>& answer_list)
{
	m_sContent = sContent;
	m_sAnswer_list = answer_list;
}


BOOL CCompletionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	int tmp_answer_idx = 0;
	for (auto value : m_EditA_list)
	{
		value->SetReadOnly(m_isReadable);
		value->SetWindowTextW(m_sAnswer_list[tmp_answer_idx]);
		tmp_answer_idx++;
	}

	m_EditQ.SetReadOnly(m_isReadable);

	m_EditQ.SetWindowTextW(m_sContent);
	return TRUE; // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
