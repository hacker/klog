// LogPattern.cpp : implementation file
//

#include "stdafx.h"
#include "KLog.h"
#include "SyslogSocket.h"
#include "LogPattern.h"

#include "LogPatternUnix.h"
#include "LogPatternReserved.h"
#include "LogPatternLocal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogPattern

UINT CLogPattern::m_ID[CSyslogSocket::totalFacilities][CSyslogSocket::totalPriorities] = {
	// Unix
	{ IDC_KERNEL_EMERG,IDC_KERNEL_ALERT,IDC_KERNEL_CRIT,IDC_KERNEL_ERR,IDC_KERNEL_WARN,IDC_KERNEL_NOTICE,IDC_KERNEL_INFO,IDC_KERNEL_DEBUG },
	{ IDC_USER_EMERG,IDC_USER_ALERT,IDC_USER_CRIT,IDC_USER_ERR,IDC_USER_WARN,IDC_USER_NOTICE,IDC_USER_INFO,IDC_USER_DEBUG },
	{ IDC_MAIL_EMERG,IDC_MAIL_ALERT,IDC_MAIL_CRIT,IDC_MAIL_ERR,IDC_MAIL_WARN,IDC_MAIL_NOTICE,IDC_MAIL_INFO,IDC_MAIL_DEBUG },
	{ IDC_DAEMON_EMERG,IDC_DAEMON_ALERT,IDC_DAEMON_CRIT,IDC_DAEMON_ERR,IDC_DAEMON_WARN,IDC_DAEMON_NOTICE,IDC_DAEMON_INFO,IDC_DAEMON_DEBUG },
	{ IDC_AUTH_EMERG,IDC_AUTH_ALERT,IDC_AUTH_CRIT,IDC_AUTH_ERR,IDC_AUTH_WARN,IDC_AUTH_NOTICE,IDC_AUTH_INFO,IDC_AUTH_DEBUG },
	{ IDC_SYSLOG_EMERG,IDC_SYSLOG_ALERT,IDC_SYSLOG_CRIT,IDC_SYSLOG_ERR,IDC_SYSLOG_WARN,IDC_SYSLOG_NOTICE,IDC_SYSLOG_INFO,IDC_SYSLOG_DEBUG },
	{ IDC_LPR_EMERG,IDC_LPR_ALERT,IDC_LPR_CRIT,IDC_LPR_ERR,IDC_LPR_WARN,IDC_LPR_NOTICE,IDC_LPR_INFO,IDC_LPR_DEBUG },
	{ IDC_NEWS_EMERG,IDC_NEWS_ALERT,IDC_NEWS_CRIT,IDC_NEWS_ERR,IDC_NEWS_WARN,IDC_NEWS_NOTICE,IDC_NEWS_INFO,IDC_NEWS_DEBUG },
	{ IDC_UUCP_EMERG,IDC_UUCP_ALERT,IDC_UUCP_CRIT,IDC_UUCP_ERR,IDC_UUCP_WARN,IDC_UUCP_NOTICE,IDC_UUCP_INFO,IDC_UUCP_DEBUG },
	{ IDC_CRON_EMERG,IDC_CRON_ALERT,IDC_CRON_CRIT,IDC_CRON_ERR,IDC_CRON_WARN,IDC_CRON_NOTICE,IDC_CRON_INFO,IDC_CRON_DEBUG },
	{ IDC_AUTHPRIV_EMERG,IDC_AUTHPRIV_ALERT,IDC_AUTHPRIV_CRIT,IDC_AUTHPRIV_ERR,IDC_AUTHPRIV_WARN,IDC_AUTHPRIV_NOTICE,IDC_AUTHPRIV_INFO,IDC_AUTHPRIV_DEBUG },
	// Reserved
	{ IDC_R0_EMERG,IDC_R0_ALERT,IDC_R0_CRIT,IDC_R0_ERR,IDC_R0_WARN,IDC_R0_NOTICE,IDC_R0_INFO,IDC_R0_DEBUG },
	{ IDC_R1_EMERG,IDC_R1_ALERT,IDC_R1_CRIT,IDC_R1_ERR,IDC_R1_WARN,IDC_R1_NOTICE,IDC_R1_INFO,IDC_R1_DEBUG },
	{ IDC_R2_EMERG,IDC_R2_ALERT,IDC_R2_CRIT,IDC_R2_ERR,IDC_R2_WARN,IDC_R2_NOTICE,IDC_R2_INFO,IDC_R2_DEBUG },
	{ IDC_R3_EMERG,IDC_R3_ALERT,IDC_R3_CRIT,IDC_R3_ERR,IDC_R3_WARN,IDC_R3_NOTICE,IDC_R3_INFO,IDC_R3_DEBUG },
	{ IDC_R4_EMERG,IDC_R4_ALERT,IDC_R4_CRIT,IDC_R4_ERR,IDC_R4_WARN,IDC_R4_NOTICE,IDC_R4_INFO,IDC_R4_DEBUG },
	// Local
	{ IDC_L0_EMERG,IDC_L0_ALERT,IDC_L0_CRIT,IDC_L0_ERR,IDC_L0_WARN,IDC_L0_NOTICE,IDC_L0_INFO,IDC_L0_DEBUG },
	{ IDC_L1_EMERG,IDC_L1_ALERT,IDC_L1_CRIT,IDC_L1_ERR,IDC_L1_WARN,IDC_L1_NOTICE,IDC_L1_INFO,IDC_L1_DEBUG },
	{ IDC_L2_EMERG,IDC_L2_ALERT,IDC_L2_CRIT,IDC_L2_ERR,IDC_L2_WARN,IDC_L2_NOTICE,IDC_L2_INFO,IDC_L2_DEBUG },
	{ IDC_L3_EMERG,IDC_L3_ALERT,IDC_L3_CRIT,IDC_L3_ERR,IDC_L3_WARN,IDC_L3_NOTICE,IDC_L3_INFO,IDC_L3_DEBUG },
	{ IDC_L4_EMERG,IDC_L4_ALERT,IDC_L4_CRIT,IDC_L4_ERR,IDC_L4_WARN,IDC_L4_NOTICE,IDC_L4_INFO,IDC_L4_DEBUG },
	{ IDC_L5_EMERG,IDC_L5_ALERT,IDC_L5_CRIT,IDC_L5_ERR,IDC_L5_WARN,IDC_L5_NOTICE,IDC_L5_INFO,IDC_L5_DEBUG },
	{ IDC_L6_EMERG,IDC_L6_ALERT,IDC_L6_CRIT,IDC_L6_ERR,IDC_L6_WARN,IDC_L6_NOTICE,IDC_L6_INFO,IDC_L6_DEBUG },
	{ IDC_L7_EMERG,IDC_L7_ALERT,IDC_L7_CRIT,IDC_L7_ERR,IDC_L7_WARN,IDC_L7_NOTICE,IDC_L7_INFO,IDC_L7_DEBUG }
};

