// WarnBlocking.cpp : implementation file
//

#include "stdafx.h"
#include "KLog.h"
#include "WarnBlocking.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWarnBlocking dialog


CWarnBlocking::CWarnBlocking(CWnd* pParent /*=NULL*/)
	: CDialog(CWarnBlocking::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWarnBlocking)
	m_bDontWarn = FALSE;
	//}}AFX_DATA_INIT
}


void CWarnBlocking::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWarnBlocking)
	DDX_Check(pDX, IDC_WARNBLOCKING, m_bDontWarn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWarnBlocking, CDialog)
	//{{AFX_MSG_MAP(CWarnBlocking)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWarnBlocking message handlers
