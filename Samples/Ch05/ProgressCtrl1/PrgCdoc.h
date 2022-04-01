// PrgCDoc.h : interface of the CPrgCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#include "ProgressDlg.h"	// Added by ClassView
class CPrgCtrlDoc : public CRichEditDoc
{
protected: // create from serialization only
	CPrgCtrlDoc();
	DECLARE_DYNCREATE(CPrgCtrlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrgCtrlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// Implementation
public:
	virtual ~CPrgCtrlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void RunComparison(LPCSTR lpszFile1, LPCSTR lpszFile2);

protected:
	CString m_File1;
	CString m_File2;

// Generated message map functions
protected:
	CProgressCtrl *m_pProgCtrl;
	CProgressDlg *m_pProgDlg;
	//{{AFX_MSG(CPrgCtrlDoc)
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