IMPLEMENT_DYNAMIC(CLogPattern, CPropertySheet)

CLogPattern::CLogPattern(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPages();
}

CLogPattern::CLogPattern(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPages();
}

CLogPattern::~CLogPattern()
{
	delete m_Unix;
	delete m_Reserved;
	delete m_Local;
}


BEGIN_MESSAGE_MAP(CLogPattern, CPropertySheet)
	//{{AFX_MSG_MAP(CLogPattern)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogPattern message handlers

void CLogPattern::AddPages()
{
	m_Unix = new CLogPatternUnix(this);
	ASSERT(m_Unix);
	AddPage(m_Unix);
	m_Reserved = new CLogPatternReserved(this);
	ASSERT(m_Reserved);
	AddPage(m_Reserved);
	m_Local = new CLogPatternLocal(this);
	ASSERT(m_Local);
	AddPage(m_Local);
}

void CLogPattern::ExchangeData(CDataExchange *pDX,UINT from,UINT to)
{
	if(pDX->m_bSaveAndValidate){
		for(UINT f=from;f<=to;f++){
			for(UINT p=0;p<CSyslogSocket::totalPriorities;p++){
				switch(pDX->m_pDlgWnd->IsDlgButtonChecked(m_ID[f][p])){
				case 0:
					m_Pattern[f][p]=FALSE;
					break;
				case 1:
					m_Pattern[f][p]=TRUE;
					break;
#ifndef	NDEBUG
				default:
					ASSERT(FALSE);
					break;
#endif
				}
			}
		}
	}else{
		for(UINT f=from;f<=to;f++){
			for(UINT p=0;p<CSyslogSocket::totalPriorities;p++){
				pDX->m_pDlgWnd->CheckDlgButton(m_ID[f][p],m_Pattern[f][p]?1:0);
			}
		}
	}
}

void CLogPattern::PriorityOn(CWnd *pWnd,UINT pri,UINT from,UINT to)
{
	for(UINT f=from;f<=to;f++)
		pWnd->CheckDlgButton(m_ID[f][pri],1);
}

void CLogPattern::PriorityXor(CWnd *pWnd,UINT pri,UINT from,UINT to)
{
	for(UINT f=from;f<=to;f++)
		pWnd->CheckDlgButton(m_ID[f][pri],pWnd->IsDlgButtonChecked(m_ID[f][pri])?0:1);
}

void CLogPattern::FacilityOn(CWnd *pWnd,UINT fac)
{
	for(int p=0;p<CSyslogSocket::totalPriorities;p++)
		pWnd->CheckDlgButton(m_ID[fac][p],1);
}

void CLogPattern::FacilityXor(CWnd *pWnd,UINT fac)
{
	for(int p=0;p<CSyslogSocket::totalPriorities;p++)
		pWnd->CheckDlgButton(m_ID[fac][p],pWnd->IsDlgButtonChecked(m_ID[fac][p])?0:1);
}

void CLogPattern::AddTips(CToolTipCtrl& tt,CWnd *pWnd,UINT from,UINT to)
{
CString ttt;
	for(UINT f=from;f<to;f++){
		for(UINT p=0;p<CSyslogSocket::totalPriorities;p++){
			ttt.Format("%s.%s",CSyslogSocket::m_Facilities[f],CSyslogSocket::m_Priorities[p]);
			tt.AddTool(pWnd->GetDlgItem(m_ID[f][p]),ttt);
		}
	}
}
