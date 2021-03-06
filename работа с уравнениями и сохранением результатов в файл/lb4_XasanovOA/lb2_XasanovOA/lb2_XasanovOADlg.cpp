
// lb2_XasanovOADlg.cpp: файл реализации
//

#include "stdafx.h"
#include "lb2_XasanovOA.h"
#include "lb2_XasanovOADlg.h"
#include "afxdialogex.h"
#include "math.h"

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


// Диалоговое окно Clb2XasanovOADlg



Clb2XasanovOADlg::Clb2XasanovOADlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LB2_XASANOVOA_DIALOG, pParent)
	, m_EditA(0)
	, m_EditB(0)
	, m_EditC(0)
	, m_message(FALSE)
	, m_Result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clb2XasanovOADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EditA);
	DDX_Text(pDX, IDC_EDIT2, m_EditB);
	DDX_Text(pDX, IDC_EDIT3, m_EditC);
	DDX_Control(pDX, IDC_RADIO1, m_Kvadrat);
	DDX_Control(pDX, IDC_RADIO2, m_Bikvadrat);
	DDX_Check(pDX, IDC_CHECK1, m_message);
	DDX_Text(pDX, IDC_STATIC1, m_Result);
}

BEGIN_MESSAGE_MAP(Clb2XasanovOADlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_Solve, &Clb2XasanovOADlg::OnBnClickedSolve)
END_MESSAGE_MAP()


// Обработчики сообщений Clb2XasanovOADlg

BOOL Clb2XasanovOADlg::OnInitDialog()
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
	m_EditA = 2;
	m_EditB = 3;
	m_EditC = -1;
	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Clb2XasanovOADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clb2XasanovOADlg::OnPaint()
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
HCURSOR Clb2XasanovOADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clb2XasanovOADlg::OnBnClickedSolve()
{
	char S[80];
	FILE *f;
	double a, b, c, d, x1, x2, y1, y2, y3, y4;
	UpdateData(TRUE);
	//считываем значения a,b,c из полей редактирования
	a = m_EditA;
	b = m_EditB;
	c = m_EditC;
	//вычисляем дискриминант
	d = b * b - 4 * a*c;
	//Функция (метод) GetCheck() проверяет, выбрана ли радиокнопка,
	//в данном случае выбрана m_Kvadrat
	if (m_Kvadrat.GetCheck())
		if (d<0)
			sprintf(S, "Корней нет");
		else
		{
			x1 = (-b + sqrt(d)) / 2 / a;
			x2 = (-b - sqrt(d)) / (2 * a);
			sprintf(S, "x1=%g\tx2=%g", x1, x2);
		}
	else
	{
		if (d<0)
			sprintf(S, "Корней нет");
		else
		{
			x1 = (-b + sqrt(d)) / 2 / a;
			x2 = (-b - sqrt(d)) / (2 * a);
			if ((x1<0) && (x2<0))
				sprintf(S, "Корней нет");
			else if ((x1 >= 0) && (x2 >= 0))
			{
				y1 = sqrt(x1);
				y2 = -y1;
				y3 = sqrt(x2);
				y4 = -y3;
				sprintf(S, "четыре корня: y1=%f\ty2=%f\ty3=%f\ty4=%f", y1, y2, y3, y4);
			}
			else if (x1 >= 0)
			{
				y1 = sqrt(x1);
				y2 = -y1;
				sprintf(S, "два корня: y1=%f\ty2=%f", y1, y2);
			}
			else
			{
				y1 = sqrt(x2);
				y2 = -y1;
				sprintf(S, "два корня: y1=%f\ty2=%f", y1, y2);
			}
		}
	}
	//в зависимости от флажка message
	if (m_message)
	{
		f = fopen("Result.txt", "w");
		fprintf(f, S);
		fclose(f);
	}
	else
	{
		m_Result = S;
		UpdateData(FALSE);
	}
	// TODO: добавьте свой код обработчика уведомлений
}
