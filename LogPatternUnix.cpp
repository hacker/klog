// LogPatternUnix.cpp : implementation file
//

#include "stdafx.h"
#include "KLog.h"
#include "LogPatternUnix.h"

#include "SyslogSocket.h"
#include "LogPattern.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogPatternUnix property page

#define	PFROM CSyslogSocket::facKernel
#define	PTO		CSyslogSocket::facAuthPriv

IMPLEMENT_DYNCREATE(CLogPatternUnix, CPropertyPage)

CLogPatternUnix::CLogPatternUnix(CLogPattern* daddy) : CPropertyPage(CLogPatternUnix::IDD), m_Daddy(daddy)
{
	//{{AFX_DATA_INIT(CLogPatternUnix)
	//}}AFX_DATA_INIT
}

CLogPatternUnix::~CLogPatternUnix()
{
}

void CLogPatternUnix::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogPatternUnix)
	//}}AFX_DATA_MAP
	m_Daddy->ExchangeData(pDX,PFROM,PTO);
}


BEGIN_MESSAGE_MAP(CLogPatternUnix, CPropertyPage)
	//{{AFX_MSG_MAP(CLogPatternUnix)
	ON_BN_CLICKED(IDC_ALERT_ON, OnAlertOn)
	ON_BN_CLICKED(IDC_AUTH_ON, OnAuthOn)
	ON_BN_CLICKED(IDC_ALERT_XOR, OnAlertXor)
	ON_BN_CLICKED(IDC_AUTH_XOR, OnAuthXor)
	ON_BN_CLICKED(IDC_CRIT_ON, OnCritOn)
	ON_BN_CLICKED(IDC_CRIT_XOR, OnCritXor)
	ON_BN_CLICKED(IDC_CRON_ON, OnCronOn)
	ON_BN_CLICKED(IDC_CRON_XOR, OnCronXor)
	ON_BN_CLICKED(IDC_DAEMON_ON, OnDaemonOn)
	ON_BN_CLICKED(IDC_DAEMON_XOR, OnDaemonXor)
	ON_BN_CLICKED(IDC_DEBUG_ON, OnDebugOn)
	ON_BN_CLICKED(IDC_DEBUG_XOR, OnDebugXor)
	ON_BN_CLICKED(IDC_EMERG_ON, OnEmergOn)
	ON_BN_CLICKED(IDC_EMERG_XOR, OnEmergXor)
	ON_BN_CLICKED(IDC_ERR_ON, OnErrOn)
	ON_BN_CLICKED(IDC_ERR_XOR, OnErrXor)
	ON_BN_CLICKED(IDC_INFO_ON, OnInfoOn)
	ON_BN_CLICKED(IDC_INFO_XOR, OnInfoXor)
	ON_BN_CLICKED(IDC_KERNEL_ON, OnKernelOn)
	ON_BN_CLICKED(IDC_KERNEL_XOR, OnKernelXor)
	ON_BN_CLICKED(IDC_LPR_ON, OnLprOn)
	ON_BN_CLICKED(IDC_LPR_XOR, OnLprXor)
	ON_BN_CLICKED(IDC_MAIL_ON, OnMailOn)
	ON_BN_CLICKED(IDC_MAIL_XOR, OnMailXor)
	ON_BN_CLICKED(IDC_NEWS_ON, OnNewsOn)
	ON_BN_CLICKED(IDC_NEWS_XOR, OnNewsXor)
	ON_BN_CLICKED(IDC_NOTICE_ON, OnNoticeOn)
	ON_BN_CLICKED(IDC_NOTICE_XOR, OnNoticeXor)
	ON_BN_CLICKED(IDC_SYSLOG_ON, OnSyslogOn)
	ON_BN_CLICKED(IDC_SYSLOG_XOR, OnSyslogXor)
	ON_BN_CLICKED(IDC_USER_ON, OnUserOn)
	ON_BN_CLICKED(IDC_USER_XOR, OnUserXor)
	ON_BN_CLICKED(IDC_UUCP_ON, OnUucpOn)
	ON_BN_CLICKED(IDC_UUCP_XOR, OnUucpXor)
	ON_BN_CLICKED(IDC_WARN_ON, OnWarnOn)
	ON_BN_CLICKED(IDC_WARN_XOR, OnWarnXor)
	ON_BN_CLICKED(IDC_AUTHPRIV_ON, OnAuthprivOn)
	ON_BN_CLICKED(IDC_AUTHPRIV_XOR, OnAuthprivXor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogPatternUnix message handlers

void CLogPatternUnix::OnAlertOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priAlert,PFROM,PTO);
}
void CLogPatternUnix::OnAlertXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priAlert,PFROM,PTO);
}

void CLogPatternUnix::OnAuthOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facAuth);
}
void CLogPatternUnix::OnAuthXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facAuth);
}

