
// lb5_XasanovOADlg.cpp: файл реализации
//

#include "stdafx.h"
#include "lb5_XasanovOA.h"
#include "lb5_XasanovOADlg.h"
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


// Диалоговое окно Clb5XasanovOADlg



Clb5XasanovOADlg::Clb5XasanovOADlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LB5_XASANOVOA_DIALOG, pParent)
	, m_edit_xk(0)
	, m_edit_dx(0)
	, m_edit_xn(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clb5XasanovOADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT2, m_edit_xk);
	DDX_Text(pDX, IDC_EDIT3, m_edit_dx);
	DDX_Text(pDX, IDC_EDIT1, m_edit_xn);
	DDX_Control(pDX, IDC_LIST1, m_Result);
}

BEGIN_MESSAGE_MAP(Clb5XasanovOADlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_Solve, &Clb5XasanovOADlg::OnBnClickedSolve)
	ON_BN_CLICKED(ID_Clear, &Clb5XasanovOADlg::OnBnClickedClear)
	ON_LBN_SELCHANGE(IDC_LIST1, &Clb5XasanovOADlg::OnLbnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, &Clb5XasanovOADlg::OnLbnSelchangeList2)
END_MESSAGE_MAP()


// Обработчики сообщений Clb5XasanovOADlg

BOOL Clb5XasanovOADlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	m_edit_xn = -5;
	m_edit_xk = 4;
	m_edit_dx = 3;
	UpdateData(FALSE);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Clb5XasanovOADlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void Clb5XasanovOADlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR Clb5XasanovOADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clb5XasanovOADlg::OnBnClickedSolve()
{
	// TODO: добавьте свой код обработчика уведомлений
	int i; float x, xn, xk, dx, y, s, p;
	int x0 = 500, y0 = 150, kx = 20, ky = 20;
	CString S;
	UpdateData(TRUE);
	xn = m_edit_xn;
	xk = m_edit_xk;
	dx = m_edit_dx;
	CClientDC dc(this);
	CPen NewPen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&NewPen);
	if ((xn <= -20 && xn >= -50) || (xk >= 20 && xk <= 50))
	{
		kx = 5;
		x0 = 600;
	}
	if (xn <= -50 || xk >= 50)
	{
		kx = 1;
		x0 = 650;
	}
	//получение начальных координат 
	x = xn;
	y = exp(sin(x));

	//m_PointX = xn;
	//m_PointY = y;
	dc.MoveTo(x*kx + x0, -y * ky + y0);///*m_PointX*kx+*/ x0, /*-m_PointY*ky+*/ y0);
	for (s = 0, p = 1, x = xn, i = 0; x <= xk; x += dx, i++)
	{
		y = exp(sin(x)); s += y; p *= y;
		S.Format(_T("x=%g y=%g"), x, y);
		m_Result.AddString(S);
		S.Format(_T("s=%g p=%g"), s, p);
		m_Result.InsertString(0, S);
		//рисование 

		dc.LineTo(x*kx + x0, -y * ky + y0);
		m_PointX = x;
		m_PointY = y;
	}
}


void Clb5XasanovOADlg::OnBnClickedClear()
{
	// TODO: добавьте свой код обработчика уведомлений
	int j, n;
	n = m_Result.GetCount();
	for (j = 0; j < n; j++)
		m_Result.DeleteString(0);
	/*
	//стирание графика
	int i; float x, xn, xk, dx, y;
	int x0 = 640, y0 = 70, kx = 10, ky = 10;
	CString S;
	UpdateData(TRUE);
	xn = m_edit_xn;
	xk = m_edit_xk;
	dx = m_edit_dx;
	CClientDC dc(this);
	CPen NewPen(PS_SOLID | PS_GEOMETRIC | PS_ENDCAP_SQUARE, 450, RGB(242, 242,242));
	dc.SelectObject(&NewPen);
	//получение начальных координат
	x = xn;
	y = exp(sin(x));
	//m_PointX = xn;
	//m_PointY = y;
	dc.MoveTo(x*kx + x0, -y * ky + y0);///*m_PointX*kx+ x0, /*-m_PointY*ky+ y0);
	for (x = x0; x <= ; x + 5)
	{
		for (y = y0; y < 300; y + 5)
		{
			dc.LineTo(x*kx + x0, -y * ky + y0);
		}
	}
*/
}


void Clb5XasanovOADlg::OnLbnSelchangeList1()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void Clb5XasanovOADlg::OnLbnSelchangeList2()
{
	// TODO: добавьте свой код обработчика уведомлений
}
