// LogPatternUnix.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogPatternUnix dialog

class CLogPattern;
class CLogPatternUnix : public CPropertyPage
{
	DECLARE_DYNCREATE(CLogPatternUnix)

// Construction
public:
	CToolTipCtrl m_tooltip;
	CLogPattern* m_Daddy;
	CLogPatternUnix(CLogPattern *daddy=NULL);
	~CLogPatternUnix();

// Dialog Data
	//{{AFX_DATA(CLogPatternUnix)
	enum { IDD = IDD_LOG_UNIX };
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CLogPatternUnix)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CLogPatternUnix)
	afx_msg void OnAlertOn();
	afx_msg void OnAuthOn();
	afx_msg void OnAlertXor();
	afx_msg void OnAuthXor();
	afx_msg void OnCritOn();
	afx_msg void OnCritXor();
	afx_msg void OnCronOn();
	afx_msg void OnCronXor();
	afx_msg void OnDaemonOn();
	afx_msg void OnDaemonXor();
	afx_msg void OnDebugOn();
	afx_msg void OnDebugXor();
	afx_msg void OnEmergOn();
	afx_msg void OnEmergXor();
	afx_msg void OnErrOn();
	afx_msg void OnErrXor();
	afx_msg void OnInfoOn();
	afx_msg void OnInfoXor();
	afx_msg void OnKernelOn();
	afx_msg void OnKernelXor();
	afx_msg void OnLprOn();
	afx_msg void OnLprXor();
	afx_msg void OnMailOn();
	afx_msg void OnMailXor();
	afx_msg void OnNewsOn();
	afx_msg void OnNewsXor();
	afx_msg void OnNoticeOn();
	afx_msg void OnNoticeXor();
	afx_msg void OnSyslogOn();
	afx_msg void OnSyslogXor();
	afx_msg void OnUserOn();
	afx_msg void OnUserXor();
	afx_msg void OnUucpOn();
	afx_msg void OnUucpXor();
	afx_msg void OnWarnOn();
	afx_msg void OnWarnXor();
	afx_msg void OnAuthprivOn();
	afx_msg void OnAuthprivXor();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
