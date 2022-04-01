// OLEDBDynAccAppDoc.h : interface of the COLEDBDynAccAppDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBDYNACCAPPDOC_H__A800F22B_C961_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEDBDYNACCAPPDOC_H__A800F22B_C961_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COLEDBDynAccAppDoc : public CDocument
{
protected: // create from serialization only
	COLEDBDynAccAppDoc();
	DECLARE_DYNCREATE(COLEDBDynAccAppDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COLEDBDynAccAppDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COLEDBDynAccAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COLEDBDynAccAppDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBDYNACCAPPDOC_H__A800F22B_C961_11D1_8582_00AA006C20E3__INCLUDED_)
