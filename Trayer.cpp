// Trayer.cpp : implementation file
//

#include "stdafx.h"
#include "KLog.h"
#include "Trayer.h"

#include "SyslogSocket.h"
#include "KLogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrayer

CTrayer::CTrayer()
{
	m_inMenu=0;
}

CTrayer::~CTrayer()
{
}


BEGIN_MESSAGE_MAP(CTrayer, CWnd)
	//{{AFX_MSG_MAP(CTrayer)
		ON_MESSAGE(WM_TRAYICON, OnTray)
	ON_COMMAND(ID_TRAY_ABOUTKLOG, OnTrayAboutklog)
	ON_COMMAND(ID_TRAY_EXIT, OnTrayExit)
	ON_COMMAND(ID_TRAY_HELP, OnTrayHelp)
	ON_COMMAND(ID_TRAY_SHOWKLOGWINDOW, OnTrayShowklogwindow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTrayer message handlers

CTrayer::CTrayer(CKLogDlg* daddy)
: m_inMenu(0), m_Daddy(daddy)
{
}

LRESULT CTrayer::OnTray(WPARAM wP,LPARAM lP)
{
	ASSERT(wP==IDC_TRAYICON);
	switch(lP){
	case WM_RBUTTONDOWN:
		{
		CMenu menu;
			VERIFY(menu.LoadMenu(IDD_KLOG_DIALOG));
		CMenu *popUp = menu.GetSubMenu(1);
			ASSERT(popUp);
		CPoint pt;
			VERIFY(::GetCursorPos(&pt));
			m_inMenu++;
			SetForegroundWindow();
			popUp->CheckMenuItem(ID_TRAY_SHOWKLOGWINDOW,MF_BYCOMMAND|(IsWindowVisible()?MF_CHECKED:MF_UNCHECKED));
			popUp->TrackPopupMenu(TPM_RIGHTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,pt.x,pt.y,this);
			m_inMenu--;
			SendMessage(WM_NULL);
		}
		break;
	case WM_LBUTTONDOWN:
		m_Daddy->SendMessage(WM_COMMAND,ID_TRAY_SHOWKLOGWINDOW);
		break;
	}
	return 0;
}

void CTrayer::OnTrayAboutklog() 
{
	m_Daddy->SendMessage(WM_COMMAND,ID_TRAY_ABOUTKLOG);
}

void CTrayer::OnTrayExit() 
{
	m_Daddy->SendMessage(WM_COMMAND,ID_TRAY_EXIT);
}

void CTrayer::OnTrayHelp() 
{
	m_Daddy->SendMessage(WM_COMMAND,ID_TRAY_HELP);
}

void CTrayer::OnTrayShowklogwindow() 
{
	m_Daddy->SendMessage(WM_COMMAND,ID_TRAY_SHOWKLOGWINDOW);
}
