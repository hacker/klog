#include "stdafx.h"
#include "SyslogSocket.h"

LPCTSTR CSyslogSocket::m_Priorities[8] = {
	"emerg", "alert", "crit", "err", "warn", "notice", "info", "debug"
};
LPCTSTR CSyslogSocket::m_Facilities[24] = {
	"kernel", "user", "mail", "daemon", "auth", "syslog", "lpr","news","uucp","cron","authpriv","reserved0","reserved1","reserved2","reserved3","reserved4","local0","local1","local2","local3","local4","local5","local6","local7"
};

BOOL CSyslogSocket::CreateListen(UINT port)
{
	if(!Create(port?port:m_Port,SOCK_DGRAM))
		return FALSE;
	DoSelect();
	return TRUE;
}

CSyslogSocket::CSyslogSocket()
{
	m_Port=514;
	m_MaxLine=2048;
	m_DefaultPriority=MakePriority(priNotice,facUser);
	memset(&m_DefaultHost,0,sizeof(m_DefaultHost));
	m_DefaultHost.sin_family=AF_INET;
	m_DefaultHost.sin_addr.s_addr=inet_addr("127.0.0.1");
	m_DefaultHost.sin_port=m_Port;
}

void CSyslogSocket::DoSelect()
{
	AsyncSelect(FD_CLOSE|FD_READ|(m_Queue.IsEmpty()?0:FD_WRITE));
}

void CSyslogSocket::OnReceive(int nErrorCode)
{
	if(nErrorCode){
		TRACE0("Error on receiving socket\n");
		return;
	}
SOCKADDR_IN sin;
int sinLength = sizeof(sin);
CString inputLine;
LPTSTR buff = inputLine.GetBuffer(m_MaxLine+1);
int bytes = ReceiveFrom(buff,m_MaxLine,(SOCKADDR*)&sin,&sinLength);
	if(bytes==SOCKET_ERROR){
		TRACE0("Failed to receive datagram\n");
		return;
	}
	buff[bytes]=0;
	inputLine.ReleaseBuffer();
UINT pri = m_DefaultPriority;
	if(!inputLine.IsEmpty()){
		if(inputLine[0]=='<'){
			inputLine=inputLine.Mid(1);
		CString newPri = inputLine.SpanIncluding("0123456789");
			inputLine=inputLine.Mid(newPri.GetLength());
			if((!inputLine.IsEmpty()) && inputLine[0]=='>')
				inputLine=inputLine.Mid(1);
			pri = atoi((LPCTSTR)newPri);
		}
	}
	ASSERT(sin.sin_family==AF_INET);
	Log(Priority(pri),Facility(pri),inputLine,&sin);
	DoSelect();
}

void CSyslogSocket::Log(UINT pri,UINT fac,LPCTSTR line,SOCKADDR_IN *sin)
{
	// Default implementation does nothing.
}

CString CSyslogSocket::Escape(LPCTSTR str)
{
CString rv;
	while(*str){
	int c = *(str++);
		if(iscntrl(c)){
			switch(c){
			case '\n':
				c=' ';
				break;
			case '\t':
				c='\t';
				break;
			default:
				rv+='^';
				c|='@';
				break;
			}
		}
		rv+=(char)c;
	}
	return rv;
}

BOOL CSyslogSocket::LogTo(SOCKADDR_IN* sin,UINT pri,UINT fac,LPCTSTR str)
{
	ASSERT(sin);
CString tmp;
	tmp.Format("<%u>",MakePriority(pri,fac));
	tmp+=str;
	return LogTo(sin,tmp);
}

BOOL CSyslogSocket::LogTo(SOCKADDR_IN* sin,LPCTSTR str)
{
CSyslogOutgoingPacket *p = new CSyslogOutgoingPacket;
	ASSERT(p);
	memmove(&p->m_To,sin,sizeof(p->m_To));
	p->m_What=str;
	m_Queue.AddTail(p);
	DoSelect();
	return TRUE;
}

BOOL CSyslogSocket::LogTo(DWORD sinAddr,UINT sinPort,LPCTSTR str)
{
SOCKADDR_IN sin;
	memset(&sin,0,sizeof(sin));
	sin.sin_addr.s_addr=sinAddr;
	sin.sin_port=sinPort;
	sin.sin_family=AF_INET;
	return LogTo(&sin,str);
}

BOOL CSyslogSocket::LogTo(DWORD sinAddr,UINT sinPort,UINT pri,UINT fac,LPCTSTR str)
{
SOCKADDR_IN sin;
	memset(&sin,0,sizeof(sin));
	sin.sin_addr.s_addr=sinAddr;
	sin.sin_port=sinPort;
	sin.sin_family=AF_INET;
	return LogTo(&sin,pri,fac,str);
}

BOOL CSyslogSocket::LogTo(DWORD sinAddr,UINT pri,UINT fac,LPCTSTR str)
{
	return LogTo(sinAddr,m_Port,pri,fac,str);
}

BOOL CSyslogSocket::LogTo(DWORD sinAddr,LPCTSTR str)
{
	return LogTo(sinAddr,m_Port,str);
}

BOOL CSyslogSocket::LogTo(UINT pri,UINT fac,LPCTSTR str)
{
	return LogTo(&m_DefaultHost,pri,fac,str);
}

BOOL CSyslogSocket::LogTo(LPCTSTR str)
{
	return LogTo(&m_DefaultHost,str);
}

UINT CSyslogSocket::Facility(LPCTSTR str)
{
	ASSERT(str);
	for(int tmp=0;tmp<(sizeof(m_Facilities)/sizeof(m_Facilities[0]));tmp++)
		if(!strcmp(str,m_Facilities[tmp]))
			return tmp;
	return facNone;
}

UINT CSyslogSocket::Priority(LPCTSTR str)
{
	ASSERT(str);
	for(int tmp=0;tmp<(sizeof(m_Priorities)/sizeof(m_Priorities[0]));tmp++)
		if(!strcmp(str,m_Priorities[tmp]))
			return tmp;
	return priNone;
}

void CSyslogSocket::OnSend(int nErrorCode)
{
	if(nErrorCode){
		TRACE0("Error on sending socket\n");
		return;
	}
	if(!m_Queue.IsEmpty()){
	CSyslogOutgoingPacket *p = m_Queue.GetHead();
		ASSERT(p);
		m_Queue.RemoveHead();
	int rv = SendTo((LPCTSTR)p->m_What,p->m_What.GetLength(),(SOCKADDR*)&p->m_To,sizeof(SOCKADDR_IN));
		if(rv!=p->m_What.GetLength()){
			TRACE0("Failed to send on socket\n");
		}
		delete p;
	}
	DoSelect();
}
