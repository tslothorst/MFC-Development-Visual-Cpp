// AnimalInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnimalInfo window

class CAnimalInfo : public CObject
{
public:
	CAnimalInfo();
	CAnimalInfo(CString, CString, CString, int);
	virtual ~CAnimalInfo();
	void Serialize(CArchive &);
	CAnimalInfo & operator = (const CAnimalInfo &);
	CAnimalInfo(const CAnimalInfo &);
	int operator == (const CAnimalInfo &) const;

	CString m_class;
	CString m_type;
	CString m_animal;
	int m_weight;

protected:
	DECLARE_SERIAL(CAnimalInfo)
};

/////////////////////////////////////////////////////////////////////////////
