// KLogDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KLog.h"
#include "SyslogSocket.h"
#include "KLogDlg.h"

#include "Trayer.h"
#include "LogPattern.h"
#include "WarnBlocking.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_SERIAL( CKLogDlg, CDialog, VERSIONABLE_SCHEMA|1 );
IMPLEMENT_SERIAL( CLogger, CObject, VERSIONABLE_SCHEMA|1 );
IMPLEMENT_SERIAL( CLogEntry, CObject, VERSIONABLE_SCHEMA|1 );
IMPLEMENT_SERIAL( CHostMask, CObject, VERSIONABLE_SCHEMA|1 );

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnKlevernet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_KLEVERNET, OnKlevernet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKLogDlg dialog

CKLogDlg::CKLogDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKLogDlg::IDD, pParent)
{
	m_Logger=NULL;
	m_LogItems=15;
	m_bShown=TRUE;
	m_bExiting=FALSE;
	m_bWarnBlocking=TRUE;
	m_bDontWarn=TRUE;
	//{{AFX_DATA_INIT(CKLogDlg)
	m_Logto = -1;
	m_Desc = _T("");
	m_Facility = _T("");
	m_HFName = _T("");
	m_HFNameCaption = _T("");
	m_hlIP = _T("");
	m_hlMask = _T("");
	m_Sound = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bmpBack.LoadBitmap(IDB_BACKGROUND);
	m_bmpBack.GetBitmap(&m_bitmapBack);
	m_Trayer = new CTrayer(this);
	ASSERT(m_Trayer);
	LoadSettings();
}

void CKLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKLogDlg)
	DDX_Control(pDX, IDCANCEL, m_CancelCtl);
	DDX_Control(pDX, IDC_LOGPATTERN, m_LogPatternCtl);
	DDX_Control(pDX, IDC_FILES, m_FilesCtl);
	DDX_Control(pDX, IDC_LOGLENSPIN, m_LogLenSpinCtl);
	DDX_Control(pDX, IDC_LOGLENGTH, m_LogLengthCtl);
	DDX_Control(pDX, IDC_INVERT, m_PriInvertCtl);
	DDX_Control(pDX, IDC_TYPE_FILE, m_LogtoFileCtl);
	DDX_Control(pDX, IDC_TYPE_HOST, m_LogtoHostCtl);
	DDX_Control(pDX, IDC_TYPE_NONE, m_LogtoNoneCtl);
	DDX_Control(pDX, IDC_HOSTORFILE, m_HFNameCaptionCtl);
	DDX_Control(pDX, IDC_HOSTS, m_hlCtl);
	DDX_Control(pDX, IDC_BROWSESOUND, m_BrowseSoundCtl);
	DDX_Control(pDX, IDC_NONE, m_PriNoneCtl);
	DDX_Control(pDX, IDC_HL_REMOVE, m_hlRemoveCtl);
	DDX_Control(pDX, IDC_HL_MASK, m_hlMaskCtl);
	DDX_Control(pDX, IDC_HL_IP, m_hlIPCtl);
	DDX_Control(pDX, IDC_HL_ADD, m_hlAddCtl);
	DDX_Control(pDX, IDC_ALL, m_PriAllCtl);
	DDX_Control(pDX, IDC_SOUND, m_SoundCtl);
	DDX_Control(pDX, IDC_REMOVE, m_RemoveCtl);
	DDX_Control(pDX, IDC_PLAYSOUND, m_PlaySoundCtl);
	DDX_Control(pDX, IDC_LOG, m_Log);
	DDX_Control(pDX, IDC_HOSTFILE, m_HFNameCtl);
	DDX_Control(pDX, IDC_FACILITY, m_FacilityCtl);
	DDX_Control(pDX, IDC_BROWSE, m_BrowseCtl);
	DDX_Control(pDX, IDC_DESC, m_DescCtl);
	DDX_Control(pDX, IDC_TABS, m_Tabs);
	DDX_Radio(pDX, IDC_TYPE_FILE, m_Logto);
	DDX_Text(pDX, IDC_DESC, m_Desc);
	DDV_MaxChars(pDX, m_Desc, 50);
	DDX_CBString(pDX, IDC_FACILITY, m_Facility);
	DDX_Text(pDX, IDC_HOSTFILE, m_HFName);
	DDX_Text(pDX, IDC_HOSTORFILE, m_HFNameCaption);
	DDX_Text(pDX, IDC_HL_IP, m_hlIP);
	DDV_MaxChars(pDX, m_hlIP, 15);
	DDX_Text(pDX, IDC_HL_MASK, m_hlMask);
	DDV_MaxChars(pDX, m_hlMask, 15);
	DDX_CBString(pDX, IDC_SOUND, m_Sound);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CKLogDlg, CDialog)
	//{{AFX_MSG_MAP(CKLogDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABS, OnSelchangeTabs)
	ON_CBN_SELCHANGE(IDC_FACILITY, OnSelchangeFacility)
	ON_BN_CLICKED(IDC_ALERT, OnPriority)
	ON_BN_CLICKED(IDC_TYPE_FILE, OnLogto)
	ON_BN_CLICKED(IDC_ALL, OnPriAll)
	ON_BN_CLICKED(IDC_NONE, OnPriNone)
	ON_EN_CHANGE(IDC_DESC, OnChangeDesc)
	ON_BN_CLICKED(IDC_INVERT, OnPriInvert)
	ON_BN_CLICKED(IDC_HL_ADD, OnHlAdd)
	ON_LBN_SELCHANGE(IDC_HOSTS, OnSelchangeHosts)
	ON_BN_CLICKED(IDC_HL_REMOVE, OnHlRemove)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_BN_CLICKED(IDC_PLAYSOUND, OnPlaysound)
	ON_CBN_EDITCHANGE(IDC_SOUND, OnEditchangeSound)
	ON_CBN_KILLFOCUS(IDC_SOUND, OnKillfocusSound)
	ON_NOTIFY(UDN_DELTAPOS, IDC_LOGLENSPIN, OnDeltaposLoglenspin)
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_FILES, OnFiles)
	ON_COMMAND(ID_FILES_EXPORT, OnFilesExport)
	ON_COMMAND(ID_FILES_IMPORT, OnFilesImport)
	ON_BN_CLICKED(IDC_BROWSESOUND, OnBrowsesound)
	ON_EN_KILLFOCUS(IDC_HOSTFILE, OnKillfocusHostfile)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	ON_COMMAND(ID_FILES_RESET, OnFilesReset)
	ON_LBN_SELCHANGE(IDC_LOG, OnSelchangeLog)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_TRAY_ABOUTKLOG, OnTrayAboutklog)
	ON_COMMAND(ID_TRAY_EXIT, OnTrayExit)
	ON_COMMAND(ID_TRAY_SHOWKLOGWINDOW, OnTrayShowklogwindow)
	ON_WM_WINDOWPOSCHANGING()
	ON_BN_CLICKED(IDC_LOGPATTERN, OnLogpattern)
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_CRIT, OnPriority)
	ON_BN_CLICKED(IDC_DEBUG, OnPriority)
	ON_BN_CLICKED(IDC_EMERG, OnPriority)
	ON_BN_CLICKED(IDC_ERR, OnPriority)
	ON_BN_CLICKED(IDC_INFO, OnPriority)
	ON_BN_CLICKED(IDC_NOTICE, OnPriority)
	ON_BN_CLICKED(IDC_WARNING, OnPriority)
	ON_BN_CLICKED(IDC_TYPE_HOST, OnLogto)
	ON_BN_CLICKED(IDC_TYPE_NONE, OnLogto)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKLogDlg message handlers

