
// lb2_XasanovOA.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Clb2XasanovOAApp:
// Сведения о реализации этого класса: lb2_XasanovOA.cpp
//

class Clb2XasanovOAApp : public CWinApp
{
public:
	Clb2XasanovOAApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Clb2XasanovOAApp theApp;
