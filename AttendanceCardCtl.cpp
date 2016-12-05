// AttendanceCardCtl.cpp : Implementation of the CAttendanceCardCtrl ActiveX Control class.

#include "stdafx.h"
#include "AttendanceCard.h"
#include "AttendanceCardCtl.h"
#include "AttendanceCardPpg.h"
#include "winsock2.h"
#pragma comment(lib,"ws2_32.lib")


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAttendanceCardCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAttendanceCardCtrl, COleControl)
	//{{AFX_MSG_MAP(CAttendanceCardCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CAttendanceCardCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CAttendanceCardCtrl)
	DISP_FUNCTION(CAttendanceCardCtrl, "Init", Init, VT_BOOL, VTS_I2)
	DISP_FUNCTION(CAttendanceCardCtrl, "Quit", Quit, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetCardType", GetCardType, VT_I2, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "ReadMainData", ReadMainData, VT_BSTR, VTS_I2)
	DISP_FUNCTION(CAttendanceCardCtrl, "WriteMainData", WriteMainData, VT_BOOL, VTS_I2 VTS_BSTR)
	DISP_FUNCTION(CAttendanceCardCtrl, "ReadAttendanceData", ReadAttendanceData, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "WriteAttendanceData", WriteAttendanceData, VT_BOOL, VTS_BSTR)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetCurrentBalance", GetCurrentBalance, VT_R8, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetCurrentUsingTimes", GetCurrentUsingTimes, VT_I4, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "Charge", Charge, VT_I2, VTS_I2)
	DISP_FUNCTION(CAttendanceCardCtrl, "DispOnLED", DispOnLED, VT_BOOL, VTS_R8)
	DISP_FUNCTION(CAttendanceCardCtrl, "Beep", Beep, VT_BOOL, VTS_I2)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetLastAttTime", GetLastAttTime, VT_DATE, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetExpiryDate", GetExpiryDate, VT_DATE, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "Halt", Halt, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetLocalIp", GetLocalIp, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetCardID", GetCardID, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetUserType", GetUserType, VT_I2, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "GetBarcode", GetBarcode, VT_BSTR, VTS_NONE)
	DISP_FUNCTION(CAttendanceCardCtrl, "InitBarcodeDev", InitBarcodeDev, VT_BOOL, VTS_I2)
	DISP_FUNCTION(CAttendanceCardCtrl, "BeepEx", BeepEx, VT_BOOL, VTS_I2 VTS_I2)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CAttendanceCardCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CAttendanceCardCtrl, COleControl)
	//{{AFX_EVENT_MAP(CAttendanceCardCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CAttendanceCardCtrl, 1)
	PROPPAGEID(CAttendanceCardPropPage::guid)
END_PROPPAGEIDS(CAttendanceCardCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAttendanceCardCtrl, "ATTENDANCECARD.AttendanceCardCtrl.1",
	0x9ee82e7f, 0xb57, 0x4058, 0x8c, 0x44, 0xa3, 0xb0, 0xbb, 0xcf, 0xee, 0xa1)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CAttendanceCardCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DAttendanceCard =
		{ 0x2434e974, 0x5536, 0x421f, { 0xac, 0x30, 0x5d, 0x57, 0x30, 0xeb, 0x7d, 0x98 } };
