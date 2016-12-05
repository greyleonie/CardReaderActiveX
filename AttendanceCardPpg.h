#if !defined(AFX_ATTENDANCECARDPPG_H__D198B427_A9CD_4F51_BFE4_7404FE8F7F28__INCLUDED_)
#define AFX_ATTENDANCECARDPPG_H__D198B427_A9CD_4F51_BFE4_7404FE8F7F28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// AttendanceCardPpg.h : Declaration of the CAttendanceCardPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CAttendanceCardPropPage : See AttendanceCardPpg.cpp.cpp for implementation.

class CAttendanceCardPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAttendanceCardPropPage)
	DECLARE_OLECREATE_EX(CAttendanceCardPropPage)

// Constructor
public:
	CAttendanceCardPropPage();

// Dialog Data
	//{{AFX_DATA(CAttendanceCardPropPage)
	enum { IDD = IDD_PROPPAGE_ATTENDANCECARD };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CAttendanceCardPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTENDANCECARDPPG_H__D198B427_A9CD_4F51_BFE4_7404FE8F7F28__INCLUDED)
