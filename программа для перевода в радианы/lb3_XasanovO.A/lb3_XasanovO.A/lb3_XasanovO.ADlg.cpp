
// lb3_XasanovO.ADlg.cpp: файл реализации
//

#include "stdafx.h"
#include "lb3_XasanovO.A.h"
#include "lb3_XasanovO.ADlg.h"
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


// Диалоговое окно Clb3XasanovOADlg



Clb3XasanovOADlg::Clb3XasanovOADlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LB3_XASANOVOA_DIALOG, pParent)
	, m_Edit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clb3XasanovOADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
}

BEGIN_MESSAGE_MAP(Clb3XasanovOADlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_radian, &Clb3XasanovOADlg::OnBnClickedradian)
	ON_BN_CLICKED(IDCANCEL, &Clb3XasanovOADlg::OnBnClickedCancel)
	ON_COMMAND(ID_32771, &Clb3XasanovOADlg::On32771)
	ON_EN_CHANGE(IDC_EDIT1, &Clb3XasanovOADlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Обработчики сообщений Clb3XasanovOADlg

BOOL Clb3XasanovOADlg::OnInitDialog()
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

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void Clb3XasanovOADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Clb3XasanovOADlg::OnPaint()
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
HCURSOR Clb3XasanovOADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clb3XasanovOADlg::OnBnClickedradian()
{
	float gr, rad;
	char s[80];
	//UpdateData позволяет считать из компонента
	//"Поле редактирования" значение, введенное пользователем
	UpdateData(TRUE);
	//считывание в переменную gr данных из поля ввода
	if (m_Edit != NULL)
	{
		if (m_Edit == 180)
		{
			MessageBox("180 градусов это Pi радиан");
		}
		else
		{
			gr = m_Edit;
			rad = gr * 3.14159 / 180;
			sprintf_s(s, "%g градусов это %g радиан", gr, rad);
			//функция MessageBox формирует диалоговое окно
			//со строкой, хранящейся в переменной s
			MessageBox(s);
		}
	}
	else
	{
		MessageBox("Пока нет текста функции обработки");
	}



	// TODO: добавьте свой код обработчика уведомлений
}

void Clb3XasanovOADlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnCancel();
}


void Clb3XasanovOADlg::On32771()
{
	CAboutDlg dlg;
	dlg.DoModal();
	// TODO: добавьте свой код обработчика команд
}


void Clb3XasanovOADlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}
