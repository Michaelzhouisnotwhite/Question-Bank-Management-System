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
	, m_sEditCA(_T(""))
{
	m_Choice_List = {&m_Choice1, &m_Choice2, &m_Choice3, &m_Choice4};
	m_Check_List = {&m_CheckA, &m_CheckB, &m_CheckC, &m_CheckD};
}

CChoiceDlg::~CChoiceDlg()
{
}

void CChoiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Choice1);
	DDX_Control(pDX, IDC_EDIT2, m_Choice2);
	DDX_Control(pDX, IDC_EDIT3, m_Choice3);
	DDX_Control(pDX, IDC_EDIT4, m_Choice4);
	DDX_Control(pDX, IDC_RADIO_A, m_CheckA);
	DDX_Control(pDX, IDC_RADIO_B, m_CheckB);
	DDX_Control(pDX, IDC_RADIO_C, m_CheckC);
	DDX_Control(pDX, IDC_RADIO_D, m_CheckD);
	DDX_Control(pDX, IDC_RICHEDIT21, m_qcontent);
	DDX_Text(pDX, IDC_EDIT1, m_sEditCA);
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
	// AfxInitRichEdit2();
	// AfxInitRichEdit();

	int i = 0;
	for (auto value : m_Choice_List)
	{
		value->SetReadOnly(m_isReadable);
		value->SetWindowTextW(m_sChoice_list[i]);
		i++;
	}
	i = 0;
	for (auto value : m_Check_List)
	{
		value->EnableWindow(!m_isReadable);
	}

	if (m_skey == L"A")
	{
		m_CheckA.SetCheck(1);
	}
	else if (m_skey == L"B")
	{
		m_CheckB.SetCheck(1);
	}
	else if (m_skey == L"C")
	{
		m_CheckC.SetCheck(1);
	}
	else if (m_skey == L"D")
	{
		m_CheckD.SetCheck(1);
	}


	m_qcontent.SetReadOnly(m_isReadable);

	m_qcontent.SetWindowTextW(m_sContent);
	return TRUE; // return TRUE unless you set the focus to a control
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
	UpdateData(TRUE);
	// CString t = m_sEditCA;
	if (!m_isReadable)
	{
		// GetDlgItem(IDC_RICHEDIT21)->GetWindowTextW(t);
		m_qcontent.GetWindowTextW(m_sContent);
		m_sChoice_list = {GetEditText(m_Choice_List[0]), GetEditText(m_Choice_List[1]), GetEditText(m_Choice_List[2]), GetEditText(m_Choice_List[3])};
		if (m_CheckA.GetCheck())
		{
			m_skey = L"A";
		}
		if (m_CheckB.GetCheck())
		{
			m_skey = L"B";
		}
		if (m_CheckC.GetCheck())
		{
			m_skey = L"C";
		}
		if (m_CheckD.GetCheck())
		{
			m_skey = L"D";
		}
	}
	CDialogEx::OnOK();
}

void CChoiceDlg::Set(const CString& sContent, const std::vector<CString>& choice_content_list, CString key)
{
	m_sContent = sContent;
	m_sChoice_list = choice_content_list;
	m_skey = key;
}

