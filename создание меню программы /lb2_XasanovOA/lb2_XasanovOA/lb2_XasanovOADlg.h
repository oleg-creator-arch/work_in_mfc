
// lb2_XasanovOADlg.h: файл заголовка
//

#pragma once


// Диалоговое окно Clb2XasanovOADlg
class Clb2XasanovOADlg : public CDialog
{
// Создание
public:
	Clb2XasanovOADlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LB2_XASANOVOA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChangeEdit1();
	afx_msg void On32771();
	afx_msg void On32772();
//	afx_msg void On32773();
	CString m_S;
	afx_msg void On32774();
};
