#include "stdafx.h"

#include "XtraFunc.h"

int RgbToInt(COLORREF c)
{
	switch(c)
	{
		case RED:
			return 1;
		case GREEN:
			return 2;
		case BLUE:
			return 3;
		default:
			return 0;
	}	
}

COLORREF IntToRgb(int r)
{
	switch(r)
	{
		case 1:
			return RED;
		case 2:
			return GREEN;
		case 3:
			return BLUE;
		default:
			return BLACK;
	}	
}
