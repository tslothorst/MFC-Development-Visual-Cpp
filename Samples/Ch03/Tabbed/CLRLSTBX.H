// ColorListBox.h : header file
//

class CColorListBox : public CListBox
{
// Construction
public:
	CColorListBox();
	virtual ~CColorListBox();

// Attributes
public:

// Operations
public:

// Implementation
public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMIS);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
};
