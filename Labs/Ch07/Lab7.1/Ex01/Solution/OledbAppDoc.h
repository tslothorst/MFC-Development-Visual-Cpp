// OledbAppDoc.h : interface of the COledbAppDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBAPPDOC_H__95BFF76C_0C18_11D2_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEDBAPPDOC_H__95BFF76C_0C18_11D2_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OledbAppSet.h"


class COledbAppDoc : public CDocument
{
protected: // create from serialization only
	COledbAppDoc();
	DECLARE_DYNCREATE(COledbAppDoc)

// Attributes
public:
	COledbAppSet m_oledbAppSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COledbAppDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COledbAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COledbAppDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBAPPDOC_H__95BFF76C_0C18_11D2_8582_00AA006C20E3__INCLUDED_)
