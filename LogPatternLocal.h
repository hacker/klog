// LogPatternLocal.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogPatternLocal dialog

class CLogPattern;
class CLogPatternLocal : public CPropertyPage
{
	DECLARE_DYNCREATE(CLogPatternLocal)

// Construction
public:
	CToolTipCtrl m_tooltip;
	CLogPattern* m_Daddy;
	CLogPatternLocal(CLogPattern *daddy=NULL);
	~CLogPatternLocal();

// Dialog Data
	//{{AFX_DATA(CLogPatternLocal)
	enum { IDD = IDD_LOG_LOCAL };
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CLogPatternLocal)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CLogPatternLocal)
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
	afx_msg void OnL0On();
	afx_msg void OnL0Xor();
	afx_msg void OnL1On();
	afx_msg void OnL1Xor();
	afx_msg void OnL2On();
	afx_msg void OnL2Xor();
	afx_msg void OnL3On();
	afx_msg void OnL3Xor();
	afx_msg void OnL4On();
	afx_msg void OnL4Xor();
	afx_msg void OnL5On();
	afx_msg void OnL5Xor();
	afx_msg void OnL6On();
	afx_msg void OnL6Xor();
	afx_msg void OnL7On();
	afx_msg void OnL7Xor();
	afx_msg void OnNoticeOn();
	afx_msg void OnNoticeXor();
	afx_msg void OnWarnOn();
	afx_msg void OnWarnXor();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
