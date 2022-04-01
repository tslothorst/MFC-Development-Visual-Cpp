// BitmapMenu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenu window

class CBitmapMenu : public CMenu
{
// Construction
public:
	CBitmapMenu();

// Attributes
public:

protected:
	CBitmap * m_pBitmaps;

// Operations
public:

// Implementation
public:
	virtual ~CBitmapMenu();
	void AppendBitmapMenuItem(UINT nID);

protected:
};

/////////////////////////////////////////////////////////////////////////////
