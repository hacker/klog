// LogPatternReserved.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogPatternReserved dialog

class CLogPattern;
class CLogPatternReserved : public CPropertyPage
{
	DECLARE_DYNCREATE(CLogPatternReserved)

// Construction
public:
	CToolTipCtrl m_tooltip;
	CLogPattern* m_Daddy;
	CLogPatternReserved(CLogPattern *daddy=NULL);
	~CLogPatternReserved();

// Dialog Data
	//{{AFX_DATA(CLogPatternReserved)
	enum { IDD = IDD_LOG_RESERVED };
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CLogPatternReserved)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CLogPatternReserved)
	afx_msg void OnAlertOn();
	afx_msg void OnAlertXor();
	afx_msg void OnCritOn();
	afx_msg void OnCritXor();
	afx_msg void OnDebugOn();
	afx_msg void OnDebugXor();
	afx_msg void OnEmergOn();
	afx_msg void OnEmergXor();
	afx_msg void OnErrOn();
	afx_msg void OnErrXor();
	afx_msg void OnInfoOn();
	afx_msg void OnInfoXor();
	afx_msg void OnNoticeOn();
	afx_msg void OnNoticeXor();
	afx_msg void OnR0On();
	afx_msg void OnR0Xor();
	afx_msg void OnR1On();
	afx_msg void OnR1Xor();
	afx_msg void OnR2On();
	afx_msg void OnR2Xor();
	afx_msg void OnR3On();
	afx_msg void OnR3Xor();
	afx_msg void OnR4On();
	afx_msg void OnR4Xor();
	afx_msg void OnWarnOn();
	afx_msg void OnWarnXor();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
