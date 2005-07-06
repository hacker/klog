// KLogDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKLogDlg dialog

class CKLogDlg;
class CKLogSocket : public CSyslogSocket {
public:
	CKLogDlg* m_Daddy;
	virtual void Log(UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin);
};

class CHostMask	: public CObject{
public:
	virtual void Serialize(CArchive& ar);
	DWORD	m_Host;
	DWORD	m_Mask;
	BOOL	IsThis(DWORD host)	{ return (host&m_Mask)==(m_Host&m_Mask); }
	CHostMask()	: m_Host(0), m_Mask(0) {}
	CHostMask(DWORD host,DWORD mask) : m_Host(host), m_Mask(mask) {}
	CString String();

	DECLARE_SERIAL( CHostMask )
};
class CLogEntry	: public CObject {
public:
	CLogEntry(CLogEntry& src);
	CLogEntry& operator=(CLogEntry& src);
	CTime m_Time;
	CString m_Source;
	CString m_Data;
	UINT m_Priority;
	UINT m_Facility;
	DECLARE_SERIAL( CLogEntry )
public:
	CLogEntry();
};

typedef	CTypedPtrList<CObList,CHostMask*> CAccessList;
typedef CList<CLogEntry*,CLogEntry*> CLog;

class CLogger	: public CObject	{
public:
	void LookupHost(CKLogDlg *daddy);
	void LogLine(CKLogDlg *dad,UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin);
	BOOL IsHostFine(DWORD saddr);
	virtual void Serialize(CArchive& ar);
	virtual ~CLogger();
	void PlayWave();
	CLogger(BOOL bAll=FALSE);
	CString	m_Desc;
	enum	{
		logToFile=0, logToHost=1, logToNone=2,
	};
	int m_LogTo;
	CString	m_LogToName;
	SOCKADDR_IN m_LogToHost;
	BOOL m_LogPattern[CSyslogSocket::totalFacilities][CSyslogSocket::totalPriorities];
	CAccessList m_Hosts;
	CString	m_Sound;
	CLog m_Log;
	DECLARE_SERIAL( CLogger )
};

typedef CMap<CLogger*,CLogger*,CLogger*,CLogger*> CLoggers;

class CTrayer;
class CKLogDlg : public CDialog
{
// Construction
public:
	BOOL m_bDontWarn;
	BOOL m_bWarnBlocking;
	CSyslogSocket m_SLS;
	virtual ~CKLogDlg();
	void SaveSettings();
	void LoadSettings();
	BOOL m_bExiting;
	BOOL m_bShown;
	CTrayer* m_Trayer;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void AddLogLine(CLogEntry *le);
	void LogMessage(UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin);
	CKLogSocket m_KLS;
	virtual void Serialize(CArchive& ar);
	void TotalCleanUp();
	BITMAP m_bitmapBack;
	CBitmap m_bmpBack;
	void UpdateLogLength(BOOL bSave=TRUE,BOOL update=FALSE);
	int m_LogItems;
	void UpdateLogto(BOOL bSave=TRUE,BOOL update=TRUE);
	void UpdatePriface(BOOL bSave=TRUE,BOOL update=TRUE);
	static UINT m_PriorityCtls[CSyslogSocket::totalPriorities];
	CLogger* m_Logger;
	void SetTab(CLogger* l);
	int m_iTriggered;
	int m_iNormal;
	CImageList m_Images;
	CLoggers m_Logs;
	CKLogDlg(CWnd* pParent = NULL);	// standard constructor

	DECLARE_SERIAL( CKLogDlg )

// Dialog Data
	//{{AFX_DATA(CKLogDlg)
	enum { IDD = IDD_KLOG_DIALOG };
	CButton	m_CancelCtl;
	CButton	m_LogPatternCtl;
	CButton	m_FilesCtl;
	CSpinButtonCtrl	m_LogLenSpinCtl;
	CStatic	m_LogLengthCtl;
	CButton	m_PriInvertCtl;
	CButton	m_LogtoFileCtl;
	CButton	m_LogtoHostCtl;
	CButton	m_LogtoNoneCtl;
	CStatic	m_HFNameCaptionCtl;
	CListBox	m_hlCtl;
	CButton	m_BrowseSoundCtl;
	CButton	m_PriNoneCtl;
	CButton	m_hlRemoveCtl;
	CEdit	m_hlMaskCtl;
	CEdit	m_hlIPCtl;
	CButton	m_hlAddCtl;
	CButton	m_PriAllCtl;
	CComboBox	m_SoundCtl;
	CButton	m_RemoveCtl;
	CButton	m_PlaySoundCtl;
	CListBox	m_Log;
	CEdit	m_HFNameCtl;
	CComboBox	m_FacilityCtl;
	CButton	m_BrowseCtl;
	CEdit	m_DescCtl;
	CTabCtrl	m_Tabs;
	int		m_Logto;
	CString	m_Desc;
	CString	m_Facility;
	CString	m_HFName;
	CString	m_HFNameCaption;
	CString	m_hlIP;
	CString	m_hlMask;
	CString	m_Sound;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKLogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CKLogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnSelchangeTabs(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeFacility();
	afx_msg void OnPriority();
	afx_msg void OnLogto();
	afx_msg void OnPriAll();
	afx_msg void OnPriNone();
	afx_msg void OnChangeDesc();
	afx_msg void OnPriInvert();
	afx_msg void OnHlAdd();
	afx_msg void OnSelchangeHosts();
	afx_msg void OnHlRemove();
	afx_msg void OnRemove();
	afx_msg void OnPlaysound();
	afx_msg void OnEditchangeSound();
	afx_msg void OnKillfocusSound();
	afx_msg void OnDeltaposLoglenspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnExit();
	afx_msg void OnFiles();
	afx_msg void OnFilesExport();
	afx_msg void OnFilesImport();
	afx_msg void OnBrowsesound();
	afx_msg void OnKillfocusHostfile();
	virtual void OnOK();
	afx_msg void OnBrowse();
	afx_msg void OnFilesReset();
	afx_msg void OnSelchangeLog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnTrayAboutklog();
	afx_msg void OnTrayExit();
	afx_msg void OnTrayShowklogwindow();
	afx_msg void OnWindowPosChanging(WINDOWPOS FAR* lpwndpos);
	afx_msg void OnLogpattern();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