BOOL CKLogDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_KLS.m_Daddy=this;
	VERIFY(m_KLS.CreateListen());
	m_SLS.Create(0,SOCK_DGRAM);

	m_LogLenSpinCtl.SetRange(5,50);
	UpdateLogLength(FALSE,FALSE);

	// Adjust Tab control rectangle size and padding
CRect rbrc,tcrc;
	m_DescCtl.GetWindowRect(&rbrc);
	m_Tabs.GetClientRect(&tcrc);
	m_Tabs.ClientToScreen(&tcrc);
	m_Tabs.SetItemSize(CSize(0,rbrc.top-tcrc.top-4));
	m_Tabs.SetPadding(CSize(5,5));

	// Load Image List
	m_Images.Create(16,16,TRUE,2,1);
	m_iNormal=m_Images.Add(AfxGetApp()->LoadIcon(IDI_KLOG));
	m_iTriggered=m_Images.Add(AfxGetApp()->LoadIcon(IDI_KLOG_TRIGGERED));
	m_Tabs.SetImageList(&m_Images);

	// Set Icons
	m_BrowseSoundCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_BROWSE));
	m_PlaySoundCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_PREPLAY));
	m_LogPatternCtl.SetIcon(AfxGetApp()->LoadIcon(IDI_LOGPATTERN));

	// Create ToolTip Control
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);

	// Restore Layout
	OnFilesReset();

	SetWindowPos(NULL,6,6,0,0,SWP_NOZORDER|SWP_NOACTIVATE|SWP_NOSIZE);

	if(m_bShown)
		ShowWindow(SW_SHOW);
	else
		ShowWindow(SW_HIDE);

	// Add Tips captions
	m_tooltip.AddTool(GetDlgItem(IDC_ADD),IDC_ADD);
	m_tooltip.AddTool(&m_RemoveCtl,IDC_REMOVE);
	m_tooltip.AddTool(&m_LogLengthCtl,IDC_LOGLENGTH);
	m_tooltip.AddTool(&m_LogLenSpinCtl,IDC_LOGLENGTH);
	m_tooltip.AddTool(GetDlgItem(IDC_STATIC_LOGLENGTH),IDC_LOGLENGTH);
	m_tooltip.AddTool(GetDlgItem(IDC_FILES),IDC_FILES);
	m_tooltip.AddTool(GetDlgItem(IDC_EXIT),IDC_EXIT);
	m_tooltip.AddTool(&m_LogtoFileCtl,IDC_TYPE_FILE);
	m_tooltip.AddTool(&m_LogtoHostCtl,IDC_TYPE_HOST);
	m_tooltip.AddTool(&m_LogtoNoneCtl,IDC_TYPE_NONE);
	m_tooltip.AddTool(&m_hlCtl,IDC_HOSTS);
	m_tooltip.AddTool(&m_Log,IDC_LOG);
	m_tooltip.AddTool(&m_LogPatternCtl,IDC_LOGPATTERN);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CKLogDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	switch(nID&0xFFF0){
	case IDM_ABOUTBOX:
		{
			OnTrayAboutklog();
		}
		break;
	case SC_CONTEXTHELP:
		AfxGetApp()->WinHelp(0,HELP_FINDER);
		break;
	default:
		CDialog::OnSysCommand(nID, lParam);
		break;
	}
}

