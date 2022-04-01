#if !defined(PALVIEWPPG_H__7F7767D3_365B_11D0_9C9D_00A0D100E3C8__INCLUDED_)
#define PALVIEWPPG_H__7F7767D3_365B_11D0_9C9D_00A0D100E3C8__INCLUDED_

// PalViewPpg.h : Declaration of the CPalViewPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CPalViewPropPage : See PalViewPpg.cpp.cpp for implementation.

class CPalViewPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CPalViewPropPage)
	DECLARE_OLECREATE_EX(CPalViewPropPage)

// Constructor
public:
	CPalViewPropPage();

// Dialog Data
	//{{AFX_DATA(CPalViewPropPage)
	enum { IDD = IDD_PROPPAGE_PALVIEW };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CPalViewPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(PALVIEWPPG_H__7F7767D3_365B_11D0_9C9D_00A0D100E3C8__INCLUDED)
