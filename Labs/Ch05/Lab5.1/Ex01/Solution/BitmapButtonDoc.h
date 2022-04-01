// BitmapButtonDoc.h : interface of the CBitmapButtonDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPBUTTONDOC_H__42FA06EF_8CE0_11D1_818D_00AA006C270F__INCLUDED_)
#define AFX_BITMAPBUTTONDOC_H__42FA06EF_8CE0_11D1_818D_00AA006C270F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBitmapButtonDoc : public CDocument
{
protected: // create from serialization only
	CBitmapButtonDoc();
	DECLARE_DYNCREATE(CBitmapButtonDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapButtonDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitmapButtonDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapButtonDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBUTTONDOC_H__42FA06EF_8CE0_11D1_818D_00AA006C270F__INCLUDED_)
