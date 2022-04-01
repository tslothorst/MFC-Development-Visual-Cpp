// OledbAppSet.h : interface of the COledbAppSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OLEDBAPPSET_H__95BFF770_0C18_11D2_8582_00AA006C20E3__INCLUDED_)
#define AFX_OLEDBAPPSET_H__95BFF770_0C18_11D2_8582_00AA006C20E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEmployees
{
public:
	char m_Address[61];
	int m_EmployeeID;
	char m_FirstName[11];
	char m_HomePhone[25];
	char m_LastName[21];
	char m_Title[31];


BEGIN_COLUMN_MAP(CEmployees)
		COLUMN_ENTRY_TYPE(5, DBTYPE_STR, m_Address)
		COLUMN_ENTRY_TYPE(1, DBTYPE_I4, m_EmployeeID)
		COLUMN_ENTRY_TYPE(3, DBTYPE_STR, m_FirstName)
		COLUMN_ENTRY_TYPE(6, DBTYPE_STR, m_HomePhone)
		COLUMN_ENTRY_TYPE(2, DBTYPE_STR, m_LastName)
		COLUMN_ENTRY_TYPE(4, DBTYPE_STR, m_Title)
END_COLUMN_MAP()

};

class COledbAppSet : public CCommand<CAccessor<CEmployees> >
{
public:
	CSession	session;
	HRESULT Open()
	{
		CDataSource db;

		HRESULT		hr;

		CDBPropSet	dbinit(DBPROPSET_DBINIT);
		dbinit.AddProperty(DBPROP_AUTH_CACHE_AUTHINFO, true);
		dbinit.AddProperty(DBPROP_AUTH_ENCRYPT_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_MASK_PASSWORD, false);
		dbinit.AddProperty(DBPROP_AUTH_PASSWORD, "");
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_ENCRYPTED, false);
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
		dbinit.AddProperty(DBPROP_AUTH_USERID, "Admin");
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, ".\\Employees.mdb");
		dbinit.AddProperty(DBPROP_INIT_MODE, (long)16);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		dbinit.AddProperty(DBPROP_INIT_PROVIDERSTRING, ";COUNTRY=0;CP=1252;LANGID=0x0409");
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);

		hr = db.OpenWithServiceComponents("Microsoft.Jet.OLEDB.3.51", &dbinit);
		if (FAILED(hr))
			return hr;

		hr = session.Open(db);
		if (FAILED(hr))
			return hr;

		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
		propset.AddProperty(DBPROP_IRowsetScroll, true);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE|DBPROPVAL_UP_INSERT|DBPROPVAL_UP_DELETE);

		hr = CCommand<CAccessor<CEmployees> >::Open(session, "SELECT * FROM Employees", &propset);
		if (FAILED(hr))
			return hr;
		session.StartTransaction();
		return MoveNext();
	}

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLEDBAPPSET_H__95BFF770_0C18_11D2_8582_00AA006C20E3__INCLUDED_)

