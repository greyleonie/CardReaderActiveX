#include "stdafx.h"
#include "Debug.h"

CDebug::CDebug(CString dbgFileName)
{
	m_pDbgStream = NULL;
	m_pDbgStream = new ofstream(dbgFileName);
}

CDebug::~CDebug()
{
	m_pDbgStream->close();
}

void CDebug::ShowDebug(CString info)
{
	CTime time = CTime::GetCurrentTime();
	*m_pDbgStream << time.Format("%Y/%m/%d %H:%M:%S ") << info << endl;
}