void CKLogDlg::OnDestroy()
{
NOTIFYICONDATA nid;
	memset(&nid,0,sizeof(nid));
	nid.cbSize=sizeof(nid);
	nid.hWnd=m_Trayer->m_hWnd;
	nid.uID=IDC_TRAYICON;
	nid.uFlags=0;
	VERIFY(Shell_NotifyIcon(NIM_DELETE,&nid));

	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKLogDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	CPaintDC pDC(this);
	CDC bmpDC;
		bmpDC.CreateCompatibleDC(&pDC);
		bmpDC.SelectObject(&m_bmpBack);
	CRect rc;
		GetClientRect(&rc);
		for(int x=-m_bitmapBack.bmWidth*2/4;x<rc.Width();x+=m_bitmapBack.bmWidth)
			for(int y=-m_bitmapBack.bmHeight*2/4;y<rc.Height();y+=m_bitmapBack.bmHeight)
				pDC.BitBlt(x,y,m_bitmapBack.bmWidth,m_bitmapBack.bmHeight,&bmpDC,0,0,SRCCOPY);
		bmpDC.DeleteDC();
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKLogDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CKLogDlg::OnAdd() 
{
CLogger *l = new CLogger(m_Tabs.GetItemCount()?FALSE:TRUE);
	ASSERT(l);
	m_Logs[l]=l;
TC_ITEM ptc;
	memset(&ptc,0,sizeof(ptc));
	ptc.mask=TCIF_TEXT|TCIF_IMAGE|TCIF_PARAM;
	ptc.pszText=(LPTSTR)(LPCTSTR)l->m_Desc;
	ptc.iImage=m_iNormal;
	ptc.lParam=(LPARAM)l;
int tmp=m_Tabs.InsertItem(m_Tabs.GetItemCount(),&ptc);
	m_Tabs.SetCurSel(tmp);
	SetTab(l);
	m_RemoveCtl.EnableWindow(m_Tabs.GetItemCount()>1);
}

void CKLogDlg::OnSelchangeTabs(NMHDR* pNMHDR, LRESULT* pResult) 
{
int cs = m_Tabs.GetCurSel();
	ASSERT(cs>=0);
TC_ITEM ptci;
	memset(&ptci,0,sizeof(ptci));
	ptci.mask=TCIF_PARAM;
	VERIFY(m_Tabs.GetItem(cs,&ptci));
CLogger *l = (CLogger*)ptci.lParam;
	memset(&ptci,0,sizeof(ptci));
	ptci.mask=TCIF_IMAGE;
	ptci.iImage=m_iNormal;
	VERIFY(m_Tabs.SetItem(cs,&ptci));
	ASSERT(l);
	SetTab(l);
	if(pResult)
		*pResult = 0;
}

UINT	CKLogDlg::m_PriorityCtls[CSyslogSocket::totalPriorities] = {
		IDC_EMERG,IDC_ALERT,IDC_CRIT,IDC_ERR,IDC_WARNING,IDC_NOTICE,IDC_INFO,IDC_DEBUG
};
void CKLogDlg::SetTab(CLogger* l)
{
	ASSERT(l);
	m_Logger=l;
	m_Desc=m_Logger->m_Desc;
	UpdateLogto(FALSE,FALSE);
	UpdatePriface(FALSE,FALSE);
	// HOST LIST
	m_hlCtl.ResetContent();
	m_hlRemoveCtl.EnableWindow(FALSE);
POSITION p = m_Logger->m_Hosts.GetHeadPosition();
	while(p){
	CHostMask *hm = m_Logger->m_Hosts.GetNext(p);
		ASSERT(hm);
	CString hms = hm->String();
	int i = m_hlCtl.AddString(hms);
		ASSERT(i>=0);
		m_hlCtl.SetItemData(i,(DWORD)hm);
	}
	// SOUND
	m_Sound=m_Logger->m_Sound;
	// EVENTS
	m_Log.ResetContent();
	p = m_Logger->m_Log.GetHeadPosition();
	while(p){
	CLogEntry *le = m_Logger->m_Log.GetNext(p);
		ASSERT(le);
		AddLogLine(le);
	}

	UpdateData(FALSE);
}

CLogger::CLogger(BOOL bAll)
{
	m_Desc=bAll?"All events":"New";
	memset(m_LogPattern,bAll,sizeof(m_LogPattern));
	m_LogTo=logToNone;
	m_LogToHost.sin_addr.s_addr = INADDR_NONE;
}

void CKLogDlg::UpdatePriface(BOOL bSave,BOOL update)
{
	ASSERT(m_Logger);
int f = CSyslogSocket::Facility(m_Facility);
	if(bSave){
		if(f==CSyslogSocket::facNone)
			return;
		for(int tmp=0;tmp<CSyslogSocket::totalPriorities;tmp++)
			m_Logger->m_LogPattern[f][tmp]=(IsDlgButtonChecked(m_PriorityCtls[tmp])!=0);
	}else{
		if(f==CSyslogSocket::facNone){
			for(int tmp=0;tmp<CSyslogSocket::totalPriorities;tmp++){
				CheckDlgButton(m_PriorityCtls[tmp],0);
				GetDlgItem(m_PriorityCtls[tmp])->EnableWindow(FALSE);
			}
			m_PriAllCtl.EnableWindow(FALSE);
			m_PriNoneCtl.EnableWindow(FALSE);
			m_PriInvertCtl.EnableWindow(FALSE);
		}else{
			for(int tmp=0;tmp<CSyslogSocket::totalPriorities;tmp++){
				CheckDlgButton(m_PriorityCtls[tmp],m_Logger->m_LogPattern[f][tmp]?1:0);
				GetDlgItem(m_PriorityCtls[tmp])->EnableWindow(TRUE);
			}
			m_PriAllCtl.EnableWindow(TRUE);
			m_PriNoneCtl.EnableWindow(TRUE);
			m_PriInvertCtl.EnableWindow(TRUE);
			if(update)
				UpdateData(FALSE);
		}
	}
}

void CKLogDlg::OnSelchangeFacility() 
{
	ASSERT(m_Logger);
	UpdatePriface(TRUE,FALSE);
	UpdateData(TRUE);
	UpdatePriface(FALSE,TRUE);
}

void CKLogDlg::OnPriority() 
{
	UpdatePriface(TRUE,FALSE);
}

void CKLogDlg::UpdateLogto(BOOL bSave,BOOL update)
{
	if(bSave){
		m_Logger->m_LogTo=m_Logto;
		if(m_Logto!=CLogger::logToNone){
			m_Logger->m_LogToName=m_HFName;
			switch(m_Logto){
			case CLogger::logToFile:
				// ??? Do nothing
				break;
			case CLogger::logToHost:
				m_Logger->LookupHost(this);
				break;
#ifndef	NDEBUG
			default:
				ASSERT(FALSE);
				break;
#endif
			}
		}
	}else{
		m_Logto=m_Logger->m_LogTo;
		m_HFNameCaption.Empty();
		m_HFName=m_Logger->m_LogToName;
	BOOL doLog = TRUE;
	BOOL doBrowse = FALSE;
		switch(m_Logger->m_LogTo){
		case CLogger::logToNone:
			doLog=FALSE;
			m_HFName.Empty();
			break;
		case CLogger::logToFile:
			m_HFNameCaption.LoadString(IDS_LOGTO_FILE);
			doBrowse=TRUE;
			break;
		case CLogger::logToHost:
			m_HFNameCaption.LoadString(IDS_LOGTO_HOST);
			break;
		default:
			ASSERT(FALSE);
			break;
		}
		m_HFNameCtl.EnableWindow(doLog);
		m_HFNameCaptionCtl.EnableWindow(doLog);
		m_BrowseCtl.EnableWindow(doBrowse);
		if(update)
			UpdateData(FALSE);
	}
}

void CKLogDlg::OnLogto() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
	m_HFName=m_Logger->m_LogToName;
	UpdateLogto(TRUE,FALSE);
	UpdateLogto(FALSE,TRUE);
}

