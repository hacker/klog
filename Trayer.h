// Trayer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTrayer window

class CKLogDlg;
class CTrayer : public CWnd
{
// Construction
public:
	CKLogDlg * m_Daddy;
	CTrayer(CKLogDlg* daddy);
	int m_inMenu;
	CTrayer();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayer)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTrayer();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTrayer)
	afx_msg LRESULT OnTray(WPARAM,LPARAM);
	afx_msg void OnTrayAboutklog();
	afx_msg void OnTrayExit();
	afx_msg void OnTrayHelp();
	afx_msg void OnTrayShowklogwindow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
