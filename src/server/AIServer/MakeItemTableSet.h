#pragma once

// MakeItemTableSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMakeItemTableSet recordset

class CMakeItemTableSet : public CRecordset {
  public:
    CMakeItemTableSet(CDatabase * pDatabase = NULL);
    DECLARE_DYNAMIC(CMakeItemTableSet)

    // Field/Param Data
    //{{AFX_FIELD(CMakeItemTableSet, CRecordset)
    int     m_sIndex;
    CString m_strItemInfo;
    int     m_sItemCode;
    //}}AFX_FIELD

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMakeItemTableSet)
  public:
    virtual CString GetDefaultConnect();                   // Default connection string
    virtual CString GetDefaultSQL();                       // Default SQL for Recordset
    virtual void    DoFieldExchange(CFieldExchange * pFX); // RFX support
                                                           //}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext & dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
