// OLEEmployeeSet.h : interface of the COLEEmployeeSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEEMPLOYEESET_H__6BF9D1EF_DB61_11D1_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEEMPLOYEESET_H__6BF9D1EF_DB61_11D1_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEmployees
{
public:
	int m_EmployeeID;
	char m_Name[51];
	char m_Address[51];


BEGIN_COLUMN_MAP(CEmployees)
		COLUMN_ENTRY_TYPE(1, DBTYPE_I4, m_EmployeeID)
		COLUMN_ENTRY_TYPE(2, DBTYPE_STR, m_Name)
		COLUMN_ENTRY_TYPE(3, DBTYPE_STR, m_Address)
END_COLUMN_MAP()

};

class COLEEmployeeSet : public CCommand<CAccessor<CEmployees> >
{
public:
	CSession	session;
	HRESULT Open()
	{
		CDataSource db;
		
		HRESULT		hr;

		CDBPropSet	dbinit(DBPROPSET_DBINIT);
		dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, "Employees");
		dbinit.AddProperty(DBPROP_INIT_MODE, (long)3);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);

		hr = db.Open("MSDASQL.1", &dbinit);
		if (FAILED(hr))
			return hr;

		hr = session.Open(db);
		session.StartTransaction();
		if (FAILED(hr))
			return hr;

		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
		propset.AddProperty(DBPROP_IRowsetScroll, true);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE|DBPROPVAL_UP_DELETE|DBPROPVAL_UP_INSERT);

		hr = CCommand<CAccessor<CEmployees> >::Open(session, "SELECT * FROM Employees", &propset);
		if (FAILED(hr))
			return hr;

		return MoveNext();
	}

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEEMPLOYEESET_H__6BF9D1EF_DB61_11D1_8582_00AA006C20E3__INCLUDED_)

