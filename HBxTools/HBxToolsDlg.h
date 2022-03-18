// HBxToolsDlg.h : header file
//

#pragma once


// CHBxToolsDlg dialog
class CHBxToolsDlg : public CDialog
{
// Construction
public:
	CHBxToolsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_HBXTOOLS_DIALOG };
	CComboBox	m_combo1;
	CComboBox	m_combo2;
	CComboBox	m_combo3;
	CComboBox	m_combo4;
	CComboBox	m_combo5;
	CString		m_edit1;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnCbnSelchangeComboboxex1();
	afx_msg void OnCbnDropdownCombo3();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};
