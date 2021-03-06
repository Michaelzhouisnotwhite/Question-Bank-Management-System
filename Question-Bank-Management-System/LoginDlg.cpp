// LoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Question-Bank-Management-System.h"
#include "LoginDlg.h"

#include "CMainWinDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnClickedMenuShortAnswer();
	afx_msg void OnClickedBtnAddMenuComplete();
	afx_msg void OnClickedBtnAddMenuJudge();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	// ON_COMMAND(ID_32775, &CAboutDlg::OnClickedMenuShortAnswer)
	ON_COMMAND(ID_32782, &CAboutDlg::OnClickedBtnAddMenuComplete)
	ON_COMMAND(ID_32783, &CAboutDlg::OnClickedBtnAddMenuJudge)
END_MESSAGE_MAP()


// CLoginDlg 对话框


CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUESTIONBANKMANAGEMENTSYSTEM_DIALOG, pParent)

	  , m_sId(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PSW, m_sPsw);
	DDX_Text(pDX, IDC_EDIT_TEACHER_ID, m_sId);
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_TEACHER_ID, &CLoginDlg::OnEnChangeEditTeacherId)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_STATIC_LOG_PIC, &CLoginDlg::OnStnClickedStaticLogPic)
	ON_STN_CLICKED(IDC_STATIC_TITLE, &CLoginDlg::OnStnClickedStaticTitle)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE); // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// TODO: 在此添加额外的初始化代码
	auto p = static_cast<CStatic*>(GetDlgItem(IDC_STATIC_LOG_PIC));
	// NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
	p->MoveWindow(10, 10, 210, 190);

	CFont tmpFont;
	tmpFont.CreatePointFont(60, L"黑体", nullptr);
	GetDlgItem(IDC_STATIC_TITLE)->SetFont(&tmpFont);
	GetDlgItem(IDC_EDIT_TEACHER_ID)->SetWindowTextW(L"");
	return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

void CLoginDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLoginDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLoginDlg::OnEnChangeEditTeacherId()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CLoginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CDataBase cdb;

	int isFind = cdb.SearchUserIdPsw(m_sId, m_sPsw);
	if (isFind == CDataBase::USERNAME_WRONG)
	{
		MessageBoxW(L"教工号未登记", L"", MB_OK | MB_ICONERROR);
		GetDlgItem(IDC_EDIT_TEACHER_ID)->SetFocus();
	}
	else
	{
		if (isFind == CDataBase::PSW_RIGHT)
		{
			MessageBoxW(L"登录成功", L"", MB_OK | MB_ICONINFORMATION);

			CDialogEx::OnOK();
		}
		else
		{
			MessageBoxW(L"密码错误", L"", MB_OK | MB_ICONERROR);
			auto edit = static_cast<CEdit*>(GetDlgItem(IDC_EDIT_PSW));
			edit->SetWindowTextW(L"");
			edit->SetFocus();
		}
	}
}


void CLoginDlg::OnStnClickedStaticLogPic()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CLoginDlg::OnStnClickedStaticTitle()
{
	// TODO: 在此添加控件通知处理程序代码
}


//void CAboutDlg::OnClickedMenuShortAnswer()
//{
//	// TODO: 在此添加命令处理程序代码
//}


void CAboutDlg::OnClickedBtnAddMenuComplete()
{
	// TODO: 在此添加命令处理程序代码
	
}


void CAboutDlg::OnClickedBtnAddMenuJudge()
{
	// TODO: 在此添加命令处理程序代码
}
