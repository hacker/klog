// KLog.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "KLog.h"
#include "SyslogSocket.h"
#include "KLogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKLogApp

BEGIN_MESSAGE_MAP(CKLogApp, CWinApp)
	//{{AFX_MSG_MAP(CKLogApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKLogApp construction

CKLogApp::CKLogApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CKLogApp object

CKLogApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CKLogApp initialization

BOOL CKLogApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	SetRegistryKey(IDS_REGISTRYKEY);
	m_HelpFile = m_pszHelpFilePath;
	m_HelpFile+=">Standard";
	m_pszHelpFilePath=(LPCTSTR)m_HelpFile;

	CKLogDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
