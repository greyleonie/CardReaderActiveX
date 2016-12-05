#if !defined(AFX_ATTENDANCECARDCTL_H__6A9CE7BE_B7CA_45A1_98AC_7B45A21D346E__INCLUDED_)
#define AFX_ATTENDANCECARDCTL_H__6A9CE7BE_B7CA_45A1_98AC_7B45A21D346E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Read.h"
#include "Card.h"

#define	EN_DEBUG

#ifdef EN_DEBUG
#include "Debug.h"
#endif


// AttendanceCardCtl.h : Declaration of the CAttendanceCardCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CAttendanceCardCtrl : See AttendanceCardCtl.cpp for implementation.

class CAttendanceCardCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAttendanceCardCtrl)

// Constructor
public:
	CAttendanceCardCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAttendanceCardCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CAttendanceCardCtrl();

	BEGIN_OLEFACTORY(CAttendanceCardCtrl)        // Class factory and guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR FAR*);
	END_OLEFACTORY(CAttendanceCardCtrl)

	DECLARE_OLETYPELIB(CAttendanceCardCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAttendanceCardCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CAttendanceCardCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CAttendanceCardCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CAttendanceCardCtrl)
	afx_msg BOOL Init(short port);
	afx_msg void Quit();
	afx_msg short GetCardType();
	afx_msg BSTR ReadMainData(short Adr);
	afx_msg BOOL WriteMainData(short Adr, LPCTSTR Data);
	afx_msg BSTR ReadAttendanceData();
	afx_msg BOOL WriteAttendanceData(LPCTSTR Data);
	afx_msg double GetCurrentBalance();
	afx_msg long GetCurrentUsingTimes();
	afx_msg short Charge(short Money);
	afx_msg BOOL DispOnLED(double Money);
	afx_msg BOOL Beep(short Time);
	afx_msg DATE GetLastAttTime();
	afx_msg DATE GetExpiryDate();
	afx_msg void Halt();
	afx_msg BSTR GetLocalIp();
	afx_msg BSTR GetCardID();
	afx_msg short GetUserType();
	afx_msg BSTR GetBarcode();
	afx_msg BOOL InitBarcodeDev(short port);
	afx_msg BOOL BeepEx(short volume, short times);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CAttendanceCardCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CAttendanceCardCtrl)
	dispidInit = 1L,
	dispidQuit = 2L,
	dispidGetCardType = 3L,
	dispidReadMainData = 4L,
	dispidWriteMainData = 5L,
	dispidReadAttendanceData = 6L,
	dispidWriteAttendanceData = 7L,
	dispidGetCurrentBalance = 8L,
	dispidGetCurrentUsingTimes = 9L,
	dispidCharge = 10L,
	dispidDispOnLED = 11L,
	dispidBeep = 12L,
	dispidGetLastAttTime = 13L,
	dispidGetExpiryDate = 14L,
	dispidHalt = 15L,
	dispidGetLocalIp = 16L,
	dispidGetCardID = 17L,
	dispidGetUserType = 18L,
	dispidGetBarcode = 19L,
	dispidInitBarcodeDev = 20L,
	dispidBeepEx = 21L,
	//}}AFX_DISP_ID
	};
	void RawToHex(unsigned char *dst, const unsigned char *src, int srcLen);
	int HexToRaw(unsigned char *dst, const unsigned char *src, int srcLen);
private:
	CReader *m_pReader;
	CCard	*m_pCard;
#ifdef EN_DEBUG
	CDebug	*m_pDbg;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ATTENDANCECARDCTL_H__6A9CE7BE_B7CA_45A1_98AC_7B45A21D346E__INCLUDED)
