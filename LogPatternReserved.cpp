// LogPatternReserved.cpp : implementation file
//

#include "stdafx.h"
#include "KLog.h"
#include "LogPatternReserved.h"

#include "SyslogSocket.h"
#include "LogPattern.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogPatternReserved property page

#define	PFROM CSyslogSocket::facReserved0
#define	PTO		CSyslogSocket::facReserved4

IMPLEMENT_DYNCREATE(CLogPatternReserved, CPropertyPage)

CLogPatternReserved::CLogPatternReserved(CLogPattern *daddy) : CPropertyPage(CLogPatternReserved::IDD), m_Daddy(daddy)
{
	//{{AFX_DATA_INIT(CLogPatternReserved)
	//}}AFX_DATA_INIT
}

CLogPatternReserved::~CLogPatternReserved()
{
}

void CLogPatternReserved::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogPatternReserved)
	//}}AFX_DATA_MAP
	m_Daddy->ExchangeData(pDX,PFROM,PTO);
}


BEGIN_MESSAGE_MAP(CLogPatternReserved, CPropertyPage)
	//{{AFX_MSG_MAP(CLogPatternReserved)
	ON_BN_CLICKED(IDC_ALERT_ON, OnAlertOn)
	ON_BN_CLICKED(IDC_ALERT_XOR, OnAlertXor)
	ON_BN_CLICKED(IDC_CRIT_ON, OnCritOn)
	ON_BN_CLICKED(IDC_CRIT_XOR, OnCritXor)
	ON_BN_CLICKED(IDC_DEBUG_ON, OnDebugOn)
	ON_BN_CLICKED(IDC_DEBUG_XOR, OnDebugXor)
	ON_BN_CLICKED(IDC_EMERG_ON, OnEmergOn)
	ON_BN_CLICKED(IDC_EMERG_XOR, OnEmergXor)
	ON_BN_CLICKED(IDC_ERR_ON, OnErrOn)
	ON_BN_CLICKED(IDC_ERR_XOR, OnErrXor)
	ON_BN_CLICKED(IDC_INFO_ON, OnInfoOn)
	ON_BN_CLICKED(IDC_INFO_XOR, OnInfoXor)
	ON_BN_CLICKED(IDC_NOTICE_ON, OnNoticeOn)
	ON_BN_CLICKED(IDC_NOTICE_XOR, OnNoticeXor)
	ON_BN_CLICKED(IDC_R0_ON, OnR0On)
	ON_BN_CLICKED(IDC_R0_XOR, OnR0Xor)
	ON_BN_CLICKED(IDC_R1_ON, OnR1On)
	ON_BN_CLICKED(IDC_R1_XOR, OnR1Xor)
	ON_BN_CLICKED(IDC_R2_ON, OnR2On)
	ON_BN_CLICKED(IDC_R2_XOR, OnR2Xor)
	ON_BN_CLICKED(IDC_R3_ON, OnR3On)
	ON_BN_CLICKED(IDC_R3_XOR, OnR3Xor)
	ON_BN_CLICKED(IDC_R4_ON, OnR4On)
	ON_BN_CLICKED(IDC_R4_XOR, OnR4Xor)
	ON_BN_CLICKED(IDC_WARN_ON, OnWarnOn)
	ON_BN_CLICKED(IDC_WARN_XOR, OnWarnXor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogPatternReserved message handlers

void CLogPatternReserved::OnAlertOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priAlert,PFROM,PTO);
}
void CLogPatternReserved::OnAlertXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priAlert,PFROM,PTO);
}

void CLogPatternReserved::OnCritOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priCritical,PFROM,PTO);
}
void CLogPatternReserved::OnCritXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priCritical,PFROM,PTO);
}

void CLogPatternReserved::OnDebugOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priDebug,PFROM,PTO);
}
void CLogPatternReserved::OnDebugXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priDebug,PFROM,PTO);
}

void CLogPatternReserved::OnEmergOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priEmergency,PFROM,PTO);
}
void CLogPatternReserved::OnEmergXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priEmergency,PFROM,PTO);
}

void CLogPatternReserved::OnErrOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priError,PFROM,PTO);
}
void CLogPatternReserved::OnErrXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priError,PFROM,PTO);
}

void CLogPatternReserved::OnInfoOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priInfo,PFROM,PTO);
}
void CLogPatternReserved::OnInfoXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priInfo,PFROM,PTO);
}

void CLogPatternReserved::OnNoticeOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priNotice,PFROM,PTO);
}
void CLogPatternReserved::OnNoticeXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priNotice,PFROM,PTO);
}

void CLogPatternReserved::OnR0On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facReserved0);
}
void CLogPatternReserved::OnR0Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facReserved0);
}

void CLogPatternReserved::OnR1On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facReserved1);
}
void CLogPatternReserved::OnR1Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facReserved1);
}

void CLogPatternReserved::OnR2On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facReserved2);
}
void CLogPatternReserved::OnR2Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facReserved2);
}

void CLogPatternReserved::OnR3On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facReserved3);
}
void CLogPatternReserved::OnR3Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facReserved3);
}

void CLogPatternReserved::OnR4On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facReserved4);
}
void CLogPatternReserved::OnR4Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facReserved4);
}

void CLogPatternReserved::OnWarnOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priWarning,PFROM,PTO);
}
void CLogPatternReserved::OnWarnXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priWarning,PFROM,PTO);
}

BOOL CLogPatternReserved::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);
	m_tooltip.AddTool(GetDlgItem(IDC_R0_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_R1_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_R2_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_R3_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_R4_ON),IDS_TIP_FACILITY_ON);

	m_tooltip.AddTool(GetDlgItem(IDC_R0_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_R1_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_R2_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_R3_XOR),IDS_TIP_FACILITY_XOR);

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

BOOL CLogPatternReserved::PreTranslateMessage(MSG* pMsg) 
{
	m_tooltip.RelayEvent(pMsg);

	return CPropertyPage::PreTranslateMessage(pMsg);
}