void CKLogDlg::OnPriAll() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
	UpdatePriface(TRUE,FALSE);
int f = CSyslogSocket::Facility(m_Facility);
	for(int tmp=0;tmp<CSyslogSocket::totalPriorities;tmp++)
		m_Logger->m_LogPattern[f][tmp]=TRUE;
	UpdatePriface(FALSE,TRUE);
}

void CKLogDlg::OnPriNone() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
	UpdatePriface(TRUE,FALSE);
int f = CSyslogSocket::Facility(m_Facility);
	for(int tmp=0;tmp<CSyslogSocket::totalPriorities;tmp++)
		m_Logger->m_LogPattern[f][tmp]=FALSE;
	UpdatePriface(FALSE,TRUE);
}

void CKLogDlg::OnPriInvert() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
	UpdatePriface(TRUE,FALSE);
int f = CSyslogSocket::Facility(m_Facility);
	for(int tmp=0;tmp<CSyslogSocket::totalPriorities;tmp++)
		m_Logger->m_LogPattern[f][tmp]=!m_Logger->m_LogPattern[f][tmp];
	UpdatePriface(FALSE,TRUE);
}

void CKLogDlg::OnChangeDesc() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
	m_Logger->m_Desc=m_Desc;
int	cs = m_Tabs.GetCurSel();
	ASSERT(cs>=0);
TC_ITEM ptci;
	memset(&ptci,0,sizeof(ptci));
	ptci.mask=TCIF_TEXT;
	ptci.pszText=(LPTSTR)(LPCTSTR)m_Logger->m_Desc;
	VERIFY(m_Tabs.SetItem(cs,&ptci));
}

CString CHostMask::String()
{
CString rv;
	rv = inet_ntoa(*(in_addr*)&m_Host);
	rv+="  /  ";
	rv+= inet_ntoa(*(in_addr*)&m_Mask);
	return rv;
}

void CKLogDlg::OnHlAdd() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
DWORD h = (DWORD)inet_addr(m_hlIP);
DWORD m = (DWORD)inet_addr(m_hlMask);
	if(h==INADDR_NONE){
		TRACE0("Bad host address\n");
		m_hlIPCtl.SetFocus();
		return;
	}
	if(m==INADDR_NONE && m_hlMask!="255.255.255.255"){ // 255.255.255.255 stands for INADDR_NONE
		TRACE0("Bad host mask\n");
		m_hlMaskCtl.SetFocus();
		return;
	}
	if(!(m && h)){
		TRACE0("Both zeros\n");
		m_hlIPCtl.SetFocus();
		return;
	}
CHostMask *hm = new CHostMask(h,m);
	ASSERT(hm);
	m_Logger->m_Hosts.AddTail(hm);
CString hms = hm->String();
int i = m_hlCtl.AddString(hms);
	ASSERT(i>=0);
	m_hlCtl.SetItemData(i,(DWORD)hm);
}

void CKLogDlg::OnSelchangeHosts() 
{
int i = m_hlCtl.GetCurSel();
	if(i<0){
		m_hlRemoveCtl.EnableWindow(FALSE);
		return;
	}
CHostMask *hm = (CHostMask*)m_hlCtl.GetItemData(i);
	ASSERT(hm);
	m_hlIP=inet_ntoa(*(in_addr*)&hm->m_Host);
	m_hlMask=inet_ntoa(*(in_addr*)&hm->m_Mask);
	UpdateData(FALSE);
	m_hlRemoveCtl.EnableWindow(TRUE);
}

void CKLogDlg::OnHlRemove() 
{
int i = m_hlCtl.GetCurSel();
	if(i<0){
		m_hlRemoveCtl.EnableWindow(FALSE);
		return;
	}
CHostMask *hm = (CHostMask*)m_hlCtl.GetItemData(i);
	m_hlCtl.DeleteString(i);
	ASSERT(hm);
	ASSERT(m_Logger);
POSITION p = m_Logger->m_Hosts.Find(hm);
	ASSERT(p);
	m_Logger->m_Hosts.RemoveAt(p);
	delete hm;
	m_hlRemoveCtl.EnableWindow(m_hlCtl.GetCurSel()>=0);
}

void CKLogDlg::OnRemove() 
{
	ASSERT(m_Tabs.GetItemCount()>1);
int t = m_Tabs.GetCurSel();
	ASSERT(t>=0);
	ASSERT(m_Logger);
TC_ITEM tci;
	memset(&tci,0,sizeof(tci));
	tci.mask=TCIF_PARAM;
	VERIFY(m_Tabs.GetItem(t,&tci));
	ASSERT(tci.lParam==(LPARAM)m_Logger);
	VERIFY(m_Tabs.DeleteItem(t));
	VERIFY(m_Logs.RemoveKey(m_Logger));
	delete m_Logger;
	m_Logger=NULL;
	m_Tabs.SetCurSel(t);
	t=m_Tabs.GetCurSel();
	if(t<0)
		VERIFY(m_Tabs.SetCurSel(t=0));
	memset(&tci,0,sizeof(tci));
	tci.mask=TCIF_PARAM;
	VERIFY(m_Tabs.GetItem(t,&tci));
CLogger *l = (CLogger*)tci.lParam;
	ASSERT(l);
	SetTab(l);
	m_RemoveCtl.EnableWindow(m_Tabs.GetItemCount()>1);
}

