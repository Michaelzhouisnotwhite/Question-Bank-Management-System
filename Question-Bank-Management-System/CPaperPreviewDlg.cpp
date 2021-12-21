// CPaperPreviewDlg.cpp: 实现文件
//

#include "pch.h"
#include "Question-Bank-Management-System.h"
#include "afxdialogex.h"
#include "CPaperPreviewDlg.h"


// CPaperPreviewDlg 对话框

IMPLEMENT_DYNAMIC(CPaperPreviewDlg, CDialogEx)

CPaperPreviewDlg::CPaperPreviewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PREVIEW_PAPER_DLG, pParent)
{
}

CPaperPreviewDlg::~CPaperPreviewDlg()
{
}

void CPaperPreviewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_EditPreview);
}


BEGIN_MESSAGE_MAP(CPaperPreviewDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_OUT, &CPaperPreviewDlg::OnBnClickedBtnOut)
END_MESSAGE_MAP()


// CPaperPreviewDlg 消息处理程序


void CPaperPreviewDlg::OnBnClickedBtnOut()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CPaperPreviewDlg::ExamQueryBuffer::clear()
{
}

CPaperPreviewDlg::ExamQueryBuffer::ExamQueryBuffer(const CDataBaseUser::ExamQueryBuffer& m_exam_query_buffer)
{
	choice_content = m_exam_query_buffer.choice_content;
	complete_content = m_exam_query_buffer.complete_content;
	judge_content = m_exam_query_buffer.judge_content;
	short_answer_content = m_exam_query_buffer.short_answer_content;
}


BOOL CPaperPreviewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	PrintExamBuffer();

	return TRUE; // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CPaperPreviewDlg::PrintExamBuffer()
{
	CString wrap = L"\n";
	CString choice_text(L"一、选择题\n");
	CString complete_text(L"二、填空题\n");
	CString judge_text(L"三、判断题\n");
	int counter = 1;
	for (const auto& content : m_exam_query_buffer.choice_content)
	{
		choice_text += Int2CString(counter) + L". " + content[0] + L"(   )" + wrap;
		choice_text += L"A. " + content[1] + wrap;
		choice_text += L"B. " + content[1] + wrap;
		choice_text += L"C. " + content[1] + wrap;
		choice_text += L"D. " + content[1] + wrap;
		counter++;
	}

	for (auto content : m_exam_query_buffer.complete_content)
	{
		complete_text += Int2CString(counter) + L". " + content[0] + wrap;
		counter++;
	}
	for (auto content : m_exam_query_buffer.judge_content)
	{
		judge_text += Int2CString(counter) + L". " + content[0] + L"................(    )" + wrap;
		counter++;
	}
	m_EditPreview.SetWindowTextW(choice_text + L"\n" + complete_text + L"\n" + judge_text);
}

CString Int2CString(const uint64_t src)
{
	CString str;
	str.Format(_T("%llu"), src);
	return str;
}