const IID BASED_CODE IID_DAttendanceCardEvents =
		{ 0xc9671b1e, 0x65da, 0x4e7b, { 0x83, 0x63, 0x87, 0x1f, 0x89, 0xfb, 0x3e, 0x13 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwAttendanceCardOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAttendanceCardCtrl, IDS_ATTENDANCECARD, _dwAttendanceCardOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::CAttendanceCardCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CAttendanceCardCtrl

BOOL CAttendanceCardCtrl::CAttendanceCardCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_ATTENDANCECARD,
			IDB_ATTENDANCECARD,
			afxRegApartmentThreading,
			_dwAttendanceCardOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// Licensing strings

static const TCHAR BASED_CODE _szLicFileName[] = _T("AttendanceCard.lic");

static const WCHAR BASED_CODE _szLicString[] =
	L"Copyright (c) 2012 广州市委党校";


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::CAttendanceCardCtrlFactory::VerifyUserLicense -
// Checks for existence of a user license

BOOL CAttendanceCardCtrl::CAttendanceCardCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::CAttendanceCardCtrlFactory::GetLicenseKey -
// Returns a runtime licensing key

BOOL CAttendanceCardCtrl::CAttendanceCardCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR FAR* pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::CAttendanceCardCtrl - Constructor

CAttendanceCardCtrl::CAttendanceCardCtrl()
{
	InitializeIIDs(&IID_DAttendanceCard, &IID_DAttendanceCardEvents);

	// TODO: Initialize your control's instance data here.
	m_pReader = new CReader();
	m_pCard = new CCard();

#ifdef EN_DEBUG
	m_pDbg = new CDebug("c:\\log.txt");
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::~CAttendanceCardCtrl - Destructor

CAttendanceCardCtrl::~CAttendanceCardCtrl()
{
	// TODO: Cleanup your control's instance data here.
	delete m_pReader;
	delete m_pCard;
#ifdef EN_DEBUG
	delete m_pDbg;
#endif
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::OnDraw - Drawing function

void CAttendanceCardCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::DoPropExchange - Persistence support

void CAttendanceCardCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::OnResetState - Reset control to default state

void CAttendanceCardCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl::AboutBox - Display an "About" box to the user

void CAttendanceCardCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_ATTENDANCECARD);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl message handlers

void CAttendanceCardCtrl::RawToHex(unsigned char *dst, const unsigned char *src, int srcLen)
{
	int cnt = 0, i;
	char ch;
	for(i = 0; i < srcLen; ++i)
	{
		ch = src[i] >> 4;
		if(ch > 9)
		{
			ch += 'A';
			ch -= 10;
		}
		else
		{	
			ch += '0';
		}
		dst[cnt] = ch;
		cnt++;

		ch = src[i] & 0x0F;
		if(ch > 9)
		{
			ch += 'A';
			ch -= 10;
		}
		else
		{	
			ch += '0';
		}
		dst[cnt] = ch;
		cnt++;
		
	}//end for
}

int CAttendanceCardCtrl::HexToRaw(unsigned char *dst, const unsigned char *src, int srcLen)
{
	int cnt = 0, i;
	unsigned char ch;
	for(i = 0; i < srcLen; ++i)
	{
		if(src[i] >= '0' && src[i] <= '9') 
		{
			ch = src[i] - '0';
		}
		else if (src[i] >= 'A' && src[i] <= 'F')
		{
			ch = src[i] + 10 - 'A';
		}
		else if (src[i] >= 'a' && src[i] <= 'f')
		{
			ch = src[i] + 10 - 'a';
		}
		else
		{
			return cnt;
		}

		if(i % 2 == 0)
		{
			dst[i / 2] = ch * 16;
		}
		else
		{
			dst[i / 2] += ch;
			cnt++;
		}
	}

	return cnt;
}

BOOL CAttendanceCardCtrl::Init(short port) 
{
	// TODO: Add your dispatch handler code here

	return TRUE;
}

void CAttendanceCardCtrl::Quit() 
{
	// TODO: Add your dispatch handler code here

}

short CAttendanceCardCtrl::GetCardType() 
{
	// TODO: Add your dispatch handler code here
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetCardType");
#endif
	//return m_pCard->GetCardTypeId();
	return m_pCard->GetUserType();
}

BSTR CAttendanceCardCtrl::ReadMainData(short Adr) 
{
	CString strResult;
	// TODO: Add your dispatch handler code here

	return strResult.AllocSysString();
}

BOOL CAttendanceCardCtrl::WriteMainData(short Adr, LPCTSTR Data) 
{
	// TODO: Add your dispatch handler code here

	return TRUE;
}

BSTR CAttendanceCardCtrl::ReadAttendanceData() 
{
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("ReadAttendanceData");
#endif
	CString strResult;
	// TODO: Add your dispatch handler code here
	unsigned char code[6] = USING_KEY;
	unsigned char buffer[16];
	int ret = m_pReader->ReadBlock(CCard::MODE_IDLE_KEY_A, 
								CCard::SECTOR_NUM_ATTENDANCE * 4 + 2, 
								1,
								code,
								buffer);
	if(ret != 0)
		return NULL;

	unsigned char temp[33];
	RawToHex(temp, buffer, 16);
	temp[32] = '\0';
	strResult = temp;

	return strResult.AllocSysString();
}

BOOL CAttendanceCardCtrl::WriteAttendanceData(LPCTSTR Data) 
{
	#ifdef EN_DEBUG
	m_pDbg->ShowDebug("WriteAttendanceData");
#endif
	// TODO: Add your dispatch handler code here

	unsigned char buffer[16];
	if(strlen(Data) == 32)
	{
		HexToRaw(buffer, (const unsigned char *)Data, 32);
	} 
	else 
	{
		//系统当前时间
		COleDateTime dateCurrent = COleDateTime::GetCurrentTime();
		buffer[0] = (dateCurrent.GetYear() % 100) / 10 * 16 + (dateCurrent.GetYear() % 100) % 10;
		buffer[1] = dateCurrent.GetMonth() / 10 * 16 + dateCurrent.GetMonth() % 10;
		buffer[2] = dateCurrent.GetDay() / 10 * 16 + dateCurrent.GetDay() % 10;
		buffer[3] = dateCurrent.GetHour() / 10 * 16 + dateCurrent.GetHour() % 10;
		buffer[4] = dateCurrent.GetMinute() / 10 * 16 + dateCurrent.GetMinute() % 10;
		buffer[5] = dateCurrent.GetSecond() / 10 * 16 + dateCurrent.GetSecond() % 10;
		for(int i = 6; i < 15; ++i)
		{
			buffer[i] = '\0';
		}
	}

	unsigned char code[6] = USING_KEY;
	int ret = m_pReader->WriteBlock(CCard::MODE_IDLE_KEY_A, 
									CCard::SECTOR_NUM_ATTENDANCE * 4 + 2,
									1,
									code,
									buffer);
	if(ret != 0)
		return FALSE;

	return TRUE;
}

double CAttendanceCardCtrl::GetCurrentBalance() 
{
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetCurrentBalance");
#endif
	// TODO: Add your dispatch handler code here

	return m_pCard->GetBalance();
}

long CAttendanceCardCtrl::GetCurrentUsingTimes() 
{
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetCurrentUsingTimes");
#endif
	// TODO: Add your dispatch handler code here

	return m_pCard->GetUsingTimes();
}

short CAttendanceCardCtrl::Charge(short Money) 
{
	#ifdef EN_DEBUG
	m_pDbg->ShowDebug("Charge");
#endif
	// TODO: Add your dispatch handler code here
	short blockNum = m_pCard->GetCurrBlockNum();
	if(blockNum != 0 && blockNum != 1)
		return -1;

	// update balance
	double balance = m_pCard->GetBalance();
	if(balance < Money)
		return -2;
	balance -= Money;
	m_pCard->SetBalance(balance);

	// update using times
	long usingTimes = m_pCard->GetUsingTimes();
	usingTimes++;
	if(usingTimes > 0xFFFF)
		usingTimes = 0;
	m_pCard->SetUsingTimes(usingTimes);

	// read block
	unsigned char code[6] = USING_KEY;
	unsigned char buffer[16];
	int ret = m_pReader->ReadBlock(CCard::MODE_IDLE_KEY_A, 
								CCard::SECTOR_NUM_ATTENDANCE * 4 + blockNum, 
								1,
								code,
								buffer);
	if(ret != 0)
		return -3;

	// set update data
	buffer[0] = ((unsigned char *)&usingTimes)[1];
	buffer[1] = ((unsigned char *)&usingTimes)[0];

	CString updBalance;
	updBalance.Format("%ld",(long)((balance+0.005)*100.0));
	while(updBalance.GetLength()<6){
		updBalance.Insert(0,'0');
	}
	HexToRaw(&buffer[4], (const unsigned char *)(LPCTSTR)updBalance, 6);

	unsigned char code1[6] = USING_KEY;
	ret = m_pReader->WriteBlock(CCard::MODE_IDLE_KEY_A, 
									CCard::SECTOR_NUM_BUSINESS * 4 + (1 - blockNum),
									1,
									code1,
									buffer);
	if(ret != 0)
		return 1;

	return 0;
}

BOOL CAttendanceCardCtrl::DispOnLED(double Money) 
{
	// TODO: Add your dispatch handler code here

	return TRUE;
}

BOOL CAttendanceCardCtrl::Beep(short Time) 
{
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("Beep");
#endif
	// TODO: Add your dispatch handler code here
	unsigned char byte;
	m_pReader->SetBuzzer(Time / 10, 1, &byte);
	return TRUE;
}

DATE CAttendanceCardCtrl::GetLastAttTime() 
{
	#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetLastAttTime");
#endif
	// TODO: Add your dispatch handler code here

	return (DATE)(m_pCard->GetLastAttTime());
}

DATE CAttendanceCardCtrl::GetExpiryDate() 
{
	#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetExpiryDate");
#endif
	// TODO: Add your dispatch handler code here

	return (DATE)(m_pCard->GetExpriyDate());
}

void CAttendanceCardCtrl::Halt() 
{
	// TODO: Add your dispatch handler code here
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("Halt");
#endif
	m_pReader->Halt();
}

BSTR CAttendanceCardCtrl::GetLocalIp() 
{
	#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetLocalIp");
#endif
	CString LocalIp; 
	// TODO: Add your dispatch handler code here
	WORD wVersionRequested;   //定义一个WORD类型 
	WSADATA wsaData;    //定义一个WSADATA数据结构
	char name[255];  
	PHOSTENT hostinfo;   //定义hostent结构体
	wVersionRequested = MAKEWORD(2, 0);    //确定Winsock的版本 也可以直接赋值：wVersionRequested=2

	if(WSAStartup(wVersionRequested, &wsaData) == 0)  //对Winsock DLL进行初始化
	{  
		if(gethostname(name, sizeof(name)) == 0)   //获取主机名
		{  
			if((hostinfo = gethostbyname(name)) != NULL)   //判断主机名转成IP是否成功
			{  
				LocalIp = inet_ntoa(*(struct in_addr *)*hostinfo->h_addr_list);              
			}  
		}  
		WSACleanup();  //中止Windows Sockets DLL的使用
	} 
//*/
	return LocalIp.AllocSysString();
}

BSTR CAttendanceCardCtrl::GetCardID() 
{
		CString strResult;
	// TODO: Add your dispatch handler code here
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetCardID start");
#endif
	// read card snr number
	unsigned char byte;
	unsigned char val[4];
	int ret = m_pReader->GetSnr(CCard::MODE_IDLE, CCard::HALT_OFF, &byte, val);
	if(ret != 0)
		return NULL;

	unsigned long snr;
	((unsigned char *)&snr)[0] = val[0];
	((unsigned char *)&snr)[1] = val[1];
	((unsigned char *)&snr)[2] = val[2];
	//((unsigned char *)&snr)[3] = val[3];
	((unsigned char *)&snr)[3] = 0;
	strResult.Format("%u", snr);

	// read business sector block 0,1,2, 
	// and set balance, usingtimes, usertype, and expriydate.
	unsigned char code[6] = USING_KEY;
	unsigned char buffer[48];
	ret = m_pReader->ReadBlock(CCard::MODE_IDLE_KEY_A, 
								CCard::SECTOR_NUM_BUSINESS * 4, 
								3,
								code,
								buffer);
	if(ret != 0)
		return NULL;

	unsigned short temp;
	((unsigned char *)&temp)[0] = buffer[1];
	((unsigned char *)&temp)[1] = buffer[0];
	long usingTimes0 = temp;

	((unsigned char *)&temp)[0] = buffer[17];
	((unsigned char *)&temp)[1] = buffer[16];
	long usingTimes1 = temp;

	unsigned char tempch[7];
	RawToHex(tempch, &buffer[4], 3);
	tempch[6] = '\0';
	double balance0 = atof((const char *)tempch);
	balance0 /= 100.0;

	RawToHex(tempch, &buffer[20], 3);
	tempch[6] = '\0';
	double balance1 = atof((const char *)tempch);
	balance1 /= 100.0;

	short userType = (0x0080 >> buffer[36]);

	unsigned char tempStr[33];
	RawToHex(tempStr, &buffer[32], 16);
	tempStr[32] = '\0';
	CString expriyTime = tempStr;
	COleDateTime expriyDate;
	if(atoi(expriyTime.Mid(16, 6)) != 0)
	{
		CString strYear,strMonth,strDay;   
		//获取年   
		strYear = "20" + expriyTime.Mid(16, 2);   
		//获取月   
		strMonth = expriyTime.Mid(18, 2);  
		//获取日期   
		strDay = expriyTime.Mid(20, 2); 

		expriyDate.SetDateTime(atoi(strYear),
								atoi(strMonth),
								atoi(strDay),
								0,0,0); 
	}

	// read attendance data, and set last attendance date.
	COleDateTime attDate;
	CString attTime = ReadAttendanceData();
	if(atoi(attTime.Mid(0, 12)) != 0)
	{
		CString strYear, strMonth, strDay, strHour, strMinute, strSecond;   
		//获取年   
		strYear = "20" + attTime.Mid(0, 2);   
		//获取月   
		strMonth = attTime.Mid(2, 2);  
		//获取日期   
		strDay = attTime.Mid(4, 2); 
		//获取小时   
		strHour = attTime.Mid(6, 2);
		//获取分钟   
		strMinute = attTime.Mid(8, 2);  
		//获取秒   
		strSecond = attTime.Mid(10, 2);

		attDate.SetDateTime(atoi(strYear), 
							atoi(strMonth),
							atoi(strDay),
							atoi(strHour),
							atoi(strMinute),
							atoi(strSecond)); 
	}

	// set card attribute
	m_pCard->Init();
	m_pCard->SetCardSnuNum(strResult);
	m_pCard->SetCardTypeId(CCard::TYPE_MIFARE1);
	m_pCard->SetLastAttTime(attDate);
	m_pCard->SetExpriyDate(expriyDate);
	m_pCard->SetUserType(userType);
	if(abs(usingTimes0 - usingTimes1) >= 0xffff)
	{
		if(usingTimes0 == 0)
		{
			m_pCard->SetUsingTimes(usingTimes0);
			m_pCard->SetBalance(balance0);
			m_pCard->SetCurrBlockNum(0);
		}
		else
		{
			m_pCard->SetUsingTimes(usingTimes1);
			m_pCard->SetBalance(balance1);
			m_pCard->SetCurrBlockNum(1);
		}
	}
	else
	{
		if(usingTimes0 > usingTimes1)
		{
			m_pCard->SetUsingTimes(usingTimes0);
			m_pCard->SetBalance(balance0);
			m_pCard->SetCurrBlockNum(0);
		}
		else
		{
			m_pCard->SetUsingTimes(usingTimes1);
			m_pCard->SetBalance(balance1);
			m_pCard->SetCurrBlockNum(1);
		}
	}

#ifdef EN_DEBUG
	CString dbgStr = "GetCardID return=";
	dbgStr += strResult;
	m_pDbg->ShowDebug(dbgStr);
#endif
	return strResult.AllocSysString();
}

short CAttendanceCardCtrl::GetUserType() 
{
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("GetUserType");
#endif
	// TODO: Add your dispatch handler code here

	return m_pCard->GetUserType();
}

BSTR CAttendanceCardCtrl::GetBarcode() 
{
	CString strResult;
	// TODO: Add your dispatch handler code here

	return strResult.AllocSysString();
}

BOOL CAttendanceCardCtrl::InitBarcodeDev(short port) 
{
	// TODO: Add your dispatch handler code here

	return TRUE;
}

BOOL CAttendanceCardCtrl::BeepEx(short volume, short times) 
{
#ifdef EN_DEBUG
	m_pDbg->ShowDebug("BeepEx");
#endif
	// TODO: Add your dispatch handler code here
	unsigned char byte;
	m_pReader->SetBuzzer(volume, times, &byte);
	return TRUE;
}
