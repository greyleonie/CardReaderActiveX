#include "stdafx.h"
#include "Read.h"
#include "mi.h"		

CReader::CReader()
{
	DeviceAddress = 0;

    m_hInstMaster = NULL;

	LoadDll();
	
}
CReader::~CReader()
{
	CloseDll();
}

int CReader::LoadDll()
{
	char buf[1024];
	GetCurrentDirectory(1024, buf);

	CString str;
	str.Format("%s", buf);
	m_hInstMaster = LoadLibrary(".\\function.dll");	
	if(!m_hInstMaster)
	{
		DWORD er = GetLastError();
		MessageBox(NULL, "调用读写器动态连接库(function.dll)失败!", "警  告", MB_OK | MB_ICONERROR);
		exit(0);
	}
	
//	(FARPROC &)API_OpenComm   = GetProcAddress(m_hInstMaster, _T("API_OpenComm"));
//	(FARPROC &)API_CloseComm  = GetProcAddress(m_hInstMaster, _T("API_CloseComm"));
	(FARPROC &)MF_Read        = GetProcAddress(m_hInstMaster, _T("MF_Read"));
	(FARPROC &)MF_Write       = GetProcAddress(m_hInstMaster, _T("MF_Write"));
	(FARPROC &)MF_InitValue   = GetProcAddress(m_hInstMaster, _T("MF_InitValue"));
	(FARPROC &)MF_Dec         = GetProcAddress(m_hInstMaster, _T("MF_Dec"));
	(FARPROC &)MF_Inc         = GetProcAddress(m_hInstMaster, _T("MF_Inc"));
//	(FARPROC &)RDM_GetSnr     = GetProcAddress(m_hInstMaster, _T("RDM_GetSnr"));
//	(FARPROC &)MF_Request     = GetProcAddress(m_hInstMaster, _T("MF_Request"));
//	(FARPROC &)MF_Anticoll    = GetProcAddress(m_hInstMaster, _T("MF_Anticoll"));
//	(FARPROC &)MF_Select      = GetProcAddress(m_hInstMaster, _T("MF_Select"));
	(FARPROC &)MF_Halt        = GetProcAddress(m_hInstMaster, _T("MF_Halt"));

//	(FARPROC &)MF_Restore           = GetProcAddress(m_hInstMaster, _T("MF_Restore"));
	(FARPROC &)ControlLED           = GetProcAddress(m_hInstMaster, _T("ControlLED"));
    (FARPROC &)ControlBuzzer        = GetProcAddress(m_hInstMaster, _T("ControlBuzzer"));
	(FARPROC &)MF_Getsnr            = GetProcAddress(m_hInstMaster, _T("MF_Getsnr"));
//	(FARPROC &)GetVersionNum        = GetProcAddress(m_hInstMaster, _T("GetVersionNum"));
//	(FARPROC &)API_SetDeviceAddress = GetProcAddress(m_hInstMaster, _T("API_SetDeviceAddress"));
    (FARPROC &)SetSerNum            = GetProcAddress(m_hInstMaster, _T("SetSerNum"));
	(FARPROC &)GetSerNum            = GetProcAddress(m_hInstMaster, _T("GetSerNum"));

	(FARPROC &)TypeB_Request        = GetProcAddress(m_hInstMaster, _T("TypeB_Request"));
    (FARPROC &)TYPEB_SFZSNR         = GetProcAddress(m_hInstMaster, _T("TYPEB_SFZSNR"));

    (FARPROC &)ISO15693_Inventory   = GetProcAddress(m_hInstMaster, _T("ISO15693_Inventory"));
    (FARPROC &)ISO15693_Read        = GetProcAddress(m_hInstMaster, _T("ISO15693_Read"));
	(FARPROC &)ISO15693_Write       = GetProcAddress(m_hInstMaster, _T("ISO15693_Write"));

    (FARPROC &)UL_Request           = GetProcAddress(m_hInstMaster, _T("UL_Request")); 
	(FARPROC &)UL_HLRead            = GetProcAddress(m_hInstMaster, _T("UL_HLRead")); 
    (FARPROC &)UL_HLWrite           = GetProcAddress(m_hInstMaster, _T("UL_HLWrite")); 
  
	/*
	if( API_OpenComm      == NULL || 
		API_CloseComm     == NULL ||
		MF_Read           == NULL ||
		MF_Write          == NULL ||
		API_PCDInitVal    == NULL ||
		API_PCDDec        == NULL ||
		API_PCDInc        == NULL ||
		RDM_GetSnr        == NULL ||
		MF_Request        == NULL ||
		MF_Anticoll       == NULL ||
		MF_Select         == NULL ||
		MF_Restore        == NULL ||
		MF_Getsnr           == NULL ||
		GetVersionNum     == NULL ||
		API_SetDeviceAddress  == NULL ||
		API_SetSerNum         == NULL ||
		API_GetSerNum         == NULL ||
		API_ControlBuzzer == NULL ||
		MF_Halt           == NULL )
		*/

	if(MF_Read == NULL || 
	   MF_Write == NULL ||
	   MF_InitValue == NULL ||
	   MF_Dec == NULL ||
	   MF_Inc == NULL ||
	   MF_Getsnr == NULL ||
	   SetSerNum == NULL ||
	   GetSerNum == NULL ||
       ControlLED == NULL ||
	   ControlBuzzer == NULL ||
	   TypeB_Request == NULL ||
	   TYPEB_SFZSNR == NULL ||
	   ISO15693_Inventory == NULL ||
	   ISO15693_Read == NULL ||
	   ISO15693_Write == NULL ||
	   UL_Request == NULL ||
	   MF_Halt == NULL ||
	   UL_HLRead == NULL ||
	   UL_HLWrite == NULL)
	{
		MessageBox(NULL, "调用读写器动态连接库的函数失败!", "警  告", MB_OK|MB_ICONERROR);
		exit(0);
		return 0;
	}
	
    return 1;
}

