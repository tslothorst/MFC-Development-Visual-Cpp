// ODmenus.h : header file

class CODmenus : public CMenu
{
// Construction
public:
	CODmenus();

// Operations
public:

// Implementation
public:
	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMIS);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	virtual ~CODmenus();
};
