
struct CSyslogOutgoingPacket	{
	SOCKADDR_IN m_To;
	CString m_What;
};
typedef CList<CSyslogOutgoingPacket*,CSyslogOutgoingPacket*> CSyslogOutgoingPackets;

class CSyslogSocket	: public CAsyncSocket	{
public:
	virtual void OnSend(int nErrorCode);
	static UINT Priority(LPCTSTR str);
	static UINT Facility(LPCTSTR str);
	BOOL LogTo(LPCTSTR str);
	SOCKADDR_IN m_DefaultHost;
	BOOL LogTo(UINT pri,UINT fac,LPCTSTR str);
	BOOL LogTo(DWORD sinAddr,LPCTSTR str);
	BOOL LogTo(DWORD sinAddr,UINT pri,UINT fac,LPCTSTR str);
	BOOL LogTo(DWORD sinAddr,UINT sinPort,UINT pri,UINT fac,LPCTSTR str);
	BOOL LogTo(DWORD sinAddr,UINT sinPort,LPCTSTR str);
	BOOL LogTo(SOCKADDR_IN* sin,LPCTSTR str);
	BOOL LogTo(SOCKADDR_IN* sin,UINT pri,UINT fac,LPCTSTR str);
	static CString Escape(LPCTSTR str);
	virtual void Log(UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin);
	UINT m_DefaultPriority;
	virtual void OnReceive(int nErrorCode);
	UINT m_MaxLine;
	void DoSelect();
	CSyslogOutgoingPackets m_Queue;
	CSyslogSocket();
	UINT m_Port;
	BOOL CreateListen(UINT port=0);
	static LPCTSTR m_Facilities[24];
	static LPCTSTR m_Priorities[8];
	enum	{
		maskPriority = 7,
		maskFacility = 0x3F8,
		shiftFacility = 3,
		priNone = 0xFFFF,
		facNone = 0xFFFF,
		totalPriorities=8,
		totalFacilities=24,

		priEmergency=0,
		priAlert=1,
		priCritical=2,
		priError=3,
		priWarning=4,
		priNotice=5,
		priInfo=6,
		priDebug=7,

		facKernel=0,
		facUser=1,
		facMail=2,
		facDaemon=3,
		facAuth=4,
		facSyslog=5,
		facLPR=6,
		facNews=7,
		facUUCP=8,
		facCron=9,
		facAuthPriv=10,

		facReserved0=11,
		facReserved1=12,
		facReserved2=13,
		facReserved3=14,
		facReserved4=15,

		facLocal0=16,
		facLocal1=17,
		facLocal2=18,
		facLocal3=19,
		facLocal4=20,
		facLocal5=21,
		facLocal6=22,
		facLocal7=23
	};
	static UINT Priority(UINT pri)	{ return pri&maskPriority; }
	static UINT Facility(UINT pri)	{ return (pri&maskFacility)>>shiftFacility; }
	static UINT MakePriority(UINT pri,UINT fac) { return (pri&maskPriority)|((fac<<shiftFacility)&maskFacility); }
};