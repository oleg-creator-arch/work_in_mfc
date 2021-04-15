
// Oleg_Xasanov_mfc1Dlg.h: файл заголовка
//

#pragma once

// Диалоговое окно COlegXasanovmfc1Dlg
class COlegXasanovmfc1Dlg : public CDialog
{
// Создание
public:
	COlegXasanovmfc1Dlg(CWnd* pParent = NULL);	// стандартный конструктор
	int m_PointX; 
	int m_PointY; 
// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OLEG_XASANOV_MFC1_DIALOG };
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
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
