#pragma once
#include <vector>

#include "afxdialogex.h"


// CCompletionDlg 对话框

class CCompletionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCompletionDlg)

public:
	CCompletionDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCompletionDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMPLETE_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	
	CString m_sContent;
	BOOL m_isReadable = FALSE;

	std::vector<CString> m_sAnswer_list;
	void Set(const CString& sContent, const std::vector<CString>& answer_list);
	BOOL OnInitDialog() override;
	CEdit m_EditA1;
	CEdit m_EditA2;
	CEdit m_EditA3;
	CEdit m_EditA4;
	CEdit m_EditA5;
	CRichEditCtrl m_EditQ;

	std::vector<CEdit*> m_EditA_list;
	CString GetEditText(CEdit* edit);
};
inline CString CCompletionDlg::GetEditText(CEdit* edit)
{
	CString tmp;
	edit->GetWindowTextW(tmp);
	return tmp;
}