void CLogPatternUnix::OnCritOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priCritical,PFROM,PTO);
}
void CLogPatternUnix::OnCritXor() 
{
m_Daddy->PriorityXor(this,CSyslogSocket::priCritical,PFROM,PTO);
}

void CLogPatternUnix::OnCronOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facCron);
}
void CLogPatternUnix::OnCronXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facCron);
}

void CLogPatternUnix::OnDaemonOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facDaemon);
}
void CLogPatternUnix::OnDaemonXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facDaemon);
}

void CLogPatternUnix::OnDebugOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priDebug,PFROM,PTO);
}
void CLogPatternUnix::OnDebugXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priDebug,PFROM,PTO);
}

void CLogPatternUnix::OnEmergOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priEmergency,PFROM,PTO);
}
void CLogPatternUnix::OnEmergXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priEmergency,PFROM,PTO);
}

void CLogPatternUnix::OnErrOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priError,PFROM,PTO);
}
void CLogPatternUnix::OnErrXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priError,PFROM,PTO);
}

void CLogPatternUnix::OnInfoOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priInfo,PFROM,PTO);
}
void CLogPatternUnix::OnInfoXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priInfo,PFROM,PTO);
}

void CLogPatternUnix::OnKernelOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facKernel);
}
void CLogPatternUnix::OnKernelXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facKernel);
}

void CLogPatternUnix::OnLprOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLPR);
}
void CLogPatternUnix::OnLprXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLPR);
}

void CLogPatternUnix::OnMailOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facMail);
}
void CLogPatternUnix::OnMailXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facMail);
}

void CLogPatternUnix::OnNewsOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facNews);
}
void CLogPatternUnix::OnNewsXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facNews);
}

void CLogPatternUnix::OnNoticeOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priNotice,PFROM,PTO);
}
void CLogPatternUnix::OnNoticeXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priNotice,PFROM,PTO);
}

void CLogPatternUnix::OnSyslogOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facSyslog);
}
void CLogPatternUnix::OnSyslogXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facSyslog);
}

void CLogPatternUnix::OnUserOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facUser);
}
void CLogPatternUnix::OnUserXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facUser);
}

void CLogPatternUnix::OnUucpOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facUUCP);
}
void CLogPatternUnix::OnUucpXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facUUCP);
}

void CLogPatternUnix::OnWarnOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priWarning,PFROM,PTO);
}
void CLogPatternUnix::OnWarnXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priWarning,PFROM,PTO);
}

void CLogPatternUnix::OnAuthprivOn() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facAuthPriv);
}
void CLogPatternUnix::OnAuthprivXor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facAuthPriv);
}

BOOL CLogPatternUnix::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);
	m_tooltip.AddTool(GetDlgItem(IDC_KERNEL_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_USER_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_MAIL_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_DAEMON_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_AUTH_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_SYSLOG_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_LPR_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_NEWS_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_UUCP_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_CRON_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_AUTHPRIV_ON),IDS_TIP_FACILITY_ON);

	m_tooltip.AddTool(GetDlgItem(IDC_KERNEL_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_USER_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_MAIL_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_DAEMON_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_AUTH_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_SYSLOG_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_LPR_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_NEWS_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_UUCP_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_CRON_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_AUTHPRIV_XOR),IDS_TIP_FACILITY_XOR);

	m_tooltip.AddTool(GetDlgItem(IDC_EMERG_ON),IDS_TIP_PRIORITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_ALERT_ON),IDS_TIP_PRIORITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_CRIT_ON),IDS_TIP_PRIORITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_ERR_ON),IDS_TIP_PRIORITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_WARN_ON),IDS_TIP_PRIORITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_NOTICE_ON),IDS_TIP_PRIORITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_INFO_ON),IDS_TIP_PRIORITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_DEBUG_ON),IDS_TIP_PRIORITY_ON);

	m_tooltip.AddTool(GetDlgItem(IDC_EMERG_XOR),IDS_TIP_PRIORITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_ALERT_XOR),IDS_TIP_PRIORITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_CRIT_XOR),IDS_TIP_PRIORITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_ERR_XOR),IDS_TIP_PRIORITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_WARN_XOR),IDS_TIP_PRIORITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_NOTICE_XOR),IDS_TIP_PRIORITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_INFO_XOR),IDS_TIP_PRIORITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_DEBUG_XOR),IDS_TIP_PRIORITY_XOR);

	m_Daddy->AddTips(m_tooltip,this,PFROM,PTO);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CLogPatternUnix::PreTranslateMessage(MSG* pMsg) 
{
	m_tooltip.RelayEvent(pMsg);

	return CPropertyPage::PreTranslateMessage(pMsg);
}
