// AnmlData.cpp : implementation file
//

#include "stdafx.h"
#include "tree.h"
#include "AnmlData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnimalInfo

IMPLEMENT_SERIAL (CAnimalInfo, CObject, 1)

// A default ctor is necessary for a serializable class.
CAnimalInfo::CAnimalInfo()
{
}

// A 4 argument ctor is useful in this class.
CAnimalInfo::CAnimalInfo(CString arg_class, CString arg_type,
						CString arg_animal, int arg_weight)
	: m_class(arg_class), m_type(arg_type),	m_animal(arg_animal),
		m_weight(arg_weight)
{
}

// No dynamic allocation means the dtor has nothing to do.
CAnimalInfo::~CAnimalInfo()
{
}

void CAnimalInfo::Serialize(CArchive & ar)
{
	if ( ar.IsLoading() )
		ar >> m_class >> m_type >> m_animal >> m_weight;
    else
		ar << m_class << m_type << m_animal << m_weight;
}

// Since this class will be used in a CList, an overloaded assignment
// operator and a copy constructor are also necessary to make this
// class serializable. The comparison in = demands an overloaded ==.

CAnimalInfo & CAnimalInfo::operator = (const CAnimalInfo &cmd)
{
	// An overloaded = operator should always check
	// for the object being assigned to itself.
	if (cmd == *this)
		return *this;

	m_class = cmd.m_class;
	m_type = cmd.m_type;
	m_animal = cmd.m_animal;
	m_weight = cmd.m_weight;

	return * this;
}

CAnimalInfo::CAnimalInfo(const CAnimalInfo & cmd)
{
	m_class = cmd.m_class;
	m_type = cmd.m_type;
	m_animal = cmd.m_animal;
	m_weight = cmd.m_weight;
}

int CAnimalInfo::operator == (const CAnimalInfo &cmd) const
{
	if ( (m_class == cmd.m_class) &&
		 (m_type == cmd.m_type) &&
		 (m_animal == cmd.m_animal) &&
		 (m_weight == cmd.m_weight) )
		 return TRUE;
	else
		return FALSE;
}