void CLogger::PlayWave()
{
	if(m_Sound.IsEmpty())
		return;
CString tmp;
	tmp.LoadString(IDS_SOUND_MEOW);
	if(!tmp.CompareNoCase(m_Sound)){
		::PlaySound((LPCTSTR)IDW_SOUND_MEOW,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_RESOURCE);
		return;
	}
	tmp.LoadString(IDS_SOUND_GLASS);
	if(!tmp.CompareNoCase(m_Sound)){
		::PlaySound((LPCTSTR)IDW_SOUND_GLASS,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_RESOURCE);
		return;
	}
	tmp.LoadString(IDS_SOUND_FEAR);
	if(!tmp.CompareNoCase(m_Sound)){
		::PlaySound((LPCTSTR)IDW_SOUND_FEAR,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_RESOURCE);
		return;
	}
	tmp.LoadString(IDS_SOUND_KICK);
	if(!tmp.CompareNoCase(m_Sound)){
		::PlaySound((LPCTSTR)IDW_SOUND_KICK,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_RESOURCE);
		return;
	}
	::PlaySound(m_Sound,AfxGetApp()->m_hInstance,SND_ASYNC|SND_NODEFAULT|SND_NOSTOP|SND_NOWAIT|SND_FILENAME);
}

void CKLogDlg::OnPlaysound() 
{
	ASSERT(m_Logger);
	m_Logger->PlayWave();
}

void CKLogDlg::OnEditchangeSound() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
	m_Logger->m_Sound=m_Sound;
}

void CKLogDlg::OnKillfocusSound() 
{
	ASSERT(m_Logger);
	UpdateData(TRUE);
	m_Logger->m_Sound=m_Sound;
}

void CKLogDlg::UpdateLogLength(BOOL bSave,BOOL update)
{
	if(bSave){
	int sbp = m_LogLenSpinCtl.GetPos();
		if(sbp&(0xFFFFl<<16)){
			sbp = 15;
			m_LogLenSpinCtl.SetPos(sbp);
		}
		m_LogItems=sbp;
	}else{
		m_LogLenSpinCtl.SetPos(m_LogItems);
	}
}

void CKLogDlg::OnDeltaposLoglenspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	UpdateLogLength(TRUE,FALSE);
	*pResult = 0;
}

void CKLogDlg::OnExit() 
{
	SaveSettings();
	TotalCleanUp();
	m_bExiting=TRUE;
	EndDialog(IDOK);
}

void CKLogDlg::TotalCleanUp()
{
POSITION p = m_Logs.GetStartPosition();
	while(p){
	CLogger *l, *ll;
		m_Logs.GetNextAssoc(p,l,ll);
		ASSERT(l);
		ASSERT(l==ll);
		delete l;
	}
	m_Logs.RemoveAll();
	m_Tabs.DeleteAllItems();
	RedrawWindow();
}

CLogger::~CLogger()
{
POSITION p = m_Hosts.GetHeadPosition();
	while(p){
	CHostMask *hm = m_Hosts.GetNext(p);
		ASSERT(hm);
		delete hm;
	}
	m_Hosts.RemoveAll();
	p = m_Log.GetHeadPosition();
	while(p){
	CLogEntry *le = m_Log.GetNext(p);
		ASSERT(le);
		delete le;
	}
	m_Log.RemoveAll();
}

void CKLogDlg::OnFiles() 
{
CRect rc;
	m_FilesCtl.GetWindowRect(&rc);
CPoint pt = rc.TopLeft();
CMenu menu;
	VERIFY(menu.LoadMenu(IDD));
CMenu *filesMenu = menu.GetSubMenu(0);
	ASSERT(filesMenu);
	filesMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON,pt.x,pt.y,this);
}

void CKLogDlg::OnFilesExport() 
{
	TRACE0("Export\n");
CString filter;
	filter.LoadString(IDS_KLOGFILTER);
CString title, ext;
	title.LoadString(IDS_KLOG_EXPORT);
	ext.LoadString(IDS_KLOG_EXT);
CFileDialog cfd(FALSE,ext,NULL,OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,filter,this);
	cfd.m_ofn.lpstrTitle=title;
	if(cfd.DoModal()==IDOK){
	CFile klo;
		if(klo.Open(cfd.GetPathName(),CFile::modeCreate|CFile::modeWrite)){
			TRY{
			CArchive ar(&klo,CArchive::store);
				Serialize(ar);
				ar.Close();
			}CATCH(CException, e){
			CString tmp;
				tmp.LoadString(IDS_MSG_FAILEDTOEXPORT);
				MessageBox(tmp,NULL,MB_ICONHAND|MB_OK);
			}END_CATCH
		}else{
		CString tmp;
			tmp.LoadString(IDS_MSG_FAILEDTOEXPORT);
			MessageBox(tmp,NULL,MB_ICONHAND|MB_OK);
		}
	}
}

void CKLogDlg::OnFilesImport() 
{
	TRACE0("Import\n");
CString filter;
	filter.LoadString(IDS_KLOGFILTER);
CString title;
	title.LoadString(IDS_KLOG_IMPORT);
CFileDialog cfd(TRUE,NULL,NULL,OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,filter,this);
	cfd.m_ofn.lpstrTitle=title;
	if(cfd.DoModal()==IDOK){
	CFile klo;
		if(klo.Open(cfd.GetPathName(),CFile::modeRead)){
			TRY{
			CArchive ar(&klo,CArchive::load);
				Serialize(ar);
				ar.Close();
			}CATCH(CException, e){
			CString tmp;
				tmp.LoadString(IDS_MSG_FAILEDTOIMPORT);
				MessageBox(tmp,NULL,MB_ICONHAND|MB_OK);
			}END_CATCH
		}else{
		CString tmp;
			tmp.LoadString(IDS_MSG_FAILEDTOIMPORT);
			MessageBox(tmp,NULL,MB_ICONHAND|MB_OK);
		}
	}
}

