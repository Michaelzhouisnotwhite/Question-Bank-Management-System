// CJudgmentDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CJudgmentDlg.h"


// CJudgmentDlg 对话框

IMPLEMENT_DYNAMIC(CJudgmentDlg, CDialogEx)

CJudgmentDlg::CJudgmentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_JUDGEMENT_DLG, pParent)
{
}

CJudgmentDlg::~CJudgmentDlg()
{
}

void CJudgmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_edit);
	DDX_Control(pDX, IDC_RADIO_RIGHT, m_radio_right);
	DDX_Control(pDX, IDC_RADIO_WRONG, m_radio_wrong);
}


BEGIN_MESSAGE_MAP(CJudgmentDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CJudgmentDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CJudgmentDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CJudgmentDlg 消息处理程序


void CJudgmentDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_isReadable)
	{
	}
	else
	{
		m_edit.GetWindowTextW(m_sText);
		m_sAnswer.Format(_T("%d"), m_radio_right.GetCheck());
	}
	CDialogEx::OnOK();
}


BOOL CJudgmentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	InitDlg();

	return TRUE; // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CJudgmentDlg::InitDlg()
{
	m_edit.SetReadOnly(m_isReadable);
	m_radio_right.EnableWindow(!m_isReadable);
	m_radio_wrong.EnableWindow(!m_isReadable);


	m_edit.SetWindowTextW(m_sText);
	if (m_sAnswer == L"对")
	{
		m_radio_right.SetCheck(1);
	}
	else
	{
		m_radio_wrong.SetCheck(1);
	}
	// test
	// m_radio_right.SetCheck(1);
}

void CJudgmentDlg::Set(const CString content, const CString answer)
{
	m_sText = content;
	m_sAnswer = answer;
}

void CJudgmentDlg::SetQId(CString q_id)
{
	m_sqid = q_id;
}


void CJudgmentDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
