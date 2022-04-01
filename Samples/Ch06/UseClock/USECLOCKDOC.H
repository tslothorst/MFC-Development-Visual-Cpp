// UseClockDoc.h : interface of the CUseClockDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USECLOCKDOC_H__07B7DC40_57ED_11D0_98AB_444553540000__INCLUDED_)
#define AFX_USECLOCKDOC_H__07B7DC40_57ED_11D0_98AB_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CUseClockDoc : public CDocument
{
protected: // create from serialization only
	CUseClockDoc();
	DECLARE_DYNCREATE(CUseClockDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseClockDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseClockDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseClockDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USECLOCKDOC_H__07B7DC40_57ED_11D0_98AB_444553540000__INCLUDED_)
