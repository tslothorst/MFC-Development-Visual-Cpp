// BitmapButtonView.h : interface of the CBitmapButtonView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPBUTTONVIEW_H__42FA06F1_8CE0_11D1_818D_00AA006C270F__INCLUDED_)
#define AFX_BITMAPBUTTONVIEW_H__42FA06F1_8CE0_11D1_818D_00AA006C270F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern CDialogBar m_wndDialogBar;

class CBitmapButtonView : public CEditView
{
protected: // create from serialization only
	CBitmapButtonView();
	DECLARE_DYNCREATE(CBitmapButtonView)

// Attributes
public:
	CBitmapButtonDoc* GetDocument();
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapButtonView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnTextNotFound(LPCTSTR lpszFind);

	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitmapButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CString m_text;
	//{{AFX_MSG(CBitmapButtonView)
	afx_msg void OnBnClicked();
	afx_msg void OnKillfocusCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BitmapButtonView.cpp
inline CBitmapButtonDoc* CBitmapButtonView::GetDocument()
   { return (CBitmapButtonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBUTTONVIEW_H__42FA06F1_8CE0_11D1_818D_00AA006C270F__INCLUDED_)
