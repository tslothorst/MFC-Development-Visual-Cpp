// ComboExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComboEx.h"
#include "ComboExDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComboExDlg dialog
const COLORREF BLACK=RGB(0,0,0);
const COLORREF RED=RGB(255,0,0);
const COLORREF YELLOW=RGB(255,255,0);
const COLORREF BLUE=RGB(0,0,255);

CComboExDlg::CComboExDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboExDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComboExDlg)
		
	//}}AFX_DATA_INIT
}


void CComboExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComboExDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComboExDlg, CDialog)
	//{{AFX_MSG_MAP(CComboExDlg)
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX, OnSelchangeComboboxex)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboExDlg message handlers

BOOL CComboExDlg::OnInitDialog() 
{
	CComboBoxEx *pCComboBoxEx;
	COLORREF m_cref=RGB(0,0,0);

	pCComboBoxEx=(CComboBoxEx*)GetDlgItem(IDC_COMBOBOXEX1);

	m_Bitmap1.LoadBitmap(IDB_BITMAP1);
	m_Bitmap2.LoadBitmap(IDB_BITMAP2);
	m_Bitmap3.LoadBitmap(IDB_BITMAP3);
	m_Bitmap4.LoadBitmap(IDB_BITMAP4);
	m_Bitmap5.LoadBitmap(IDB_BITMAP5);
	m_Bitmap6.LoadBitmap(IDB_BITMAP6);
	m_Bitmap7.LoadBitmap(IDB_BITMAP7);
	m_Bitmap8.LoadBitmap(IDB_BITMAP8);
	m_Bitmap9.LoadBitmap(IDB_BITMAP9);
	m_ImageList.Create(32,32,ILC_COLOR,9,10);
	m_ImageList.Add(&m_Bitmap1,m_cref);
	m_ImageList.Add(&m_Bitmap2,m_cref);
	m_ImageList.Add(&m_Bitmap3,m_cref);
	m_ImageList.Add(&m_Bitmap4,m_cref);
	m_ImageList.Add(&m_Bitmap5,m_cref);
	m_ImageList.Add(&m_Bitmap6,m_cref);
	m_ImageList.Add(&m_Bitmap7,m_cref);
	m_ImageList.Add(&m_Bitmap8,m_cref);
	m_ImageList.Add(&m_Bitmap9,m_cref);
	pCComboBoxEx->SetImageList(&m_ImageList);


	
	COMBOBOXEXITEM     cbi;
	CString            str;
	int                nItem;
	//First
	cbi.mask = CBEIF_IMAGE | CBEIF_INDENT | CBEIF_OVERLAY |
     CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
	cbi.iItem = 0;
	str.Format("Red");
	cbi.pszText = (LPTSTR)(LPCTSTR)str;
	cbi.cchTextMax = str.GetLength();
	cbi.iImage = 0;
	cbi.iSelectedImage = 1;
	cbi.iOverlay = 2;
	cbi.iIndent = (0 & 0x03);   
	//Set indentation according to item position
	nItem = pCComboBoxEx->InsertItem(&cbi);
	ASSERT(nItem == 0);

	//Second
	cbi.mask = CBEIF_IMAGE | CBEIF_INDENT | CBEIF_OVERLAY |
     CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
	cbi.iItem = 1;
	str.Format("Yellow");
	cbi.pszText = (LPTSTR)(LPCTSTR)str;
	cbi.cchTextMax = str.GetLength();
	cbi.iImage = 4;
	cbi.iSelectedImage = 5;
	cbi.iOverlay = 6;
	cbi.iIndent = (0 & 0x03);   
	//Set indentation according to item position
	nItem = pCComboBoxEx->InsertItem(&cbi);
	ASSERT(nItem == 1);

	//Third
	cbi.mask = CBEIF_IMAGE | CBEIF_INDENT | CBEIF_OVERLAY |
     CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
	cbi.iItem = 2;
	str.Format("Blue");
	cbi.pszText = (LPTSTR)(LPCTSTR)str;
	cbi.cchTextMax = str.GetLength();
	cbi.iImage = 7;
	cbi.iSelectedImage = 8;
	cbi.iOverlay = 9;
	cbi.iIndent = (0 & 0x03);   
	//Set indentation according to item position
	nItem = pCComboBoxEx->InsertItem(&cbi);
	ASSERT(nItem == 2);
	
	//*****

	pCComboBoxEx->SetWindowPos(this , 10,10, 100, 60, SWP_SHOWWINDOW);
	CDialog::OnInitDialog();
	
	

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CComboExDlg::OnSelchangeComboboxex() 
{
	int nSel;
	CComboBoxEx *pCComboBoxEx;
	pCComboBoxEx=(CComboBoxEx*)GetDlgItem(IDC_COMBOBOXEX1);
	nSel = pCComboBoxEx->GetCurSel();	
	switch (nSel)
	{
		case 0:	m_Color =  RED;
				break;
		case 1:	m_Color =  YELLOW;		
			    break;
		case 2:	m_Color =  BLUE;
				break;
		default:m_Color =  BLACK;		
	}
}
