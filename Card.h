#ifndef CARD_H
#define CARD_H

#define DEFAULT_KEY {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}
#define	OFFICAL_KEY {0x87, 0x31, 0x34, 0x73, 0x10, 0x47}
#define JIANGMEN_KEY {0xF8, 0xA1, 0xE6, 0xC2, 0xB9, 0xD7}
#define	USING_KEY	OFFICAL_KEY

class CCard
{
public:

	enum 
	{
		SECTOR_NUM_ATTENDANCE = 6,	//6
		SECTOR_NUM_BUSINESS = 7,	//7
		
		MODE_IDLE = 0x26,
		MODE_ALL = 0x52,

		HALT_OFF = 0x00,
		HALT_ON	= 0x01,

		MODE_IDLE_KEY_A = 0x00,
		MODE_ALL_KEY_A = 0x01,
		MODE_IDLE_KEY_B = 0x02,
		MODE_ALL_KEY_B = 0x03,

		TYPE_MIFARE1 = 1,				//M1卡
		TYPE_IDCARD	= 2				//二代身份证

	};

	CCard();
	~CCard();

	double	GetBalance();
	long	GetUsingTimes();
	short	GetCardTypeId();
	DATE	GetLastAttTime();
	DATE	GetExpriyDate();
	CString	GetCardSnrNum();
	short	GetCurrBlockNum();
	short	GetUserType();

	void	SetBalance(double balance);
	void	SetUsingTimes(long usingTimes);
	void	SetCardSnuNum(CString snrNum);
	void	SetCardTypeId(short type);
	void	SetCurrBlockNum(short blkNum);
	void	SetLastAttTime(DATE dateTime);
	void	SetExpriyDate(DATE dateTime);
	void	SetUserType(short type);

	void	Init();

private:
	CString	m_CardSnrNum;
	double	m_Balance;			//当前卡余额
	long	m_UsingTimes;		//当前卡使用次数
	short	m_CardTypeId;		//卡类型，MIFARE1表示M1卡，IDCARD表示二代身份证
	DATE	m_LastAttTime;
	DATE	m_ExpriyDate;
	short	m_CurrBlockNum;
	short	m_UserType;
};


#endif //CARD_H






