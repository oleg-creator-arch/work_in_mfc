
// lb5_XasanovOADlg.h: файл заголовка
//

#pragma once
#include "afxwin.h"


// Диалоговое окно Clb5XasanovOADlg
class Clb5XasanovOADlg : public CDialog
{
// Создание
public:
	Clb5XasanovOADlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LB5_XASANOVOA_DIALOG };
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
	float m_edit_xk;
	float m_edit_dx;
	float m_edit_xn;
	int m_PointX;
	int m_PointY;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedSolve();
	afx_msg void OnBnClickedClear();
	afx_msg void OnLbnSelchangeList1();
	CListBox m_Result;

//	CListBox m_graph;
	afx_msg void OnLbnSelchangeList2();
};
