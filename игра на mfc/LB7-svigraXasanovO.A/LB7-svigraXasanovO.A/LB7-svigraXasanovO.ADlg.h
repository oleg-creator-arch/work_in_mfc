
// LB7-svigraXasanovO.ADlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CLB7svigraXasanovOADlg
class CLB7svigraXasanovOADlg : public CDialogEx
{
// Создание
public:
	CLB7svigraXasanovOADlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LB7SVIGRAXASANOVOA_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	
	int hp_plaer=100, hp_vrag = 100,pobet_1=0, pobet_2 = 0;
	HICON icon_plS, icon_plN, icon_plT;
	int random_hick();
	CStatic icon_pl;
	CButton  res_plaer, res_vrag, res_pb1, res_pb2;
	CString s;

	afx_msg void OnBnClickedButton2();
	afx_msg void On32771();
};