void CKLogDlg::OnBrowsesound() 
{
CString filter;
	filter.LoadString(IDS_WAVFILTER);
CString title;
	title.LoadString(IDS_SOUND_SELECT);
CFileDialog cfd(TRUE,NULL,NULL,OFN_EXPLORER|OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,filter,this);
	cfd.m_ofn.lpstrTitle=title;
	if(cfd.DoModal()==IDOK){
		m_Sound=cfd.GetPathName();
		ASSERT(m_Logger);
		UpdateData(FALSE);
		m_Logger->m_Sound=m_Sound;
	}	
}

void CKLogDlg::OnKillfocusHostfile() 
{
	UpdateData(TRUE);
	if(m_HFName.Compare(m_Logger->m_LogToName))
		UpdateLogto(TRUE,FALSE);
}

void CKLogDlg::OnOK() 
{
	UpdateData(TRUE);
	UpdateLogto(TRUE,FALSE);
}

void CKLogDlg::OnBrowse() 
{
CString filter;
	filter.LoadString(IDS_LOGFILTER);
CString title, ext;
	title.LoadString(IDS_LOG_SELECT);
	ext.LoadString(IDS_LOG_EXT);
CFileDialog cfd(FALSE,ext,NULL,OFN_EXPLORER|OFN_PATHMUSTEXIST|OFN_HIDEREADONLY,filter,this);
	cfd.m_ofn.lpstrTitle=title;
	if(cfd.DoModal()==IDOK){
		m_HFName=cfd.GetPathName();
		ASSERT(m_Logger);
		UpdateData(FALSE);
		m_Logger->m_LogToName=m_HFName;
	}	
}

void CKLogDlg::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	ar.MapObject(this);
	ar.SerializeClass(RUNTIME_CLASS(CKLogDlg));

	if(ar.IsStoring()){
		// Store
		TRACE0("Store Klog\n");
	int	nCount = m_Tabs.GetItemCount();
		ar << nCount;
		for(int tmp=0;tmp<nCount;tmp++){
		TC_ITEM ptci;
			memset(&ptci,0,sizeof(ptci));
			ptci.mask=TCIF_PARAM;
			VERIFY(m_Tabs.GetItem(tmp,&ptci));
		CLogger *l = (CLogger*)ptci.lParam;
			ASSERT(l);
			l->Serialize(ar);
		}
	}else{
		// Retrieve
	UINT schema = ar.GetObjectSchema();
#ifndef NDEBUG
		{
			CString tmp;
			tmp.Format("Doc-OSchema: %u\n",schema);
			TRACE0(tmp);
		}
#endif
		// Do the cleanup
		TotalCleanUp();
	int nCount;
		ar >> nCount;
		ASSERT(nCount);
		for(int tmp=0;tmp<nCount;tmp++){
		CLogger *l = new CLogger();
			l->Serialize(ar);
			m_Logs[l]=l;
		TC_ITEM ptc;
			memset(&ptc,0,sizeof(ptc));
			ptc.mask=TCIF_TEXT|TCIF_IMAGE|TCIF_PARAM;
			ptc.pszText=(LPTSTR)(LPCTSTR)l->m_Desc;
			ptc.iImage=m_iNormal;
			ptc.lParam=(LPARAM)l;
		int tmp=m_Tabs.InsertItem(m_Tabs.GetItemCount(),&ptc);
		if(l->m_LogTo==CLogger::logToHost)
				l->LookupHost(this);
		}
		m_Tabs.SetCurSel(0);
		OnSelchangeTabs(NULL,NULL);
		m_RemoveCtl.EnableWindow(nCount>1);
	}
}

void CLogger::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	ar.MapObject(this);
	ar.SerializeClass(RUNTIME_CLASS(CLogger));

	if(ar.IsStoring()){
		// Store
		TRACE0("Store Klogger\n");
		ar << m_Desc;
		ar.Write(&m_LogPattern,sizeof(m_LogPattern));
		ar << m_LogTo;
		ar << m_LogToName;
		ar << m_Sound;
		m_Hosts.Serialize(ar);
	}else{
		// Retrieve
UINT schema = ar.GetObjectSchema();
#ifndef NDEBUG
		{
			CString tmp;
			tmp.Format("Doc-OSchema: %u\n",schema);
			TRACE0(tmp);
		}
#endif
		ar >> m_Desc;
		ar.Read(&m_LogPattern,sizeof(m_LogPattern));
		ar >> m_LogTo;
		ar >> m_LogToName;
		ar >> m_Sound;
		m_Hosts.Serialize(ar);
	}
}

void CHostMask::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	if(ar.IsStoring()){
		// Store
		ar << m_Host;
		ar << m_Mask;
	}else{
		// Retrieve
		ar >> m_Host;
		ar >> m_Mask;
	}
}

void CKLogDlg::OnFilesReset() 
{
	TotalCleanUp();
BYTE *pData = NULL;
UINT dataLength = 0;
	if(AfxGetApp()->GetProfileBinary("Layout","Destinations",&pData,&dataLength)){
	CMemFile mf(pData,dataLength);
	CArchive ar(&mf,CArchive::load);
		Serialize(ar);
		ar.Close();
		delete mf.Detach();
	}else
		OnAdd();
}

void CAboutDlg::OnKlevernet() 
{
CString url;
	url.LoadString(IDS_KLEVERNET_URL);
	ShellExecute(::GetDesktopWindow(),"open",url,NULL,NULL,SW_SHOWMAXIMIZED);
}

void CKLogSocket::Log(UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin)
{
CString str = Escape(line);
	m_Daddy->LogMessage(pri,fac,str,sin);
}

void CKLogDlg::LogMessage(UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin)
{
	// Setting up defaults:
UINT ap = pri, af = fac;
	if(ap>=CSyslogSocket::totalPriorities)
		ap=CSyslogSocket::priInfo;
	if(af>=CSyslogSocket::totalFacilities)
		af=CSyslogSocket::facUser;
POSITION p = m_Logs.GetStartPosition();
	while(p){
	CLogger *l,*ll;
		m_Logs.GetNextAssoc(p,l,ll);
		ASSERT(l);
		ASSERT(l==ll);
		if(l->m_LogPattern[af][ap]  && l->IsHostFine(sin->sin_addr.s_addr))
			l->LogLine(this,ap,af,line,sin);
	}
}

