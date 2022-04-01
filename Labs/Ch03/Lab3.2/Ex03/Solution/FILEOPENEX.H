#ifndef __FILEOPENEX_H__
#define __FILEOPENEX_H__

// FileOpenEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFileOpenEx dialog

class CFileOpenEx : public CFileDialog
{
// Construction
public:
	CFileOpenEx(LPCTSTR lpszDefExt = NULL,
				LPCTSTR lpszFileName = NULL,
				DWORD dwFlags = OFN_HIDEREADONLY,
				LPCTSTR lpszFilter = NULL,
				CWnd* pParentWnd = NULL);

// Dialog Data
	//{{AFX_DATA(CFileOpenEx)
	enum { IDD = IDD_FILEOPEN_EX };
		// NOTE: the ClassWizard will add data members here
	CRichEditCtrl m_RichEdit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOpenEx)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void PreviewContents(LPCSTR lpszFilespec);
	virtual void OnFileNameChange();
	// Generated message map functions
	//{{AFX_MSG(CFileOpenEx)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // __FILEOPENEX_H__
