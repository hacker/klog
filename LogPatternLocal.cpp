// LogPatternLocal.cpp : implementation file
//

#include "stdafx.h"
#include "KLog.h"
#include "LogPatternLocal.h"

#include "SyslogSocket.h"
#include "LogPattern.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogPatternLocal property page

#define	PFROM CSyslogSocket::facLocal0
#define	PTO		CSyslogSocket::facLocal7

IMPLEMENT_DYNCREATE(CLogPatternLocal, CPropertyPage)

CLogPatternLocal::CLogPatternLocal(CLogPattern* daddy) : CPropertyPage(CLogPatternLocal::IDD), m_Daddy(daddy)
{
	//{{AFX_DATA_INIT(CLogPatternLocal)
	//}}AFX_DATA_INIT
}

CLogPatternLocal::~CLogPatternLocal()
{
}

void CLogPatternLocal::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogPatternLocal)
	//}}AFX_DATA_MAP
	m_Daddy->ExchangeData(pDX,PFROM,PTO);
}


BEGIN_MESSAGE_MAP(CLogPatternLocal, CPropertyPage)
	//{{AFX_MSG_MAP(CLogPatternLocal)
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
	ON_BN_CLICKED(IDC_L0_ON, OnL0On)
	ON_BN_CLICKED(IDC_L0_XOR, OnL0Xor)
	ON_BN_CLICKED(IDC_L1_ON, OnL1On)
	ON_BN_CLICKED(IDC_L1_XOR, OnL1Xor)
	ON_BN_CLICKED(IDC_L2_ON, OnL2On)
	ON_BN_CLICKED(IDC_L2_XOR, OnL2Xor)
	ON_BN_CLICKED(IDC_L3_ON, OnL3On)
	ON_BN_CLICKED(IDC_L3_XOR, OnL3Xor)
	ON_BN_CLICKED(IDC_L4_ON, OnL4On)
	ON_BN_CLICKED(IDC_L4_XOR, OnL4Xor)
	ON_BN_CLICKED(IDC_L5_ON, OnL5On)
	ON_BN_CLICKED(IDC_L5_XOR, OnL5Xor)
	ON_BN_CLICKED(IDC_L6_ON, OnL6On)
	ON_BN_CLICKED(IDC_L6_XOR, OnL6Xor)
	ON_BN_CLICKED(IDC_L7_ON, OnL7On)
	ON_BN_CLICKED(IDC_L7_XOR, OnL7Xor)
	ON_BN_CLICKED(IDC_NOTICE_ON, OnNoticeOn)
	ON_BN_CLICKED(IDC_NOTICE_XOR, OnNoticeXor)
	ON_BN_CLICKED(IDC_WARN_ON, OnWarnOn)
	ON_BN_CLICKED(IDC_WARN_XOR, OnWarnXor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogPatternLocal message handlers

void CLogPatternLocal::OnAlertOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priAlert,PFROM,PTO);
}
void CLogPatternLocal::OnAlertXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priAlert,PFROM,PTO);
}

void CLogPatternLocal::OnCritOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priCritical,PFROM,PTO);
}
void CLogPatternLocal::OnCritXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priCritical,PFROM,PTO);
}

void CLogPatternLocal::OnDebugOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priDebug,PFROM,PTO);
}
void CLogPatternLocal::OnDebugXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priDebug,PFROM,PTO);
}

void CLogPatternLocal::OnEmergOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priEmergency,PFROM,PTO);
}
void CLogPatternLocal::OnEmergXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priEmergency,PFROM,PTO);
}

void CLogPatternLocal::OnErrOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priError,PFROM,PTO);
}
void CLogPatternLocal::OnErrXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priError,PFROM,PTO);
}

void CLogPatternLocal::OnInfoOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priInfo,PFROM,PTO);
}
void CLogPatternLocal::OnInfoXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priInfo,PFROM,PTO);
}

void CLogPatternLocal::OnL0On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal0);
}
void CLogPatternLocal::OnL0Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal0);
}

void CLogPatternLocal::OnL1On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal1);
}
void CLogPatternLocal::OnL1Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal1);
}

void CLogPatternLocal::OnL2On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal2);
}
void CLogPatternLocal::OnL2Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal2);
}

void CLogPatternLocal::OnL3On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal3);
}
void CLogPatternLocal::OnL3Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal3);
}

void CLogPatternLocal::OnL4On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal4);
}
void CLogPatternLocal::OnL4Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal4);
}

void CLogPatternLocal::OnL5On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal5);
}
void CLogPatternLocal::OnL5Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal5);
}

void CLogPatternLocal::OnL6On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal6);
	
}
void CLogPatternLocal::OnL6Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal6);
}

void CLogPatternLocal::OnL7On() 
{
	m_Daddy->FacilityOn(this,CSyslogSocket::facLocal7);
}
void CLogPatternLocal::OnL7Xor() 
{
	m_Daddy->FacilityXor(this,CSyslogSocket::facLocal7);
}

void CLogPatternLocal::OnNoticeOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priNotice,PFROM,PTO);
}
void CLogPatternLocal::OnNoticeXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priNotice,PFROM,PTO);
}

void CLogPatternLocal::OnWarnOn() 
{
	m_Daddy->PriorityOn(this,CSyslogSocket::priWarning,PFROM,PTO);
}
void CLogPatternLocal::OnWarnXor() 
{
	m_Daddy->PriorityXor(this,CSyslogSocket::priWarning,PFROM,PTO);
}

BOOL CLogPatternLocal::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_tooltip.Create(this);
	m_tooltip.Activate(TRUE);
	m_tooltip.AddTool(GetDlgItem(IDC_L0_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_L1_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_L2_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_L3_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_L4_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_L5_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_L6_ON),IDS_TIP_FACILITY_ON);
	m_tooltip.AddTool(GetDlgItem(IDC_L7_ON),IDS_TIP_FACILITY_ON);

	m_tooltip.AddTool(GetDlgItem(IDC_L0_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_L1_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_L2_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_L3_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_L4_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_L5_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_L6_XOR),IDS_TIP_FACILITY_XOR);
	m_tooltip.AddTool(GetDlgItem(IDC_L7_XOR),IDS_TIP_FACILITY_XOR);

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

BOOL CLogPatternLocal::PreTranslateMessage(MSG* pMsg) 
{
	m_tooltip.RelayEvent(pMsg);

	return CPropertyPage::PreTranslateMessage(pMsg);
}
