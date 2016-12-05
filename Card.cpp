#include "stdafx.h"
#include "Card.h"

CCard::CCard()
{
	Init();
}

CCard::~CCard()
{
	;	
}

double	CCard::GetBalance()
{
	return this->m_Balance;
}

long	CCard::GetUsingTimes()
{
	return this->m_UsingTimes;
}

short	CCard::GetCardTypeId()
{
	return this->m_CardTypeId;
}

DATE	CCard::GetLastAttTime()
{
	return this->m_LastAttTime;
}

DATE	CCard::GetExpriyDate()
{
	return this->m_ExpriyDate;
}

CString	CCard::GetCardSnrNum()
{
	return this->m_CardSnrNum;
}

short CCard::GetCurrBlockNum()
{
	return this->m_CurrBlockNum;
}

short CCard::GetUserType()
{
	return m_UserType;
}


void CCard::SetCardSnuNum(CString snrNum)
{
	this->m_CardSnrNum = snrNum;
}

void CCard::SetUsingTimes(long usingTimes)
{
	this->m_UsingTimes = usingTimes;
}

void CCard::SetBalance(double balance)
{
	this->m_Balance = balance;
}

void CCard::SetCardTypeId(short type)
{
	this->m_CardTypeId = type;
}

void CCard::SetCurrBlockNum(short blkNum)
{
	this->m_CurrBlockNum = blkNum;
}

void CCard::SetLastAttTime(DATE dateTime)
{
	this->m_LastAttTime = dateTime;
}

void CCard::SetExpriyDate(DATE dateTime)
{
	this->m_ExpriyDate = dateTime;
}

void CCard::SetUserType(short type)
{
	this->m_UserType = type;
}

void CCard::Init()
{
	m_CardSnrNum = "";
	m_Balance = 0;			
	m_UsingTimes = 0;		
	m_CardTypeId = 0;		
	m_CurrBlockNum = 0;
	m_UserType = 0;

	COleDateTime date;
	m_LastAttTime = date;
	m_ExpriyDate = date;
}
//*/

