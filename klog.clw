; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CKLogDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "KLog.h"

ClassCount=9
Class1=CKLogApp
Class2=CKLogDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_LOG_LOCAL
Resource2=IDR_MAINFRAME
Class4=CTrayer
Resource3=IDD_LOG_RESERVED
Resource4=IDD_WARNBLOCKING
Resource5=IDD_LOG_UNIX
Class5=CLogPattern
Class6=CLogPatternUnix
Class7=CLogPatternReserved
Class8=CLogPatternLocal
Resource6=IDD_ABOUTBOX
Class9=CWarnBlocking
Resource7=IDD_KLOG_DIALOG

[CLS:CKLogApp]
Type=0
HeaderFile=KLog.h
ImplementationFile=KLog.cpp
Filter=N

[CLS:CKLogDlg]
Type=0
HeaderFile=KLogDlg.h
ImplementationFile=KLogDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LOG

[CLS:CAboutDlg]
Type=0
HeaderFile=KLogDlg.h
ImplementationFile=KLogDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_KLEVERNET

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_KLEVERNET,button,1342242816

[DLG:IDD_KLOG_DIALOG]
Type=1
Class=CKLogDlg
ControlCount=48
Control1=IDC_STATIC,static,1342308609
Control2=IDC_DESC,edit,1350631552
Control3=IDC_TYPE_FILE,button,1342312457
Control4=IDC_TYPE_HOST,button,1342181385
Control5=IDC_TYPE_NONE,button,1342181385
Control6=IDC_HOSTORFILE,static,1342308353
Control7=IDC_HOSTFILE,edit,1350631552
Control8=IDC_BROWSE,button,1342242816
Control9=IDC_STATIC,static,1342177296
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342177296
Control12=IDC_STATIC,static,1342308352
Control13=IDC_FACILITY,combobox,1344340035
Control14=IDC_LOGPATTERN,button,1342263104
Control15=IDC_STATIC,button,1342194439
Control16=IDC_EMERG,button,1342259747
Control17=IDC_ALERT,button,1342259747
Control18=IDC_CRIT,button,1342259747
Control19=IDC_ERR,button,1342259747
Control20=IDC_WARNING,button,1342259459
Control21=IDC_NOTICE,button,1342259459
Control22=IDC_INFO,button,1342259459
Control23=IDC_DEBUG,button,1342259459
Control24=IDC_ALL,button,1342242816
Control25=IDC_NONE,button,1342242816
Control26=IDC_INVERT,button,1342259200
Control27=IDC_STATIC,static,1342308608
Control28=IDC_HL_IP,edit,1350631552
Control29=IDC_STATIC,static,1342308608
Control30=IDC_HL_MASK,edit,1350631552
Control31=IDC_HL_ADD,button,1342259200
Control32=IDC_HL_REMOVE,button,1342242816
Control33=IDC_HOSTS,listbox,1345388929
Control34=IDC_STATIC,button,1342177287
Control35=IDC_SOUND,combobox,1344340034
Control36=IDC_BROWSESOUND,button,1342263104
Control37=IDC_PLAYSOUND,button,1342263104
Control38=IDC_LOG,listbox,1353793665
Control39=IDC_ADD,button,1342259200
Control40=IDC_REMOVE,button,1342242816
Control41=IDC_EXIT,button,1342242816
Control42=IDC_TABS,SysTabControl32,1342193664
Control43=IDC_LOGLENGTH,static,1342308737
Control44=IDC_LOGLENSPIN,msctls_updown32,1342177463
Control45=IDC_STATIC_LOGLENGTH,static,1342308737
Control46=IDOK,button,1073807361
Control47=IDCANCEL,button,1208025088
Control48=IDC_FILES,button,1342197504

