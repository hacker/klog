// LogPattern.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogPattern

class	CLogPatternUnix;
class	CLogPatternReserved;
class	CLogPatternLocal;
class CLogPattern : public CPropertySheet
{
	DECLARE_DYNAMIC(CLogPattern)

// Construction
public:
	void AddTips(CToolTipCtrl& tt,CWnd *pWnd,UINT from,UINT to);
	void FacilityXor(CWnd *pWnd,UINT fac);
	void FacilityOn(CWnd *pWnd,UINT fac);
	void PriorityXor(CWnd *pWnd,UINT pri,UINT from,UINT to);
	void PriorityOn(CWnd *pWnd,UINT pri,UINT from,UINT to);
	void ExchangeData(CDataExchange *pDX,UINT from,UINT to);
	static UINT m_ID[CSyslogSocket::totalFacilities][CSyslogSocket::totalPriorities];
	CLogPatternLocal *m_Local;
	CLogPatternReserved *m_Reserved;
	CLogPatternUnix *m_Unix;
	void AddPages();
	BOOL m_Pattern[CSyslogSocket::totalFacilities][CSyslogSocket::totalPriorities];
	CLogPattern(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CLogPattern(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogPattern)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLogPattern();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLogPattern)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
