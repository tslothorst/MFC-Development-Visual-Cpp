#if !defined(PALVIEWCTL_H__7F7767D1_365B_11D0_9C9D_00A0D100E3C8__INCLUDED_)
#define PALVIEWCTL_H__7F7767D1_365B_11D0_9C9D_00A0D100E3C8__INCLUDED_

// PalViewCtl.h : Declaration of the CPalViewCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CPalViewCtrl : See PalViewCtl.cpp for implementation.

class CPalViewCtrl : public COleControl
{
	DECLARE_DYNCREATE(CPalViewCtrl)

// Constructor
public:
	CPalViewCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPalViewCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ExtractPalFromDIBFile(LPCTSTR lpszFileSpec);
	CDIBPal * m_pDibPal;
	~CPalViewCtrl();

	DECLARE_OLECREATE_EX(CPalViewCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CPalViewCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CPalViewCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CPalViewCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CPalViewCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CPalViewCtrl)
	CString m_dibFileName;
	afx_msg void OnDibFileNameChanged();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CPalViewCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CPalViewCtrl)
	dispidDibFileName = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(PALVIEWCTL_H__7F7767D1_365B_11D0_9C9D_00A0D100E3C8__INCLUDED)
