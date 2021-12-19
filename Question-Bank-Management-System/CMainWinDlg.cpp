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
	DDX_Control(pDX, IDC_COMBO_QCLASS, m_qclass);
	DDX_Control(pDX, IDC_COMBO_QCHAPTER, m_qchapter);
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
	ON_COMMAND(ID_32780, &CMainWinDlg::OnClickedMenuCheck)
END_MESSAGE_MAP()


// CMainWinDlg 消息处理程序


BOOL CMainWinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	AfxInitRichEdit();
	AfxInitRichEdit2();

	InitDataBase();

	InitListCtrl();

	InitComboQtype();

	// InitComboQchapter();

	InitComboQclass();

	// m_table.InsertColumn(0, L"id", LVCFMT_CENTER, 0);
	// m_nCols++;

	m_table.InsertColumn(0, L"题号", LVCFMT_CENTER, 50);
	m_nCols++;
	m_table.InsertColumn(1, L"题目内容", LVCFMT_LEFT, 1000);
	m_nCols++;

	InitListTable();
	// m_qchapter.EnableWindow(FALSE);

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
	InitListTable();
}


void CMainWinDlg::OnCbnSelchangeComboQchapter()
{
	// TODO: 在此添加控件通知处理程序代码
	InitListTable();
}


void CMainWinDlg::OnCbnSelchangeComboQclass()
{
	// TODO: 在此添加控件通知处理程序代码
	int cur_sel = m_qclass.GetCurSel();
	CString data;
	m_qclass.GetLBText(cur_sel, data);
	InitComboQchapter(data);

	InitListTable();
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
	dlg.m_isReadable = TRUE;
	dlg.DoModal();
}


void CMainWinDlg::OnClickedToPaper()
{
	// TODO: 在此添加命令处理程序代码
}

void CMainWinDlg::InitDataBase()
{
	dbsu.teacher_id = m_sid;
	dbsu.FindAuthorityClass();
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

void CMainWinDlg::InitComboQchapter(const CString& data)
{
	m_qchapter.ResetContent();
	dbsu.FindChapter(data);
	if (dbsu.query_buffer.empty())
	{
		m_qchapter.AddString(L"没有该课程的章节号");
	}
	else
	{
		for (auto feild : dbsu.query_buffer)
		{
			m_qchapter.AddString(feild[0]);
		}
	}
	m_qchapter.SetCurSel(0);
}

void CMainWinDlg::InitComboQclass()
{
	for (const auto& feild : dbsu.authority_class)
	{
		m_qclass.AddString(feild);
	}
	m_qclass.SetCurSel(0);

	CString data;
	m_qclass.GetLBText(0, data);
	InitComboQchapter(data);
}

void CMainWinDlg::InitListTable()
{
	CString q_type = GetComboBoxText(&m_qtype);
	dbsu.query_buffer.clear();
	m_table.DeleteAllItems();
	for (int i = 2; i < 50; i++)
	{
		m_table.DeleteColumn(2);
	}

	m_nCols = 2;
	if (q_type == L"判断题")
	{
		dbsu.FilterJudge(q_type, GetComboBoxText(&m_qchapter), GetComboBoxText(&m_qclass));
		m_table.InsertColumn(2, L"答案", LVCFMT_LEFT, 100);
		m_nCols++;
	}
	else if (q_type == L"简答题")
	{
	}
	else if (q_type == L"填空题")
	{
		dbsu.FilterComplete(q_type, GetComboBoxText(&m_qchapter), GetComboBoxText(&m_qclass));
		for (size_t i = 2; i < dbsu.query_feild.size(); i++)
		{
			m_table.InsertColumn(static_cast<int>(i), L"答案" + Int2CString(i - 1), LVCFMT_LEFT, 100);
			m_nCols++;
		}
	}
	else if (q_type == L"选择题")
	{
		dbsu.FilterChoice(q_type, GetComboBoxText(&m_qchapter), GetComboBoxText(&m_qclass));
		for (size_t i = 2; i <= 5; i++)
		{
			m_table.InsertColumn(static_cast<int>(i), L"选项" + Int2CString(i - 1), LVCFMT_LEFT, 200);
			m_nCols++;
		}
		m_table.InsertColumn(6, L"答案", LVCFMT_LEFT, 100);
		m_nCols++;
	}


	for (size_t i = 0; i < dbsu.query_buffer.size(); i++)
	{
		auto row = dbsu.query_buffer[i];
		m_table.InsertItem(i, L"");
		for (size_t j = 0; j < row.size(); j++)
		{
			m_table.SetItemText(i, j, row[j]);
		}
	}
}

CString CMainWinDlg::GetComboBoxText(const CComboBox* box)
{
	CString str;
	box->GetLBText(box->GetCurSel(), str);
	return str;
}


void CMainWinDlg::OnClickedMenuCheck()
{
	// TODO: 在此添加命令处理程序代码
	CString q_type = GetComboBoxText(&m_qtype);
	if (q_type == L"判断题")
	{
		CJudgmentDlg dlg;
		dlg.Set(m_table.GetItemText(GetSelectedRow(), 1), m_table.GetItemText(GetSelectedRow(), 2));
		dlg.DoModal();
	}
	else if (q_type == L"简答题")
	{
	}
	else if (q_type == L"填空题")
	{
		
	}
	else if (q_type == L"选择题")
	{
		
	}

}

int CMainWinDlg::GetSelectedRow()
{
	int nIndex = -1;
	for (int i = 0; i < m_table.GetItemCount(); i++)
	{
		if (m_table.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString str;
			// str.Format(_T("选中了第%d行"), i);
			nIndex = i;
		}
	}
	return nIndex;
}
