// OLEEmployeeDoc.h : interface of the COLEEmployeeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEEMPLOYEEDOC_H__6BF9D1EB_DB61_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEEMPLOYEEDOC_H__6BF9D1EB_DB61_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OLEEmployeeSet.h"


class COLEEmployeeDoc : public CDocument
{
protected: // create from serialization only
	COLEEmployeeDoc();
	DECLARE_DYNCREATE(COLEEmployeeDoc)

// Attributes
public:
	COLEEmployeeSet m_oLEEmployeeSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEEmployeeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEEmployeeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEEmployeeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEEMPLOYEEDOC_H__6BF9D1EB_DB61_11D1_8582_00AA006C20E3__INCLUDED_)
