
// Oleg_Xasanov_mfc1.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// COlegXasanovmfc1App:
// Сведения о реализации этого класса: Oleg_Xasanov_mfc1.cpp
//

class COlegXasanovmfc1App : public CWinApp
{
public:
	COlegXasanovmfc1App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern COlegXasanovmfc1App theApp;