int CReader::CloseDll()
{
	if(m_hInstMaster)
	{
		FreeLibrary(m_hInstMaster);

		API_OpenComm      = NULL; 
		API_CloseComm     = NULL;
		MF_Read           = NULL;
		MF_Write          = NULL;
		MF_InitValue      = NULL;
		MF_Dec            = NULL;
		MF_Inc            = NULL;
		RDM_GetSnr        = NULL;
		MF_Request        = NULL;
		MF_Anticoll       = NULL;
		MF_Select         = NULL;
		MF_Restore        = NULL;
		MF_Getsnr         = NULL;
		ControlBuzzer     = NULL;
		MF_Halt           = NULL;

		TypeB_Request     = NULL;
        TYPEB_SFZSNR      = NULL;
		UL_Request        = NULL;
		UL_HLRead         = NULL;
		UL_HLWrite        = NULL;

		return 1;
	}

	return 0;
}

//int CReader::ReadBlock(int add, int mod, BYTE *pData, BYTE *pCode, int len)
//int CReader::ReadBlock(BYTE mode, BYTE blk_add, BYTE num_blk, BYTE *snr, BYTE *buffer)
int CReader::ReadBlock(int mode, int blk_add, int num_blk, BYTE *snr, BYTE *buffer)
{
	//BYTE buf[128];

	int result = 0;

	//memset(buf, 0, 128);

    //if((result = GetCardByteSerial(buf)) != 0x00)
	//	return result;

	//BYTE dataBuf[128];
    //memcpy(buf, pCode, 6);
	//memset(dataBuf, 0, 128);

	//BYTE buf[128];
    //memset(buf, 0, 128);
    //memcpy(buf,snr,6);

	//buffer = new BYTE[128];
    
	//memset(buffer,0,128);

	if((result = MF_Read(mode, blk_add, num_blk, snr, buffer)) != 0x00)
		return 6;

	//memcpy(pData, dataBuf, 16*len);

	return 0;
}

