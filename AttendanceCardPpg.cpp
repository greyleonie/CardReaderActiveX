// AttendanceCardPpg.cpp : Implementation of the CAttendanceCardPropPage property page class.

#include "stdafx.h"
#include "AttendanceCard.h"
#include "AttendanceCardPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAttendanceCardPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAttendanceCardPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAttendanceCardPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAttendanceCardPropPage, "ATTENDANCECARD.AttendanceCardPropPage.1",
	0x1afd2be8, 0x535a, 0x450d, 0x9f, 0xcb, 0x45, 0xbc, 0x21, 0x2a, 0x8b, 0x20)


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardPropPage::CAttendanceCardPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CAttendanceCardPropPage

BOOL CAttendanceCardPropPage::CAttendanceCardPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_ATTENDANCECARD_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardPropPage::CAttendanceCardPropPage - Constructor

CAttendanceCardPropPage::CAttendanceCardPropPage() :
	COlePropertyPage(IDD, IDS_ATTENDANCECARD_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAttendanceCardPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT

	SetHelpInfo(_T("Names to appear in the control"), _T("ATTENDANCECARD.HLP"), 0);
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardPropPage::DoDataExchange - Moves data between page and properties

void CAttendanceCardPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CAttendanceCardPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardPropPage message handlers
