
// lb5_XasanovOA.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Clb5XasanovOAApp:
// Сведения о реализации этого класса: lb5_XasanovOA.cpp
//

class Clb5XasanovOAApp : public CWinApp
{
public:
	Clb5XasanovOAApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Clb5XasanovOAApp theApp;
