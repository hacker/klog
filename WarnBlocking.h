// WarnBlocking.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWarnBlocking dialog

class CWarnBlocking : public CDialog
{
// Construction
public:
	CWarnBlocking(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWarnBlocking)
	enum { IDD = IDD_WARNBLOCKING };
	BOOL	m_bDontWarn;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWarnBlocking)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWarnBlocking)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
