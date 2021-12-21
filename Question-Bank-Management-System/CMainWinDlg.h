#pragma once
#include "afxdialogex.h"
#include "CDataBaseUser.h"


// CMainWinDlg 对话框

class CMainWinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainWinDlg)

public:
	CMainWinDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMainWinDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL OnInitDialog() override;
	CString m_sid;
	afx_msg void OnLvnItemchangedListQ(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnBnClickedMenubtn1();
	CListCtrl m_table;
	void InitListCtrl();
	afx_msg void OnCbnSelchangeComboQtype();
	afx_msg void OnCbnSelchangeComboQchapter();
	afx_msg void OnCbnSelchangeComboQclass();
	afx_msg void OnNMRClickListQ(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickedMenuModify();
//	CMFCMenuButton m_MenuBtn;
	CMenu* pMenu;
	afx_msg void OnClickedMenuAddChoice();
	afx_msg void OnClickedMenuAddCompletion();
	afx_msg void OnClickedMenuJudgment();
	afx_msg void OnClickedToPaper();
	CComboBox m_qtype;

	CDataBaseUser dbsu;


	void InitDataBase();
	void InitComboQtype();
	void InitComboQchapter(const CString& data);
	void InitComboQclass();

	void InitListTable();

	static CString GetComboBoxText(const CComboBox *box);
	CComboBox m_qclass;
	CComboBox m_qchapter;

	int m_nCols = 0;
	afx_msg void OnClickedMenuCheck();

	int GetSelectedRow() const;

	CString GetSelectedColumn(int nColumn_idx) const;
	afx_msg void OnStnClickedStc4();
	afx_msg void OnBnClickedBtn2paper();

};

CString Int2CString(const uint64_t src);
