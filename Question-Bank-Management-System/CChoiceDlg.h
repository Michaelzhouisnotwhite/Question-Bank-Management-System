#pragma once
#include <vector>

#include "afxdialogex.h"


// CChoiceDlg 对话框

class CChoiceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChoiceDlg)

public:
	CChoiceDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CChoiceDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHOICE_ADD_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeRichedit21();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();

	BOOL m_isReadable = FALSE;
	
	CEdit m_Choice1;
	CEdit m_Choice2;
	CEdit m_Choice3;
	CEdit m_Choice4;
	
	CButton m_CheckA;
	CButton m_CheckB;
	CButton m_CheckC;
	CButton m_CheckD;

	std::vector<CEdit*> m_Choice_List;
	std::vector<CButton*> m_Check_List;
	CRichEditCtrl m_qcontent;

	CString m_sContent;

	void Set(const CString& sContent, const std::vector<CString>& choice_content_list, CString key);

	std::vector<CString> m_sChoice_list;
	CString m_skey;

	CString GetEditText(CEdit * edit);
	CString m_sEditCA;

};

inline CString CChoiceDlg::GetEditText(CEdit* edit)
{
	CString tmp;
	edit->GetWindowTextW(tmp);
	return tmp;
}
