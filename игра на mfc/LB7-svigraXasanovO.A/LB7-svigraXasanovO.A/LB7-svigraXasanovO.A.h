
// LB7-svigraXasanovO.A.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLB7svigraXasanovOAApp:
// Сведения о реализации этого класса: LB7-svigraXasanovO.A.cpp
//

class CLB7svigraXasanovOAApp : public CWinApp
{
public:
	CLB7svigraXasanovOAApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLB7svigraXasanovOAApp theApp;
