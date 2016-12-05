#if !defined(AFX_ATTENDANCECARD_H__A38E387C_F5D4_4F6A_B268_C656CEEF592A__INCLUDED_)
#define AFX_ATTENDANCECARD_H__A38E387C_F5D4_4F6A_B268_C656CEEF592A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AttendanceCard.h : main header file for ATTENDANCECARD.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardApp : See AttendanceCard.cpp for implementation.

class CAttendanceCardApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTENDANCECARD_H__A38E387C_F5D4_4F6A_B268_C656CEEF592A__INCLUDED)
