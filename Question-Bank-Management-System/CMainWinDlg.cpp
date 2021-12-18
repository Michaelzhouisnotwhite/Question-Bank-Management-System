// CMainWinDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CMainWinDlg.h"

#include "CAddQDlg.h"
#include "CChoiceDlg.h"
#include "CCompletionDlg.h"
#include "CJudgmentDlg.h"


// CMainWinDlg 对话框

IMPLEMENT_DYNAMIC(CMainWinDlg, CDialogEx)

CMainWinDlg::CMainWinDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_DLG, pParent)
{
	pMenu = new CMenu;
}

CMainWinDlg::~CMainWinDlg()
{
	delete pMenu;
}

void CMainWinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_Q, m_table);
	DDX_Control(pDX, IDC_COMBO_QTYPE, m_qtype);
}


BEGIN_MESSAGE_MAP(CMainWinDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_Q, &CMainWinDlg::OnLvnItemchangedListQ)
	ON_CBN_SELCHANGE(IDC_COMBO_QTYPE, &CMainWinDlg::OnCbnSelchangeComboQtype)
	ON_CBN_SELCHANGE(IDC_COMBO_QCHAPTER, &CMainWinDlg::OnCbnSelchangeComboQchapter)
	ON_CBN_SELCHANGE(IDC_COMBO_QCLASS, &CMainWinDlg::OnCbnSelchangeComboQclass)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_Q, &CMainWinDlg::OnNMRClickListQ)
	ON_COMMAND(ID_32772, &CMainWinDlg::OnClickedMenuModify)
	ON_COMMAND(ID_32773, &CMainWinDlg::OnClickedMenuAddChoice)
	ON_COMMAND(ID_32774, &CMainWinDlg::OnClickedMenuAddCompletion)
	ON_COMMAND(ID_32776, &CMainWinDlg::OnClickedMenuJudgment)
	ON_COMMAND(ID_32779, &CMainWinDlg::OnClickedToPaper)
END_MESSAGE_MAP()


// CMainWinDlg 消息处理程序


BOOL CMainWinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	AfxInitRichEdit();
	InitListCtrl();
	
	InitListTable();
	InitComboQtype();

	InitComboQchapter();

	InitComboQclass();

	dbsu.teacher_id = m_sid;
	return TRUE; // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CMainWinDlg::OnLvnItemchangedListQ(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


//void CMainWinDlg::OnBnClickedMenubtn1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}

void CMainWinDlg::InitListCtrl()
{
	DWORD dwStyle = m_table.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_table.SetExtendedStyle(dwStyle);
}


void CMainWinDlg::OnCbnSelchangeComboQtype()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMainWinDlg::OnCbnSelchangeComboQchapter()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMainWinDlg::OnCbnSelchangeComboQclass()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMainWinDlg::OnNMRClickListQ(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (pNMItemActivate->iItem != -1)
	{
		DWORD dwPos = GetMessagePos();
		CPoint point(LOWORD(dwPos), HIWORD(dwPos));

		CMenu menu;
		VERIFY(menu.LoadMenu( ID_MENU ));
		CMenu* popup = menu.GetSubMenu(0);
		ASSERT(popup != NULL);
		popup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
	*pResult = 0;
}


void CMainWinDlg::OnClickedMenuModify()
{
	// TODO: 在此添加命令处理程序代码
}


void CMainWinDlg::OnClickedMenuAddChoice()
{
	// TODO: 在此添加命令处理程序代码
	CChoiceDlg dlg;
	dlg.DoModal();
}


void CMainWinDlg::OnClickedMenuAddCompletion()
{
	// TODO: 在此添加命令处理程序代码
	CCompletionDlg dlg;
	dlg.DoModal();
}


void CMainWinDlg::OnClickedMenuJudgment()
{
	// TODO: 在此添加命令处理程序代码
	CJudgmentDlg dlg;
	dlg.DoModal();
}


void CMainWinDlg::OnClickedToPaper()
{
	// TODO: 在此添加命令处理程序代码
}

void CMainWinDlg::InitComboQtype()
{
	// m_qtype.AddString(L"<无>");
	m_qtype.AddString(L"选择题");
	m_qtype.AddString(L"填空题");
	m_qtype.AddString(L"判断题");
	m_qtype.AddString(L"简答题");
	m_qtype.SetCurSel(0);
}

void CMainWinDlg::InitComboQchapter()
{
}

void CMainWinDlg::InitComboQclass()
{
}

void CMainWinDlg::InitListTable()
{
	m_table.InsertColumn(0, L"id", LVCFMT_CENTER, 0);


	m_table.InsertColumn(2, L"题目内容", LVCFMT_CENTER, 200);
	m_table.InsertColumn(1, L"题号", LVCFMT_CENTER, 50);

	m_table.InsertItem(0, L"");
	m_table.SetItemText(0, 0, L"0");
	m_table.SetItemText(0, 1, L"0");
	m_table.SetItemText(0, 2, L"test");
}
