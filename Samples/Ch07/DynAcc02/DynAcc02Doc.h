// DynAcc02Doc.h : interface of the CDynAcc02Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANACC01DOC_H__C1A311EB_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_MANACC01DOC_H__C1A311EB_C93E_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CDynAcc02Doc : public CDocument
{
protected: // create from serialization only
	CDynAcc02Doc();
	DECLARE_DYNCREATE(CDynAcc02Doc)

// Attributes
public:


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynAcc02Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDynAcc02Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDynAcc02Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANACC01DOC_H__C1A311EB_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