[MNU:IDD_KLOG_DIALOG]
Type=1
Class=?
Command1=ID_FILES_EXPORT
Command2=ID_FILES_IMPORT
Command3=ID_FILES_RESET
Command4=ID_FILES_EXPORT
Command5=ID_FILES_IMPORT
Command6=ID_FILES_RESET
Command7=ID_TRAY_SHOWKLOGWINDOW
Command8=ID_TRAY_HELP
Command9=ID_TRAY_ABOUTKLOG
Command10=ID_TRAY_EXIT
CommandCount=10

[CLS:CTrayer]
Type=0
HeaderFile=Trayer.h
ImplementationFile=Trayer.cpp
BaseClass=generic CWnd
Filter=W
LastObject=ID_FILES_RESET

[DLG:IDD_LOG_RESERVED]
Type=1
Class=CLogPatternReserved
ControlCount=68
Control1=IDC_EMERG_ON,button,1342263040
Control2=IDC_ALERT_ON,button,1342263040
Control3=IDC_CRIT_ON,button,1342263040
Control4=IDC_ERR_ON,button,1342263040
Control5=IDC_WARN_ON,button,1342263040
Control6=IDC_NOTICE_ON,button,1342263040
Control7=IDC_INFO_ON,button,1342263040
Control8=IDC_DEBUG_ON,button,1342263040
Control9=IDC_R0_ON,button,1342263040
Control10=IDC_R1_ON,button,1342263040
Control11=IDC_R2_ON,button,1342263040
Control12=IDC_R3_ON,button,1342263040
Control13=IDC_R4_ON,button,1342263040
Control14=IDC_R0_EMERG,button,1342263299
Control15=IDC_R0_ALERT,button,1342263299
Control16=IDC_R0_CRIT,button,1342263299
Control17=IDC_R0_ERR,button,1342263299
Control18=IDC_R0_WARN,button,1342263299
Control19=IDC_R0_NOTICE,button,1342263299
Control20=IDC_R0_INFO,button,1342263299
Control21=IDC_R0_DEBUG,button,1342263299
Control22=IDC_R1_EMERG,button,1342263299
Control23=IDC_R1_ALERT,button,1342263299
Control24=IDC_R1_CRIT,button,1342263299
Control25=IDC_R1_ERR,button,1342263299
Control26=IDC_R1_WARN,button,1342263299
Control27=IDC_R1_NOTICE,button,1342263299
Control28=IDC_R1_INFO,button,1342263299
Control29=IDC_R1_DEBUG,button,1342263299
Control30=IDC_R2_EMERG,button,1342263299
Control31=IDC_R2_ALERT,button,1342263299
Control32=IDC_R2_CRIT,button,1342263299
Control33=IDC_R2_ERR,button,1342263299
Control34=IDC_R2_WARN,button,1342263299
Control35=IDC_R2_NOTICE,button,1342263299
Control36=IDC_R2_INFO,button,1342263299
Control37=IDC_R2_DEBUG,button,1342263299
Control38=IDC_R3_EMERG,button,1342263299
Control39=IDC_R3_ALERT,button,1342263299
Control40=IDC_R3_CRIT,button,1342263299
Control41=IDC_R3_ERR,button,1342263299
Control42=IDC_R3_WARN,button,1342263299
Control43=IDC_R3_NOTICE,button,1342263299
Control44=IDC_R3_INFO,button,1342263299
Control45=IDC_R3_DEBUG,button,1342263299
Control46=IDC_R4_EMERG,button,1342263299
Control47=IDC_R4_ALERT,button,1342263299
Control48=IDC_R4_CRIT,button,1342263299
Control49=IDC_R4_ERR,button,1342263299
Control50=IDC_R4_WARN,button,1342263299
Control51=IDC_R4_NOTICE,button,1342263299
Control52=IDC_R4_INFO,button,1342263299
Control53=IDC_R4_DEBUG,button,1342263299
Control54=IDC_EMERG_XOR,button,1342263040
Control55=IDC_ALERT_XOR,button,1342263040
Control56=IDC_CRIT_XOR,button,1342263040
Control57=IDC_ERR_XOR,button,1342263040
Control58=IDC_WARN_XOR,button,1342263040
Control59=IDC_NOTICE_XOR,button,1342263040
Control60=IDC_INFO_XOR,button,1342263040
Control61=IDC_DEBUG_XOR,button,1342263040
Control62=IDC_R0_XOR,button,1342263040
Control63=IDC_R1_XOR,button,1342263040
Control64=IDC_R2_XOR,button,1342263040
Control65=IDC_R3_XOR,button,1342263040
Control66=IDC_R4_XOR,button,1342263040
Control67=IDC_STATIC,static,1342308352
Control68=IDC_STATIC,static,1342308352

