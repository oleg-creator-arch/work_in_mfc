
// lb3_XasanovO.A.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Clb3XasanovOAApp:
// Сведения о реализации этого класса: lb3_XasanovO.A.cpp
//

class Clb3XasanovOAApp : public CWinApp
{
public:
	Clb3XasanovOAApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Clb3XasanovOAApp theApp;
