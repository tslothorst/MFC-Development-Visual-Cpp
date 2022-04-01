// GrafView.h : interface of the CTemperatureGraphView class
//
/////////////////////////////////////////////////////////////////////////////

class CTemperatureGraphView : public CView
{
protected: // create from serialization only
	CTemperatureGraphView();
	DECLARE_DYNCREATE(CTemperatureGraphView)

// Attributes
public:
	CTemperatureGraphDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTemperatureGraphView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTemperatureGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void DrawAxes(CDC* pDC);
	void DrawGraph(CDC* pDC);
	void DrawHorizontalDecorations(CDC* pDC);
	void DrawVerticalDecorations(CDC* pDC);
	void SetMappingMode(CDC* pDC);

// Generated message map functions
protected:
	//{{AFX_MSG(CTemperatureGraphView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TemperatureGraphView.cpp
inline CTemperatureGraphDoc* CTemperatureGraphView::GetDocument()
   { return (CTemperatureGraphDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
