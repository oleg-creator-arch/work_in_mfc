
// lb2_XasanovOADlg.h: файл заголовка
//

#pragma once
#include "afxwin.h"


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
	float m_EditA;
	float m_EditB;
	float m_EditC;
	CButton m_Kvadrat;
	CButton m_Bikvadrat;
	BOOL m_message;
	CString m_Result;
	afx_msg void OnBnClickedSolve();
};