int CReader::WriteBlock(int mode, int blk_add, int num_blk, BYTE *pCode, BYTE *buffer)
{
	/*
    if(add<0 || add>64)
		return 10;
	if(add%4 == 3)
		return 11;
    */
	
	//BYTE buf[128];

	int result = 0;

	//memset(buf,0,128);
    //if((result = GetCardByteSerial(buf)) != 0x00)
	//	return result;

	//memset(buf,0x11,16);

    //BYTE buf[128];
    //memset(buf, 0, 128);
    //memcpy(buf, pCode, 6);

//	if((result = MF_Wrte(mod,add,len,pCode,pData)) != 0x00)
	if(result = MF_Write(mode, blk_add, num_blk, pCode, buffer) != 0x00)
		return 6;
	
	return 0;
}

int CReader::SetSnr(BYTE *pSnr, BYTE *buffer)
{
	if(!pSnr) 
		return 1;

	//int re = API_SetSerNum(hComm,DeviceAddress,pSnr,buf);
    int re = SetSerNum(pSnr, buffer);

	return re;
}

int CReader::GetSnr(BYTE * buf)
{

//	BYTE buf[128];
//	memset(buf,1,128);
	int re = 0;

	//if((re = API_GetSerNum(hComm,DeviceAddress,buf)) == 0)
    re = GetSerNum(buf);
	
		/*
		CString str;
		str.Format("%02x %02x %02x %02x %02x %02x %02x %02x",
			buf[1],buf[2],buf[3],
			buf[4],buf[5],buf[6],buf[7],buf[8]);
		*/

		//return str;
	//else
		//return "";

	return re;
}

int CReader::SetLED(int fre, int duration, BYTE *buffer)
{

	int re = 0;
    re = ControlLED(fre, duration, buffer);
	

	return re;
}

int CReader::SetBuzzer(int fre, int duration, BYTE *buffer)
{

    int re = 0;
	re = ControlBuzzer(fre, duration, buffer);
	
    return re;
}

int CReader::InitValue(int mode, int SectNum, BYTE *snr, BYTE *value)
{
	int re;
    re = MF_InitValue(mode, SectNum, snr, value); 

	return re;
}

int CReader::Dec(int mode, int SectNum, BYTE *snr, BYTE *value)
{ 
	int re;
	re = MF_Dec(mode, SectNum, snr, value);
    
	return re;
}

int CReader::Inc(int mode, int SectNum, BYTE *snr, BYTE *value)
{
	int re;
	re = MF_Inc(mode, SectNum, snr, value);

	return re;
}

int CReader::GetSnr(int mode, int halt, BYTE *snr, BYTE *value)
{
	int re;
	re = MF_Getsnr(mode, halt, snr, value);

	return re;
}

int CReader::TYPE_B_SFZSNR(int mode, int halt, BYTE *snr, BYTE *value)
{
	int re;
	//re = TYPEB_SFZSNR(buffer);
	re = TYPEB_SFZSNR(mode, halt, snr, value);
    
	return re;
}

int CReader::TypeB_to_Request(BYTE *buffer)
{
	int re;
    re = TypeB_Request(buffer);

	return re;
}

int CReader::Halt( )
{
	int re;
    re = MF_Halt();

	return re;
}

int CReader::ULRequest(int mode, BYTE *snr)
{
    int re = UL_Request(mode, snr); 

	return re;

}

int CReader::HLRead(int mode, int blk_add, BYTE *snr, BYTE *buffer)
{
	int re;
    re = UL_HLRead(mode, blk_add, snr, buffer);

	return re;
}

int CReader::HLWrite(int mode, int blk_add, BYTE *snr, BYTE *buffer)
{
	int re;
    re = UL_HLWrite(mode, blk_add, snr, buffer);

	return re;
}

int CReader::ISO_15693_Inventory(BYTE *CardNumber, BYTE *pBuffer)
{
    int re;

	re = ISO15693_Inventory(CardNumber, pBuffer);
    
	return re;
}

int CReader::ISO_15693_Read(int flags, int blk_add, int num_blk, BYTE *uid, BYTE *buffer)
{
    int re;

	re = ISO15693_Read(flags, blk_add, num_blk, uid, buffer);

	return re;
}

int CReader::ISO_15693_Write(int flags, int blk_add, int num_blk, BYTE *uid, BYTE *data)
{
	int re;

	re = ISO15693_Write(flags, blk_add, num_blk, uid, data);

	return re;
}