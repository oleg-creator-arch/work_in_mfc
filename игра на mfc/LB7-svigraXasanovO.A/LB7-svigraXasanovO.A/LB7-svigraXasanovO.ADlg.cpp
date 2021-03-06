
// LB7-svigraXasanovO.ADlg.cpp: файл реализации
//

#include "stdafx.h"
#include "LB7-svigraXasanovO.A.h"
#include "LB7-svigraXasanovO.ADlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CLB7svigraXasanovOADlg



CLB7svigraXasanovOADlg::CLB7svigraXasanovOADlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LB7SVIGRAXASANOVOA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	icon_plS = AfxGetApp()->LoadIcon(IDI_SRedne);
	icon_plN = AfxGetApp()->LoadIcon(IDI_Norm);
	icon_plT = AfxGetApp()->LoadIcon(IDI_Tryp);
}

void CLB7svigraXasanovOADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
//	DDX_Text(pDX, IDC_STATICplaer, res_plaer);
	DDX_Control(pDX, IDC_STATICplaer, res_plaer);
	DDX_Control(pDX, IDC_STATICvrag, res_vrag);
	DDX_Control(pDX, IDC_STATICpb1, res_pb1);
	DDX_Control(pDX, IDC_STATICpb2, res_pb2);
	DDX_Control(pDX, IDC_STATICpl, icon_pl);
	 
}

BEGIN_MESSAGE_MAP(CLB7svigraXasanovOADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLB7svigraXasanovOADlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLB7svigraXasanovOADlg::OnBnClickedButton2)
	ON_COMMAND(ID_32771, &CLB7svigraXasanovOADlg::On32771)
END_MESSAGE_MAP()


// Обработчики сообщений CLB7svigraXasanovOADlg

BOOL CLB7svigraXasanovOADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLB7svigraXasanovOADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLB7svigraXasanovOADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLB7svigraXasanovOADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLB7svigraXasanovOADlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	hp_plaer -= random_hick();
	if(hp_plaer > 77)
		icon_pl.SetIcon(icon_plN);
	if (hp_plaer <= 77 && hp_plaer >0 )
		icon_pl.SetIcon(icon_plS);
	if (hp_plaer <= 0)
	{
		icon_pl.SetIcon(icon_plT);
		MessageBox("игрок 1 выиграл");
		hp_plaer = 100;
		hp_vrag = 100;
		pobet_1++;
		s.Format("%d", pobet_1);
		res_pb1.SetWindowText(s);
		s.Format("%d", hp_vrag);
		res_vrag.SetWindowText(s);
	}
	s.Format("%d", hp_plaer);
	res_plaer.SetWindowText(s);
}

int CLB7svigraXasanovOADlg::random_hick()
{
	srand(time(NULL));
	return rand() % 10;
}


void CLB7svigraXasanovOADlg::OnBnClickedButton2()
{
hp_vrag -= random_hick();
if (hp_plaer > 77)
icon_pl.SetIcon(icon_plN);
	if (hp_vrag <= 0)
	{
		MessageBox("игрок 2 выиграл");
		hp_plaer = 100;
		hp_vrag = 100;
		pobet_2++;
		s.Format("%d", pobet_2);
		res_pb2.SetWindowText(s);
		s.Format("%d", hp_plaer);
		res_plaer.SetWindowText(s);
		icon_pl.SetIcon(icon_plN);
	}
	s.Format("%d", hp_vrag);
	res_vrag.SetWindowText(s);
	// TODO: добавьте свой код обработчика уведомлений
}


void CLB7svigraXasanovOADlg::On32771()
{
	CAboutDlg dlg;
	dlg.DoModal();
	// TODO: добавьте свой код обработчика команд
}
