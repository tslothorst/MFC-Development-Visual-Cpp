// ManAcc01Doc.h : interface of the CManAcc01Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANACC01DOC_H__C1A311EB_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_MANACC01DOC_H__C1A311EB_C93E_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



class CManAcc01Doc : public CDocument
{
protected: // create from serialization only
	CManAcc01Doc();
	DECLARE_DYNCREATE(CManAcc01Doc)

// Attributes
public:


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManAcc01Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CManAcc01Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CManAcc01Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANACC01DOC_H__C1A311EB_C93E_11D1_8582_00AA006C20E3__INCLUDED_)