[DLG:IDD_LOG_UNIX]
Type=1
Class=CLogPatternUnix
ControlCount=128
Control1=IDC_EMERG_ON,button,1342263040
Control2=IDC_ALERT_ON,button,1342263040
Control3=IDC_CRIT_ON,button,1342263040
Control4=IDC_ERR_ON,button,1342263040
Control5=IDC_WARN_ON,button,1342263040
Control6=IDC_NOTICE_ON,button,1342263040
Control7=IDC_INFO_ON,button,1342263040
Control8=IDC_DEBUG_ON,button,1342263040
Control9=IDC_KERNEL_ON,button,1342263040
Control10=IDC_USER_ON,button,1342263040
Control11=IDC_MAIL_ON,button,1342263040
Control12=IDC_DAEMON_ON,button,1342263040
Control13=IDC_AUTH_ON,button,1342263040
Control14=IDC_SYSLOG_ON,button,1342263040
Control15=IDC_LPR_ON,button,1342263040
Control16=IDC_NEWS_ON,button,1342263040
Control17=IDC_UUCP_ON,button,1342263040
Control18=IDC_CRON_ON,button,1342263040
Control19=IDC_KERNEL_EMERG,button,1342263299
Control20=IDC_KERNEL_ALERT,button,1342263299
Control21=IDC_KERNEL_CRIT,button,1342263299
Control22=IDC_KERNEL_ERR,button,1342263299
Control23=IDC_KERNEL_WARN,button,1342263299
Control24=IDC_KERNEL_NOTICE,button,1342263299
Control25=IDC_KERNEL_INFO,button,1342263299
Control26=IDC_KERNEL_DEBUG,button,1342263299
Control27=IDC_USER_EMERG,button,1342263299
Control28=IDC_USER_ALERT,button,1342263299
Control29=IDC_USER_CRIT,button,1342263299
Control30=IDC_USER_ERR,button,1342263299
Control31=IDC_USER_WARN,button,1342263299
Control32=IDC_USER_NOTICE,button,1342263299
Control33=IDC_USER_INFO,button,1342263299
Control34=IDC_USER_DEBUG,button,1342263299
Control35=IDC_MAIL_EMERG,button,1342263299
Control36=IDC_MAIL_ALERT,button,1342263299
Control37=IDC_MAIL_CRIT,button,1342263299
Control38=IDC_MAIL_ERR,button,1342263299
Control39=IDC_MAIL_WARN,button,1342263299
Control40=IDC_MAIL_NOTICE,button,1342263299
Control41=IDC_MAIL_INFO,button,1342263299
Control42=IDC_MAIL_DEBUG,button,1342263299
Control43=IDC_DAEMON_EMERG,button,1342263299
Control44=IDC_DAEMON_ALERT,button,1342263299
Control45=IDC_DAEMON_CRIT,button,1342263299
Control46=IDC_DAEMON_ERR,button,1342263299
Control47=IDC_DAEMON_WARN,button,1342263299
Control48=IDC_DAEMON_NOTICE,button,1342263299
Control49=IDC_DAEMON_INFO,button,1342263299
Control50=IDC_DAEMON_DEBUG,button,1342263299
Control51=IDC_AUTH_EMERG,button,1342263299
Control52=IDC_AUTH_ALERT,button,1342263299
Control53=IDC_AUTH_CRIT,button,1342263299
Control54=IDC_AUTH_ERR,button,1342263299
Control55=IDC_AUTH_WARN,button,1342263299
Control56=IDC_AUTH_NOTICE,button,1342263299
Control57=IDC_AUTH_INFO,button,1342263299
Control58=IDC_AUTH_DEBUG,button,1342263299
Control59=IDC_SYSLOG_EMERG,button,1342263299
Control60=IDC_SYSLOG_ALERT,button,1342263299
Control61=IDC_SYSLOG_CRIT,button,1342263299
Control62=IDC_SYSLOG_ERR,button,1342263299
Control63=IDC_SYSLOG_WARN,button,1342263299
Control64=IDC_SYSLOG_NOTICE,button,1342263299
Control65=IDC_SYSLOG_INFO,button,1342263299
Control66=IDC_SYSLOG_DEBUG,button,1342263299
Control67=IDC_LPR_EMERG,button,1342263299
Control68=IDC_LPR_ALERT,button,1342263299
Control69=IDC_LPR_CRIT,button,1342263299
Control70=IDC_LPR_ERR,button,1342263299
Control71=IDC_LPR_WARN,button,1342263299
Control72=IDC_LPR_NOTICE,button,1342263299
Control73=IDC_LPR_INFO,button,1342263299
Control74=IDC_LPR_DEBUG,button,1342263299
Control75=IDC_NEWS_EMERG,button,1342263299
Control76=IDC_NEWS_ALERT,button,1342263299
Control77=IDC_NEWS_CRIT,button,1342263299
Control78=IDC_NEWS_ERR,button,1342263299
Control79=IDC_NEWS_WARN,button,1342263299
Control80=IDC_NEWS_NOTICE,button,1342263299
Control81=IDC_NEWS_INFO,button,1342263299
Control82=IDC_NEWS_DEBUG,button,1342263299
Control83=IDC_UUCP_EMERG,button,1342263299
Control84=IDC_UUCP_ALERT,button,1342263299
Control85=IDC_UUCP_CRIT,button,1342263299
Control86=IDC_UUCP_ERR,button,1342263299
Control87=IDC_UUCP_WARN,button,1342263299
Control88=IDC_UUCP_NOTICE,button,1342263299
Control89=IDC_UUCP_INFO,button,1342263299
Control90=IDC_UUCP_DEBUG,button,1342263299
Control91=IDC_CRON_EMERG,button,1342263299
Control92=IDC_CRON_ALERT,button,1342263299
Control93=IDC_CRON_CRIT,button,1342263299
Control94=IDC_CRON_ERR,button,1342263299
Control95=IDC_CRON_WARN,button,1342263299
Control96=IDC_CRON_NOTICE,button,1342263299
Control97=IDC_CRON_INFO,button,1342263299
Control98=IDC_CRON_DEBUG,button,1342263299
Control99=IDC_EMERG_XOR,button,1342263040
Control100=IDC_ALERT_XOR,button,1342263040
Control101=IDC_CRIT_XOR,button,1342263040
Control102=IDC_ERR_XOR,button,1342263040
Control103=IDC_WARN_XOR,button,1342263040
Control104=IDC_NOTICE_XOR,button,1342263040
Control105=IDC_INFO_XOR,button,1342263040
Control106=IDC_DEBUG_XOR,button,1342263040
Control107=IDC_KERNEL_XOR,button,1342263040
Control108=IDC_USER_XOR,button,1342263040
Control109=IDC_MAIL_XOR,button,1342263040
Control110=IDC_DAEMON_XOR,button,1342263040
Control111=IDC_AUTH_XOR,button,1342263040
Control112=IDC_SYSLOG_XOR,button,1342263040
Control113=IDC_LPR_XOR,button,1342263040
Control114=IDC_NEWS_XOR,button,1342263040
Control115=IDC_UUCP_XOR,button,1342263040
Control116=IDC_CRON_XOR,button,1342263040
Control117=IDC_STATIC,static,1342308352
Control118=IDC_STATIC,static,1342308352
Control119=IDC_AUTHPRIV_ON,button,1342263040
Control120=IDC_AUTHPRIV_EMERG,button,1342263299
Control121=IDC_AUTHPRIV_ALERT,button,1342263299
Control122=IDC_AUTHPRIV_CRIT,button,1342263299
Control123=IDC_AUTHPRIV_ERR,button,1342263299
Control124=IDC_AUTHPRIV_WARN,button,1342263299
Control125=IDC_AUTHPRIV_NOTICE,button,1342263299
Control126=IDC_AUTHPRIV_INFO,button,1342263299
Control127=IDC_AUTHPRIV_DEBUG,button,1342263299
Control128=IDC_AUTHPRIV_XOR,button,1342263040

