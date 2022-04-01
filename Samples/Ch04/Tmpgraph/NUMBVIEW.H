// NumbView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTemperatureNumbersView view

class CTemperatureNumbersView : public CView
{
protected:
	CTemperatureNumbersView();
	DECLARE_DYNCREATE(CTemperatureNumbersView)

// Attributes
public:
	CTemperatureGraphDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTemperatureNumbersView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTemperatureNumbersView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTemperatureNumbersView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TemperatureGraphNumbers.cpp
inline CTemperatureGraphDoc* CTemperatureNumbersView::GetDocument()
   { return (CTemperatureGraphDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
