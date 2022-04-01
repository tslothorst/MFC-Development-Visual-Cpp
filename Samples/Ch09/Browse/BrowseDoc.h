// BrowseDoc.h : interface of the CBrowseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BROWSEDOC_H__72DE4D4B_9252_11D1_818D_00AA006C270F__INCLUDED_)
#define AFX_BROWSEDOC_H__72DE4D4B_9252_11D1_818D_00AA006C270F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBrowseDoc : public CDocument
{
protected: // create from serialization only
	CBrowseDoc();
	DECLARE_DYNCREATE(CBrowseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrowseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBrowseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBrowseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BROWSEDOC_H__72DE4D4B_9252_11D1_818D_00AA006C270F__INCLUDED_)
