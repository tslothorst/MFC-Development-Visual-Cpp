// ClockPpg.h : Declaration of the CClockPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CClockPropPage : See ClockPpg.cpp.cpp for implementation.

class CClockPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CClockPropPage)
	DECLARE_OLECREATE_EX(CClockPropPage)

// Constructor
public:
	CClockPropPage();

// Dialog Data
	//{{AFX_DATA(CClockPropPage)
	enum { IDD = IDD_PROPPAGE_CLOCK };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CClockPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