[DLG:IDD_LOG_LOCAL]
Type=1
Class=CLogPatternLocal
ControlCount=98
Control1=IDC_EMERG_ON,button,1342263040
Control2=IDC_ALERT_ON,button,1342263040
Control3=IDC_CRIT_ON,button,1342263040
Control4=IDC_ERR_ON,button,1342263040
Control5=IDC_WARN_ON,button,1342263040
Control6=IDC_NOTICE_ON,button,1342263040
Control7=IDC_INFO_ON,button,1342263040
Control8=IDC_DEBUG_ON,button,1342263040
Control9=IDC_L0_ON,button,1342263040
Control10=IDC_L1_ON,button,1342263040
Control11=IDC_L2_ON,button,1342263040
Control12=IDC_L3_ON,button,1342263040
Control13=IDC_L4_ON,button,1342263040
Control14=IDC_L5_ON,button,1342263040
Control15=IDC_L6_ON,button,1342263040
Control16=IDC_L7_ON,button,1342263040
Control17=IDC_L0_EMERG,button,1342263299
Control18=IDC_L0_ALERT,button,1342263299
Control19=IDC_L0_CRIT,button,1342263299
Control20=IDC_L0_ERR,button,1342263299
Control21=IDC_L0_WARN,button,1342263299
Control22=IDC_L0_NOTICE,button,1342263299
Control23=IDC_L0_INFO,button,1342263299
Control24=IDC_L0_DEBUG,button,1342263299
Control25=IDC_L1_EMERG,button,1342263299
Control26=IDC_L1_ALERT,button,1342263299
Control27=IDC_L1_CRIT,button,1342263299
Control28=IDC_L1_ERR,button,1342263299
Control29=IDC_L1_WARN,button,1342263299
Control30=IDC_L1_NOTICE,button,1342263299
Control31=IDC_L1_INFO,button,1342263299
Control32=IDC_L1_DEBUG,button,1342263299
Control33=IDC_L2_EMERG,button,1342263299
Control34=IDC_L2_ALERT,button,1342263299
Control35=IDC_L2_CRIT,button,1342263299
Control36=IDC_L2_ERR,button,1342263299
Control37=IDC_L2_WARN,button,1342263299
Control38=IDC_L2_NOTICE,button,1342263299
Control39=IDC_L2_INFO,button,1342263299
Control40=IDC_L2_DEBUG,button,1342263299
Control41=IDC_L3_EMERG,button,1342263299
Control42=IDC_L3_ALERT,button,1342263299
Control43=IDC_L3_CRIT,button,1342263299
Control44=IDC_L3_ERR,button,1342263299
Control45=IDC_L3_WARN,button,1342263299
Control46=IDC_L3_NOTICE,button,1342263299
Control47=IDC_L3_INFO,button,1342263299
Control48=IDC_L3_DEBUG,button,1342263299
Control49=IDC_L4_EMERG,button,1342263299
Control50=IDC_L4_ALERT,button,1342263299
Control51=IDC_L4_CRIT,button,1342263299
Control52=IDC_L4_ERR,button,1342263299
Control53=IDC_L4_WARN,button,1342263299
Control54=IDC_L4_NOTICE,button,1342263299
Control55=IDC_L4_INFO,button,1342263299
Control56=IDC_L4_DEBUG,button,1342263299
Control57=IDC_L5_EMERG,button,1342263299
Control58=IDC_L5_ALERT,button,1342263299
Control59=IDC_L5_CRIT,button,1342263299
Control60=IDC_L5_ERR,button,1342263299
Control61=IDC_L5_WARN,button,1342263299
Control62=IDC_L5_NOTICE,button,1342263299
Control63=IDC_L5_INFO,button,1342263299
Control64=IDC_L5_DEBUG,button,1342263299
Control65=IDC_L6_EMERG,button,1342263299
Control66=IDC_L6_ALERT,button,1342263299
Control67=IDC_L6_CRIT,button,1342263299
Control68=IDC_L6_ERR,button,1342263299
Control69=IDC_L6_WARN,button,1342263299
Control70=IDC_L6_NOTICE,button,1342263299
Control71=IDC_L6_INFO,button,1342263299
Control72=IDC_L6_DEBUG,button,1342263299
Control73=IDC_L7_EMERG,button,1342263299
Control74=IDC_L7_ALERT,button,1342263299
Control75=IDC_L7_CRIT,button,1342263299
Control76=IDC_L7_ERR,button,1342263299
Control77=IDC_L7_WARN,button,1342263299
Control78=IDC_L7_NOTICE,button,1342263299
Control79=IDC_L7_INFO,button,1342263299
Control80=IDC_L7_DEBUG,button,1342263299
Control81=IDC_EMERG_XOR,button,1342263040
Control82=IDC_ALERT_XOR,button,1342263040
Control83=IDC_CRIT_XOR,button,1342263040
Control84=IDC_ERR_XOR,button,1342263040
Control85=IDC_WARN_XOR,button,1342263040
Control86=IDC_NOTICE_XOR,button,1342263040
Control87=IDC_INFO_XOR,button,1342263040
Control88=IDC_DEBUG_XOR,button,1342263040
Control89=IDC_L0_XOR,button,1342263040
Control90=IDC_L1_XOR,button,1342263040
Control91=IDC_L2_XOR,button,1342263040
Control92=IDC_L3_XOR,button,1342263040
Control93=IDC_L4_XOR,button,1342263040
Control94=IDC_L5_XOR,button,1342263040
Control95=IDC_L6_XOR,button,1342263040
Control96=IDC_L7_XOR,button,1342263040
Control97=IDC_STATIC,static,1342308352
Control98=IDC_STATIC,static,1342308352

[CLS:CLogPattern]
Type=0
HeaderFile=LogPattern.h
ImplementationFile=LogPattern.cpp
BaseClass=CPropertySheet
Filter=W
LastObject=CLogPattern

[CLS:CLogPatternUnix]
Type=0
HeaderFile=LogPatternUnix.h
ImplementationFile=LogPatternUnix.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CLogPatternUnix
VirtualFilter=idWC

[CLS:CLogPatternReserved]
Type=0
HeaderFile=LogPatternReserved.h
ImplementationFile=LogPatternReserved.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=IDC_WARN_XOR
VirtualFilter=idWC

[CLS:CLogPatternLocal]
Type=0
HeaderFile=LogPatternLocal.h
ImplementationFile=LogPatternLocal.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CLogPatternLocal
VirtualFilter=idWC

[DLG:IDD_WARNBLOCKING]
Type=1
Class=CWarnBlocking
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_WARNBLOCKING,button,1342254595

[CLS:CWarnBlocking]
Type=0
HeaderFile=WarnBlocking.h
ImplementationFile=WarnBlocking.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CWarnBlocking

