// HBxTools.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CHBxToolsApp:
// See HBxTools.cpp for the implementation of this class
//

class CHBxToolsApp : public CWinApp
{
public:
	CHBxToolsApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CHBxToolsApp theApp;