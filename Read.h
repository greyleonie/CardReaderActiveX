#if !defined(AFX_Read_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_)
#define AFX_Read_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_

class CReader
{
    HINSTANCE m_hInstMaster;

public:
	int DeviceAddress;

	CReader();
	~CReader();

	int LoadDll();
	int CloseDll();

	//int OpenComm(int com,int bp);
	//int OpenComm(int bp);
	//int CloseComm();

	int SetDeviceAddress(int da);
	
	//HANDLE  GetHComm();
	//CString GetCardStrSerial();
	int GetSnr(BYTE *buf);
	int SetSnr(BYTE *pSnr, BYTE *buffer);

	int SetLED(int fre, int duration, BYTE *buffer);
	int SetBuzzer(int fre, int duration, BYTE *buffer);
	
	//int GetCardByteSerial(BYTE *pSerial);
	//int GetCardByteSerial1(BYTE *pSerial);

	//int ReadBLOCK(int add, BYTE *pData);
	//int ReadBlock(int add, int mod, BYTE *pData, BYTE *pCode, int len);
	//int ReadBlock(BYTE mode, BYTE blk_add, BYTE num_blk, BYTE *snr, BYTE *buffer);
    int ReadBlock(int mode, int blk_add, int num_blk, BYTE *snr, BYTE *buffer);

	//int ReadBLOCKWithCode(int add, BYTE *pData, BYTE *pCode);
	//int ReadWORD(int add, DWORD &revData);
	//int ReadBYTE(int add, BYTE  &revData);

	//int WriteBLOCK(BYTE add, BYTE *pData);
	//int WriteBlock(BYTE add, int mod, BYTE *pData, int len, BYTE *pCode);
    int WriteBlock(int mode, int blk_add, int num_blk, BYTE *pCode, BYTE *buffer);
	//int WriteWORD( int add, DWORD revData);
	//int WriteBYTE( int add, BYTE revData);

	//void Buzzer(int time, int count);
	int InitValue(int mode, int SectNum, BYTE *snr, BYTE *value);

	int Dec(int mode, int SectNum, BYTE *snr, BYTE *value);
 
	int Inc(int mode, int SectNum, BYTE *snr, BYTE *value);

	int GetSnr(int mode, int halt, BYTE *snr, BYTE *value);

	int TYPE_B_SFZSNR(int mode, int halt, BYTE *snr, BYTE *value);

	int TypeB_to_Request(BYTE *buffer);
   
    int Halt( );

	int ULRequest(int mode, BYTE *snr);

	int HLRead(int mode, int blk_add, BYTE *snr, BYTE *buffer);

	int HLWrite(int mode, int blk_add, BYTE *snr, BYTE *buffer);

	int ISO_15693_Inventory(BYTE *CardNumber, BYTE *pBuffer);

	int ISO_15693_Read(int flags, int blk_add, int num_blk, BYTE *uid, BYTE *buffer);

	int ISO_15693_Write(int flags, int blk_add, int num_blk, BYTE *uid, BYTE *data);
};

#endif // !defined(AFX_Read_H__4D8E026C_6490_49EE_B102_4885B7AABF1F__INCLUDED_)