CLogEntry::CLogEntry()
{
	m_Time==CTime::GetCurrentTime();
	m_Priority=CSyslogSocket::priNone;
	m_Facility=CSyslogSocket::facNone;
}

BOOL CLogger::IsHostFine(DWORD saddr)
{
	if(m_Hosts.IsEmpty())
		return TRUE;
POSITION p = m_Hosts.GetHeadPosition();
	while(p){
	CHostMask *hm = m_Hosts.GetNext(p);
		ASSERT(hm);
		if(hm->IsThis(saddr))
			return TRUE;
	}
	return FALSE;
}

void CLogger::LogLine(CKLogDlg *dad,UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin)
{
CLogEntry *le = NULL;
	while(m_Log.GetCount()>=dad->m_LogItems){
		le = m_Log.GetHead();
		ASSERT(le);
		if(dad->m_Logger==this){
			ASSERT((CLogEntry*)dad->m_Log.GetItemData(0)==le);
			dad->m_Log.DeleteString(0);
		}
		m_Log.RemoveHead();
		if(m_Log.GetCount()>dad->m_LogItems){
			delete le;
			le=NULL;
		}
	}
	if(!le)
		le = new CLogEntry();
	ASSERT(le);
	le->m_Time=CTime::GetCurrentTime();
	le->m_Priority=pri;
	le->m_Facility=fac;
	le->m_Data=line;
	le->m_Source=inet_ntoa(sin->sin_addr);
	m_Log.AddTail(le);
	if(dad->m_Logger==this){
		dad->AddLogLine(le);
	}else{
	int c = dad->m_Tabs.GetItemCount();
		ASSERT(c>0);
		for(int i=0;i<c;i++){
		TC_ITEM ptci;
			memset(&ptci,0,sizeof(ptci));
			ptci.mask=TCIF_PARAM;
			VERIFY(dad->m_Tabs.GetItem(i,&ptci));
		CLogger *l = (CLogger*)ptci.lParam;
			if(l==this){
				memset(&ptci,0,sizeof(ptci));
				ptci.mask=TCIF_IMAGE;
				ptci.iImage=dad->m_iTriggered;
				VERIFY(dad->m_Tabs.SetItem(i,&ptci));
			}
		}
	}
	PlayWave();
	switch(m_LogTo){
	case logToFile:
		if(!m_LogToName.IsEmpty()){
			TRY{
			CFile file(m_LogToName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite|CFile::shareDenyWrite|CFile::typeBinary);
				file.SeekToEnd();
			CString tmp = le->m_Time.Format(IDS_LOGFILETIMEFORMAT);
				file.Write((LPCTSTR)tmp,tmp.GetLength());
				tmp.Format(IDS_LOGFILESOURCEFORMAT,le->m_Source);
				file.Write((LPCTSTR)tmp,tmp.GetLength());
				tmp.Format(IDS_LOGFILEPRIFACEFORMAT,CSyslogSocket::m_Facilities[fac],CSyslogSocket::m_Priorities[pri]);
				file.Write((LPCTSTR)tmp,tmp.GetLength());
				file.Write(line,strlen(line));
				file.Write("\r\n",2);
				file.Close();
			}CATCH(CFileException, e){
#ifndef	NDEBUG
				afxDump << "Logging error: " << e->m_cause << "\n";
#endif
			}END_CATCH
		}
		break;
	case logToHost:
		if(m_LogToHost.sin_addr.s_addr!=INADDR_NONE){
		CString tmp;
			tmp.Format(IDS_LOGHOSTSOURCEFORMAT,le->m_Source);
			tmp+=line;
			dad->m_SLS.LogTo(m_LogToHost.sin_addr.s_addr,pri,fac,tmp);
		}
		break;
	}
}

CLogEntry& CLogEntry::operator=(CLogEntry& src)
{
	m_Data=src.m_Data;
	m_Facility=src.m_Facility;
	m_Priority=src.m_Priority;
	m_Source=src.m_Source;
	m_Time=src.m_Time;
	return *this;
}

CLogEntry::CLogEntry(CLogEntry& src)
{
	(*this)=src;
}

void CKLogDlg::AddLogLine(CLogEntry *le)
{
	ASSERT(le);
int i = m_Log.AddString(le->m_Data);
	m_Log.SetItemData(i,(DWORD)le);
	m_Log.SetCurSel(i);
}

BOOL CKLogDlg::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);

		return CDialog::PreTranslateMessage(pMsg);
	}
}

void CKLogDlg::OnSelchangeLog() 
{
int i = m_Log.GetCurSel();
	if(i==LB_ERR)
		return;
CLogEntry *le = (CLogEntry*)m_Log.GetItemData(i);
	ASSERT(le);
CString tmp;
	tmp.Format(IDS_TIP_LOG,
		(LPCTSTR)le->m_Time.Format(IDS_LOGTIMEFORMAT),
		(LPCTSTR)le->m_Source,
		CSyslogSocket::m_Facilities[le->m_Facility],
		CSyslogSocket::m_Priorities[le->m_Priority]
	);
	m_tooltip.UpdateTipText(tmp,&m_Log);
}

int CKLogDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if(!m_Trayer->Create(NULL,"PumpKIN TrayIcon",WS_CHILD,CRect(0,0,0,0),this,0)){
		TRACE0("Failed to create trayer\n");
		return -1;
	}

NOTIFYICONDATA nid;
	memset(&nid,0,sizeof(nid));
	nid.cbSize=sizeof(nid);
	nid.hWnd=m_Trayer->m_hWnd;
	nid.uID=IDC_TRAYICON;
	nid.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
	nid.uCallbackMessage=WM_TRAYICON;
	nid.hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	// *** Load from resource
	strcpy(nid.szTip,"KLog");
	VERIFY(Shell_NotifyIcon(NIM_ADD,&nid));

	return 0;
}

