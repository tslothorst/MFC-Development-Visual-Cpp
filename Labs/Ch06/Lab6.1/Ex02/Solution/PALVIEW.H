#if !defined(PALVIEW_H__7F7767C9_365B_11D0_9C9D_00A0D100E3C8__INCLUDED_)
#define PALVIEW_H__7F7767C9_365B_11D0_9C9D_00A0D100E3C8__INCLUDED_

// PalView.h : main header file for PALVIEW.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPalViewApp : See PalView.cpp for implementation.

class CPalViewApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(PALVIEW_H__7F7767C9_365B_11D0_9C9D_00A0D100E3C8__INCLUDED)
