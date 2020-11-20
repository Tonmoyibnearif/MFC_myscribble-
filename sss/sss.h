
// sss.h : main header file for the sss application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CsssApp:
// See sss.cpp for the implementation of this class
//

class CsssApp : public CWinApp
{
public:
	CsssApp() noexcept;

	


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CsssApp theApp;
