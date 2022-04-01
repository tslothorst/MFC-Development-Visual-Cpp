#ifndef __DIBFILEPROPPAGE_H__
#define __DIBFILEPROPPAGE_H__

// DibFilePropPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDibFilePropPage : Property page dialog

class CDibFilePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CDibFilePropPage)
	DECLARE_OLECREATE_EX(CDibFilePropPage)

// Constructors
public:
	CDibFilePropPage();

// Dialog Data
	//{{AFX_DATA(CDibFilePropPage)
	enum { IDD = IDD_PROPPAGE_DIBFILE };
	CString	m_DibFileName;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CDibFilePropPage)
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // __DIBFILEPROPPAGE_H__