void CKLogDlg::OnClose() 
{
	OnTrayShowklogwindow();
}

void CKLogDlg::OnTrayAboutklog() 
{
CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CKLogDlg::OnTrayExit() 
{
	OnExit();
}

void CKLogDlg::OnTrayShowklogwindow() 
{
	if(IsWindowVisible()){
		m_bShown=FALSE;
		ShowWindow(SW_HIDE);
	}else{
		m_bShown=TRUE;
		ShowWindow(SW_SHOW);
		SetForegroundWindow();
		SetFocus();
	}
}

void CKLogDlg::OnWindowPosChanging(WINDOWPOS FAR* lpwndpos) 
{
	CDialog::OnWindowPosChanging(lpwndpos);
	
	if(!m_bExiting){
		if(m_bShown){
			lpwndpos->flags&=~SWP_HIDEWINDOW;
			lpwndpos->flags|=SWP_SHOWWINDOW;
		}else{
			lpwndpos->flags&=~SWP_SHOWWINDOW;
			lpwndpos->flags|=SWP_HIDEWINDOW;
			if(::GetForegroundWindow()==m_hWnd && (m_Trayer &&  !m_Trayer->m_inMenu))
				GetDesktopWindow()->SetForegroundWindow();
		}
	}
}

void CKLogDlg::LoadSettings()
{
CWinApp *app = AfxGetApp();
	ASSERT(app);
	m_LogItems=app->GetProfileInt("UISettings","LogLength",m_LogItems);
	m_bShown=app->GetProfileInt("UISettings","Visible",m_bShown);
	m_bWarnBlocking=app->GetProfileInt("Resolve","WarnBlocking",m_bWarnBlocking);
	m_bDontWarn=app->GetProfileInt("Resolve","DontWarn",m_bDontWarn);
}

void CKLogDlg::SaveSettings()
{
CWinApp *app = AfxGetApp();
	ASSERT(app);
	app->WriteProfileInt("UISettings","LogLength",m_LogItems);
	app->WriteProfileInt("UISettings","Visible",m_bShown);
	app->WriteProfileInt("Resolve","WarnBlocking",m_bWarnBlocking);
	app->WriteProfileInt("Resolve","DontWarn",m_bDontWarn);
CMemFile mf(4096);
CArchive ar(&mf,CArchive::store);
	Serialize(ar);
	ar.Close();
DWORD dataLength = mf.GetLength();
	if(dataLength&0xFFFF0000l){
	CString tmp;
		tmp.LoadString(IDS_MSG_FAILEDTOSTORE);
		MessageBox(tmp,NULL,MB_ICONHAND|MB_OK);
	}else{
	UINT dl = (UINT)dataLength;
	BYTE *data = mf.Detach();
		app->WriteProfileBinary("Layout","Destinations",data,dl);
		delete data;
	}
}

CKLogDlg::~CKLogDlg()
{
	delete m_Trayer;
}

void CKLogDlg::OnLogpattern() 
{
CLogPattern lp(IDS_LOGPATTERN_TITLE,this);
	memmove(lp.m_Pattern,m_Logger->m_LogPattern,sizeof(lp.m_Pattern));
	if(lp.DoModal()==IDOK){
		memmove(m_Logger->m_LogPattern,lp.m_Pattern,sizeof(m_Logger->m_LogPattern));
		UpdatePriface(FALSE,TRUE);
	}
}

void CLogger::LookupHost(CKLogDlg *daddy)
{
		m_LogToHost.sin_addr.s_addr=inet_addr((LPCTSTR)m_LogToName);
		if(m_LogToHost.sin_addr.s_addr==INADDR_NONE){
			if(daddy->m_bWarnBlocking){
			CWarnBlocking wb(::IsWindow(daddy->m_hWnd)?daddy:NULL);
				wb.m_bDontWarn = daddy->m_bDontWarn;
				if(wb.DoModal()!=IDOK)
					return;
				daddy->m_bDontWarn=wb.m_bDontWarn;
				daddy->m_bWarnBlocking=!wb.m_bDontWarn;
			}
			daddy->BeginWaitCursor();
		hostent *he = gethostbyname(m_LogToName);
			daddy->EndWaitCursor();
			if(he){
				m_LogToHost.sin_addr.s_addr = *(DWORD*)he->h_addr;
			}else{
				m_LogToHost.sin_addr.s_addr = INADDR_NONE;
				if(daddy->m_bWarnBlocking){
				CString sux;
					sux.Format(IDS_MSG_LOOKUPFAILED,(LPCTSTR)m_LogToName);
					daddy->MessageBox(sux,NULL,MB_ICONSTOP|MB_OK);
				}else
					MessageBeep(MB_ICONHAND);
			}
		}
}

void CKLogDlg::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	CDialog::OnGetMinMaxInfo(lpMMI);
	WINDOWPLACEMENT wp;
	if(IsWindow(m_CancelCtl.m_hWnd) && m_CancelCtl.GetWindowPlacement(&wp)) {
		CRect wr; GetWindowRect(wr);
		CRect cr; GetClientRect(cr);
		CSize ncs = (wr-cr).Size();
		CRect ctlr = wp.rcNormalPosition;
		CSize corner = ctlr.BottomRight()+ncs;
		lpMMI->ptMaxTrackSize.x = lpMMI->ptMinTrackSize.x = corner.cx;
		lpMMI->ptMinTrackSize.y = corner.cy;
	}
}

void CKLogDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(!IsWindow(m_Log.m_hWnd))
		return;
	WINDOWPLACEMENT lp; m_Log.GetWindowPlacement(&lp);
	CRect lr = lp.rcNormalPosition;
	lr.bottom = cy-2;
	CSize ls = lr.Size();
	m_Log.SetWindowPos(0,0,0,ls.cx,ls.cy,SWP_NOACTIVATE|SWP_NOMOVE|SWP_NOOWNERZORDER|SWP_NOZORDER);
}
