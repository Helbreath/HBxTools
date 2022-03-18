// HBxToolsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HBxTools.h"
#include "HBxToolsDlg.h"
#include ".\hbxtoolsdlg.h"
#include <shlobj.h>
#include <shellapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
extern dlg;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
END_MESSAGE_MAP()


// CHBxToolsDlg dialog



CHBxToolsDlg::CHBxToolsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHBxToolsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_XICON);
}

void CHBxToolsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_COMBO4, m_combo4);
	DDX_Control(pDX, IDC_COMBO5, m_combo5);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
}

BEGIN_MESSAGE_MAP(CHBxToolsDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
END_MESSAGE_MAP()


// CHBxToolsDlg message handlers

BOOL CHBxToolsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_combo1.SetCurSel(0);
	m_combo2.SetCurSel(0);
	m_combo3.SetCurSel(0);
	m_combo4.EnableWindow(FALSE);
	m_combo5.EnableWindow(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHBxToolsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHBxToolsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHBxToolsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CHBxToolsDlg::OnCbnSelchangeCombo3()
{
	// TODO: Add your control notification handler code here
}

void CHBxToolsDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);


	DWORD	dwUpgrade = 0x10000000;
	//STEP ONE \/
	DWORD	Agile	=	0x00500000;
	DWORD	Light	=	0x00600000;
	DWORD	Strong	=	0x00800000;
	DWORD	Poison	=	0x00200000;
	DWORD	Critical=	0x00100000;
	DWORD	Sharp	=	0x00700000;
	DWORD	Righteous=	0x00300000;
	DWORD	Ancient	=	0x00900000;
	DWORD	Special	=	0x00A00000;
	DWORD	Mana	=	0x00B00000;
	DWORD	CIC		=	0x00C00000;
	DWORD	Step 	=	0x00010000;
	//STEP TWO \/
	DWORD	PoisonResist=	0x1000;
	DWORD	HitProb		=	0x2000;
	DWORD	DefProb		=	0x3000;
	DWORD	HPRecov		=	0x4000;
	DWORD	SPRecov		=	0x5000;
	DWORD	MPRecov		=	0x6000;
	DWORD	MagicResist	=	0x7000;
	DWORD	PhysAbsorpt	=	0x8000;
	DWORD	MagAbsorpt	=	0x9000;
	DWORD	REP			=	0xA000;
	DWORD	EXP			=	0xB000;
	DWORD	GOLD		=	0xC000;
	DWORD	Step2 		=	0x0100;

	//char celohel[90];
	//ZeroMemory(celohel, 90);
	////wsprintf(celohel, "%d", (0x3066EC00 & 0x0000F000) >> 12);//812051456

	//short sStep1 = (0x3066EC00 & 0x00F00000) >> 20;
	//short sStep2 = (0x3066EC00 & 0x0000F000) >> 12;
	//short sStep3 = (0x3066EC00 & Step) >> 16;
	//short sStep4 = (0x3066EC00 & Step2) >> 8;


	//short up = (0x90000000 & 0xF0000000) >> 28;

	if (((((DWORD)atoi(m_edit1)) & 0x00F00000) >> 20) < 4)
		m_combo2.SetCurSel(((((DWORD)atoi(m_edit1)) & 0x00F00000) >> 20));
	else
		m_combo2.SetCurSel(((((DWORD)atoi(m_edit1)) & 0x00F00000) >> 20) - 1);

	m_combo1.SetCurSel((((DWORD)atoi(m_edit1)) & 0x0000F000) >> 12);
	OnCbnSelchangeCombo1();
	OnCbnSelchangeCombo2();
	//Sleep(100);
	m_combo4.SetCurSel(((((DWORD)atoi(m_edit1)) & 0x000F0000) >> 16) - 1);
	m_combo5.SetCurSel(((((DWORD)atoi(m_edit1)) & 0x00000F00) >> 8) - 1);
	
	m_combo3.SetCurSel((((DWORD)atoi(m_edit1)) & 0xF0000000) >> 28);

	switch (((((DWORD)atoi(m_edit1)) & 0x00F00000) >> 20))
	{
	case 0:
	case 3:
	case 5:
	case 7:
	case 9:
		m_combo4.EnableWindow(FALSE);
		break;
	default:
		m_combo4.EnableWindow(TRUE);
		break;
	}
	if (((((DWORD)atoi(m_edit1)) & 0x0000F000) >> 12) > 0)
		m_combo5.EnableWindow(TRUE);
	else
		m_combo5.EnableWindow(FALSE);



	//wsprintf(celohel, "Step 1 %d : %d%% - Step 2 %d : %d%%", sStep1, sStep3, sStep2, sStep3);
	//wsprintf(celohel, "+%d", (((DWORD)atoi(m_edit1)) & 0xF00000) >> 24);

	//::MessageBox(m_hWnd, celohel, celohel, MB_ICONEXCLAMATION | MB_OK);
}

void CHBxToolsDlg::OnCbnSelchangeComboboxex1()
{
	// TODO: Add your control notification handler code here
}
void CHBxToolsDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here

	//num =  m_combo5.GetCount();

	m_combo5.ResetContent();


	switch(m_combo1.GetCurSel()) {
		case 0:
			m_combo5.EnableWindow(FALSE);
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			m_combo5.EnableWindow(TRUE);
			m_combo5.AddString("+7%");
			m_combo5.AddString("+14%");
			m_combo5.AddString("+21%");
			m_combo5.AddString("+28%");
			m_combo5.AddString("+35%");
			m_combo5.AddString("+42%");
			m_combo5.AddString("+49%");
			m_combo5.AddString("+56%");
			m_combo5.AddString("+63%");
			m_combo5.AddString("+70%");
			m_combo5.AddString("+77%");
			m_combo5.AddString("+84%");
			m_combo5.AddString("+91%");
			m_combo5.AddString("+98%");
			m_combo5.AddString("+105%");
			m_combo5.SetCurSel(0);
			break;
		case 8:
		case 9:
			m_combo5.EnableWindow(TRUE);
			m_combo5.AddString("+3%");
			m_combo5.AddString("+6%");
			m_combo5.AddString("+9%");
			m_combo5.AddString("+12%");
			m_combo5.AddString("+15%");
			m_combo5.AddString("+18%");
			m_combo5.AddString("+21%");
			m_combo5.AddString("+24%");
			m_combo5.AddString("+27%");
			m_combo5.AddString("+30%");
			m_combo5.AddString("+33%");
			m_combo5.AddString("+36%");
			m_combo5.AddString("+39%");
			m_combo5.AddString("+42%");
			m_combo5.AddString("+45%");
			m_combo5.SetCurSel(0);
			break;
		case 10:
			m_combo5.EnableWindow(TRUE);
			m_combo5.AddString("+1");
			m_combo5.AddString("+2");
			m_combo5.AddString("+3");
			m_combo5.AddString("+4");
			m_combo5.AddString("+5");
			m_combo5.AddString("+6");
			m_combo5.AddString("+7");
			m_combo5.AddString("+8");
			m_combo5.AddString("+9");
			m_combo5.AddString("+10");
			m_combo5.AddString("+11");
			m_combo5.AddString("+12");
			m_combo5.AddString("+13");
			m_combo5.AddString("+14");
			m_combo5.AddString("+15");
			m_combo5.SetCurSel(0);
			break;
		case 11:
		case 12:
			m_combo5.EnableWindow(TRUE);
			m_combo5.AddString("+10%");
			m_combo5.AddString("+20%");
			m_combo5.AddString("+30%");
			m_combo5.AddString("+40%");
			m_combo5.AddString("+50%");
			m_combo5.AddString("+60%");
			m_combo5.AddString("+70%");
			m_combo5.AddString("+80%");
			m_combo5.AddString("+90%");
			m_combo5.AddString("+100%");
			m_combo5.AddString("+110%");
			m_combo5.AddString("+120%");
			m_combo5.AddString("+130%");
			m_combo5.AddString("+140%");
			m_combo5.AddString("+150%");
			m_combo5.SetCurSel(0);
			break;
		default:
			break;


	}
	UpdateData(FALSE);
}

void CHBxToolsDlg::OnCbnSelchangeCombo2()
{
	// TODO: Add your control notification handler code here
	int num;
	//char micadena[30];

	num =  m_combo2.GetCount();
	//m_combo2.GetLBText(num, micadena); 

	//for (i = 0; i <= num; i++)
	m_combo4.ResetContent();


	switch(m_combo2.GetCurSel()) {
		case 0:
		case 3:
		case 4:
		case 6:
		case 8:
			m_combo4.EnableWindow(FALSE);
			break;
		case 1:
			m_combo4.EnableWindow(TRUE);
			m_combo4.AddString("+1");
			m_combo4.AddString("+2");
			m_combo4.AddString("+3");
			m_combo4.AddString("+4");
			m_combo4.AddString("+5");
			m_combo4.AddString("+6");
			m_combo4.AddString("+7");
			m_combo4.AddString("+8");
			m_combo4.AddString("+9");
			m_combo4.AddString("+10");
			m_combo4.AddString("+11");
			m_combo4.AddString("+12");
			m_combo4.AddString("+13");
			m_combo4.AddString("+14");
			m_combo4.AddString("+15");
			m_combo4.SetCurSel(0);
			break;
		case 10:
		case 11:
			m_combo4.EnableWindow(TRUE);
			m_combo4.AddString("+1%");
			m_combo4.AddString("+2%");
			m_combo4.AddString("+3%");
			m_combo4.AddString("+4%");
			m_combo4.AddString("+5%");
			m_combo4.AddString("+6%");
			m_combo4.AddString("+7%");
			m_combo4.AddString("+8%");
			m_combo4.AddString("+9%");
			m_combo4.AddString("+10%");
			m_combo4.AddString("+11%");
			m_combo4.AddString("+12%");
			m_combo4.AddString("+13%");
			m_combo4.AddString("+14%");
			m_combo4.AddString("+15%");
			m_combo4.SetCurSel(0);
			break;
		case 2:
			m_combo4.EnableWindow(TRUE);
			m_combo4.AddString("+5");
			m_combo4.AddString("+10");
			m_combo4.AddString("+15");
			m_combo4.AddString("+20");
			m_combo4.AddString("+25");
			m_combo4.AddString("+30");
			m_combo4.AddString("+35");
			m_combo4.AddString("+40");
			m_combo4.AddString("+45");
			m_combo4.AddString("+50");
			m_combo4.AddString("+55");
			m_combo4.AddString("+60");
			m_combo4.AddString("+65");
			m_combo4.AddString("+70");
			m_combo4.AddString("+75");
			m_combo4.SetCurSel(0);
			break;
		case 5:
			m_combo4.EnableWindow(TRUE);
			m_combo4.AddString("+5%");
			m_combo4.AddString("+8%");
			m_combo4.AddString("+12%");
			m_combo4.AddString("+16%");
			m_combo4.AddString("+20%");
			m_combo4.AddString("+24%");
			m_combo4.AddString("+28%");
			m_combo4.AddString("+32%");
			m_combo4.AddString("+36%");
			m_combo4.AddString("+40%");
			m_combo4.AddString("+44%");
			m_combo4.AddString("+48%");
			m_combo4.AddString("+52%");
			m_combo4.AddString("+56%");
			m_combo4.AddString("+60%");
			m_combo4.SetCurSel(0);
			break;
		case 7:
			m_combo4.EnableWindow(TRUE);
			m_combo4.AddString("+7%");
			m_combo4.AddString("+14%");
			m_combo4.AddString("+21%");
			m_combo4.AddString("+28%");
			m_combo4.AddString("+35%");
			m_combo4.AddString("+42%");
			m_combo4.AddString("+49%");
			m_combo4.AddString("+56%");
			m_combo4.AddString("+63%");
			m_combo4.AddString("+70%");
			m_combo4.AddString("+77%");
			m_combo4.AddString("+84%");
			m_combo4.AddString("+91%");
			m_combo4.AddString("+98%");
			m_combo4.AddString("+105%");
			m_combo4.SetCurSel(0);
			break;
		case 9:
			m_combo4.EnableWindow(TRUE);
			m_combo4.AddString("+3%");
			m_combo4.AddString("+6%");
			m_combo4.AddString("+9%");
			m_combo4.AddString("+12%");
			m_combo4.AddString("+15%");
			m_combo4.AddString("+18%");
			m_combo4.AddString("+21%");
			m_combo4.AddString("+24%");
			m_combo4.AddString("+27%");
			m_combo4.AddString("+30%");
			m_combo4.AddString("+33%");
			m_combo4.AddString("+36%");
			m_combo4.AddString("+39%");
			m_combo4.AddString("+42%");
			m_combo4.AddString("+45%");
			m_combo4.SetCurSel(0);
			break;
		default:
			break;
	}
	UpdateData(FALSE);
}

void CHBxToolsDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	// Attributes Syntax: 0x00F00000

/*
	if ((m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwAttribute & 0x0000F000) != NULL) {
		dwSWEType  = (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwAttribute & 0x0000F000) >> 12;  
		dwSWEValue = (m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_dwAttribute & 0x00000F00) >> 8;
	switch (dwSWEType) {
				case 0:  break;
				case 1:  m_pClientList[iClientH]->m_iAddPR += (int)dwSWEValue*7; break;
				case 2:  m_pClientList[iClientH]->m_iAddAR += (int)dwSWEValue*7; break;
				case 3:  m_pClientList[iClientH]->m_iAddDR += (int)dwSWEValue*7; break;
				case 4:  m_pClientList[iClientH]->m_iAddHP += (int)dwSWEValue*7; break;
				case 5:  m_pClientList[iClientH]->m_iAddSP += (int)dwSWEValue*7; break;
				case 6:  m_pClientList[iClientH]->m_iAddMP += (int)dwSWEValue*7; break;
				case 7:  m_pClientList[iClientH]->m_iAddMR += (int)dwSWEValue*7; break;
				case 8:  m_pClientList[iClientH]->m_iDamageAbsorption_Armor[m_pClientList[iClientH]->m_pItemList[sItemIndex]->m_cEquipPos] += (int)dwSWEValue*3; break;
				case 9:  m_pClientList[iClientH]->m_iAddAbsMD += (int)dwSWEValue*3; break;
				case 10: m_pClientList[iClientH]->m_iAddCD    += (int)dwSWEValue; break;
				case 11: m_pClientList[iClientH]->m_iAddExp   += (int)dwSWEValue*10; break;
				case 12: m_pClientList[iClientH]->m_iAddGold  += (int)dwSWEValue*10; break;
	}
*/
/* MANU
dwTemp = pItem->m_dwAttribute;
dwTemp = dwTemp & 0xFFFFFFFE;
dwTemp = dwTemp | 0x00000001;
pItem->m_dwAttribute = dwTemp;
*/


	/* cColor - Weapons
	1 = grey (light/strong)	- dwType = 5 - Hex : 50 0000 - Binary : 0101 0000 0000 0000 0000 0000
	2 = grey (light/strong)	- dwType = 6 - Hex : 60 0000 - Binary : 0110 0000 0000 0000 0000 0000
	3 = light blue (agile)	- dwType = 8 - Hex : 80 0000 - Binary : 1000 0000 0000 0000 0000 0000
	4 = green (psn)			- dwType = 2 - Hex : 20 0000 - Binary : 0010 0000 0000 0000 0000 0000
	5 = gold (crit)			- dwType = 1 - Hex : 10 0000 - Binary : 0001 0000 0000 0000 0000 0000
	6 = blue (sharp)		- dwType = 7 - Hex : 70 0000 - Binary : 0111 0000 0000 0000 0000 0000
	7 = white (right)		- dwType = 3 - Hex : 30 0000 - Binary : 0011 0000 0000 0000 0000 0000
	8 = purple (ancient)	- dwType = 9 - Hex : 90 0000 - Binary : 1001 0000 0000 0000 0000 0000
	9 = crimson				- dwType = ?
	*/

/* Second Stats
2 = HitProb					- dwValue = 3 - Hex : 3 0000 - Binary : 0000 0011 0000 0000 0000 0000
10 = REP					- dwValue = 7 - Hex : 7 0000 - Binary : 0000 0111 0000 0000 0000 0000
11 = EXP					- dwValue = 2 - Hex : 2 0000 - Binary : 0000 0010 0000 0000 0000 0000
12 = Gold					- dwValue = 5 - Hex : 5 0000 - Binary : 0000 0101 0000 0000 0000 0000
*/

/*
Test Values
Poison
dwType = 2
dwValue = 10
dwType			0000 0000 0010 0000 0000 0000 0000 0000
dwValue			0000 0000 0000 1010 0000 0000 0000 0000
m_dwAttribute	0000 0000 0000 0000 0000 0000 0000 0000
pItem->m_dwAttribute = pItem->m_dwAttribute | dwType | dwValue;
0000 0000 0010 1010 0000 0000 0000 0000

EXP
dwType = 11
dwValue = 6
dwType			0000 0000 0000 0000 1011 0000 0000 0000
dwValue			0000 0000 0000 0000 0000 0110 0000 0000
m_dwAttribute	0000 0000 0010 1010 0000 0000 0000 0000
pItem->m_dwAttribute = pItem->m_dwAttribute | dwType | dwValue;
*/
	// Nothing: 4456702
	DWORD	dwFinal = 0;
	DWORD	snum = 0;
	DWORD	dwnum = 0;
	int		cursel = 0;
	DWORD	cursell = 0;
	DWORD	dwUpgrade = 0x10000000;
	DWORD	dwGreen =	0x00400000;
	//STEP ONE \/
	DWORD	Agile	=	0x00500000;
	DWORD	Light	=	0x00600000;
	DWORD	Strong	=	0x00800000;
	DWORD	Poison	=	0x00200000;
	DWORD	Critical=	0x00100000;
	DWORD	Sharp	=	0x00700000;
	DWORD	Righteous=	0x00300000;
	DWORD	Ancient	=	0x00900000;
	DWORD	Special	=	0x00A00000;
	DWORD	Mana	=	0x00B00000;
	DWORD	CIC		=	0x00C00000;
	DWORD	Step 	=	0x00010000;
	//STEP TWO \/
	DWORD	PoisonResist=	0x1000;
	DWORD	HitProb		=	0x2000;
	DWORD	DefProb		=	0x3000;
	DWORD	HPRecov		=	0x4000;
	DWORD	SPRecov		=	0x5000;
	DWORD	MPRecov		=	0x6000;
	DWORD	MagicResist	=	0x7000;
	DWORD	PhysAbsorpt	=	0x8000;
	DWORD	MagAbsorpt	=	0x9000;
	DWORD	REP			=	0xA000;
	DWORD	EXP			=	0xB000;
	DWORD	GOLD		=	0xC000;
	DWORD	Step2 		=	0x0100;


	char	*cp = NULL;
	char	*cp2 = NULL;
	int		*ip = NULL;
	DWORD	*dwp2 = NULL;
	char cTxt[30];
	char xTxt[30];
	ZeroMemory(cTxt, 30);
	ZeroMemory(xTxt, 30);

	snum =  m_combo3.GetCurSel();
	m_combo3.GetLBText(snum, cTxt);
	cp = cTxt;
	cp++;

	switch(*cp) {
		case '0':
			break;
		case '1':
			cp++;
			switch(*cp) {
				case '0':	dwFinal += dwUpgrade*10;	break;
				case '1':	dwFinal += dwUpgrade*11;	break;
				case '2':	dwFinal += dwUpgrade*12;	break;
				case '3':	dwFinal += dwUpgrade*13;	break;
				case '4':	dwFinal += dwUpgrade*14;	break;
				case '5':	dwFinal += dwUpgrade*15;	break;
				default:	dwFinal += dwUpgrade;		break;
			} break;
			case '2':	dwFinal += dwUpgrade*2;	break;
			case '3':	dwFinal += dwUpgrade*3;	break;
			case '4':	dwFinal += dwUpgrade*4;	break;
			case '5':	dwFinal += dwUpgrade*5;	break;
			case '6':	dwFinal += dwUpgrade*6;	break;
			case '7':	dwFinal += dwUpgrade*7;	break;
			case '8':	dwFinal += dwUpgrade*8;	break;
			case '9':	dwFinal += dwUpgrade*9;	break;
	}
AFTERM3:;

	cursel = m_combo2.GetCurSel();
	switch(cursel) {
		case 0:
			break;
		case 1:
			snum =  m_combo4.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (Critical + Step);			break;
				case 1: 	dwFinal = dwFinal + (Critical + Step*2);		break;
				case 2: 	dwFinal = dwFinal + (Critical + Step*3);		break;
				case 3: 	dwFinal = dwFinal + (Critical + Step*4);		break;
				case 4: 	dwFinal = dwFinal + (Critical + Step*5);		break;
				case 5: 	dwFinal = dwFinal + (Critical + Step*6);		break;
				case 6: 	dwFinal = dwFinal + (Critical + Step*7);		break;
				case 7: 	dwFinal = dwFinal + (Critical + Step*8);		break;
				case 8: 	dwFinal = dwFinal + (Critical + Step*9);		break;
				case 9:		dwFinal = dwFinal + (Critical + Step*10);		break;
				case 10:	dwFinal = dwFinal + (Critical + Step*11);		break;
				case 11:	dwFinal = dwFinal + (Critical + Step*12);		break;
				case 12:	dwFinal = dwFinal + (Critical + Step*13);		break;
				case 13:	dwFinal = dwFinal + (Critical + Step*14);		break;
				case 14:	dwFinal = dwFinal + (Critical + Step*15);		break;
			} break;
		case 2:
			snum =  m_combo4.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (Poison + Step);		break;
				case 1: 	dwFinal = dwFinal + (Poison + Step*2);		break;
				case 2: 	dwFinal = dwFinal + (Poison + Step*3);		break;
				case 3: 	dwFinal = dwFinal + (Poison + Step*4);		break;
				case 4: 	dwFinal = dwFinal + (Poison + Step*5);		break;
				case 5: 	dwFinal = dwFinal + (Poison + Step*6);		break;
				case 6: 	dwFinal = dwFinal + (Poison + Step*7);		break;
				case 7: 	dwFinal = dwFinal + (Poison + Step*8);		break;
				case 8: 	dwFinal = dwFinal + (Poison + Step*9);		break;
				case 9:		dwFinal = dwFinal + (Poison + Step*10);		break;
				case 10:	dwFinal = dwFinal + (Poison + Step*11);		break;
				case 11:	dwFinal = dwFinal + (Poison + Step*12);		break;
				case 12:	dwFinal = dwFinal + (Poison + Step*13);		break;
				case 13:	dwFinal = dwFinal + (Poison + Step*14);		break;
				case 14:	dwFinal = dwFinal + (Poison + Step*15);		break;
			} break;
		case 3:
			snum =  m_combo4.GetCurSel(); 	dwFinal = dwFinal + (Righteous);	break;
		case 4:
			snum =  m_combo4.GetCurSel();	dwFinal = dwFinal + (Agile);		break;
		case 5:
			snum =  m_combo4.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (Light + Step);			break;
				case 1: 	dwFinal = dwFinal + (Light + Step*2);		break;
				case 2: 	dwFinal = dwFinal + (Light + Step*3);		break;
				case 3: 	dwFinal = dwFinal + (Light + Step*4);		break;
				case 4: 	dwFinal = dwFinal + (Light + Step*5);		break;
				case 5: 	dwFinal = dwFinal + (Light + Step*6);		break;
				case 6: 	dwFinal = dwFinal + (Light + Step*7);		break;
				case 7: 	dwFinal = dwFinal + (Light + Step*8);		break;
				case 8: 	dwFinal = dwFinal + (Light + Step*9);		break;
				case 9:		dwFinal = dwFinal + (Light + Step*10);		break;
				case 10:	dwFinal = dwFinal + (Light + Step*11);		break;
				case 11:	dwFinal = dwFinal + (Light + Step*12);		break;
				case 12:	dwFinal = dwFinal + (Light + Step*13);		break;
				case 13:	dwFinal = dwFinal + (Light + Step*14);		break;
				case 14:	dwFinal = dwFinal + (Light + Step*15);		break;
			} break;
		case 6:
			snum =  m_combo4.GetCurSel();	dwFinal = dwFinal + (Sharp);	break;
		case 7:
			snum =  m_combo4.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (Strong + Step);		break;
				case 1: 	dwFinal = dwFinal + (Strong + Step*2);		break;
				case 2: 	dwFinal = dwFinal + (Strong + Step*3);		break;
				case 3: 	dwFinal = dwFinal + (Strong + Step*4);		break;
				case 4: 	dwFinal = dwFinal + (Strong + Step*5);		break;
				case 5: 	dwFinal = dwFinal + (Strong + Step*6);		break;
				case 6: 	dwFinal = dwFinal + (Strong + Step*7);		break;
				case 7: 	dwFinal = dwFinal + (Strong + Step*8);		break;
				case 8: 	dwFinal = dwFinal + (Strong + Step*9);		break;
				case 9:		dwFinal = dwFinal + (Strong + Step*10);		break;
				case 10:	dwFinal = dwFinal + (Strong + Step*11);		break;
				case 11:	dwFinal = dwFinal + (Strong + Step*12);		break;
				case 12:	dwFinal = dwFinal + (Strong + Step*13);		break;
				case 13:	dwFinal = dwFinal + (Strong + Step*14);		break;
				case 14:	dwFinal = dwFinal + (Strong + Step*15);		break;
			} break;
		case 8:
			snum =  m_combo4.GetCurSel();	dwFinal = dwFinal + (Ancient);	break;
		case 9:
			snum =  m_combo4.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (Special + Step);		break;
				case 1: 	dwFinal = dwFinal + (Special + Step*2);		break;
				case 2: 	dwFinal = dwFinal + (Special + Step*3);		break;
				case 3: 	dwFinal = dwFinal + (Special + Step*4);		break;
				case 4: 	dwFinal = dwFinal + (Special + Step*5);		break;
				case 5: 	dwFinal = dwFinal + (Special + Step*6);		break;
				case 6: 	dwFinal = dwFinal + (Special + Step*7);		break;
				case 7: 	dwFinal = dwFinal + (Special + Step*8);		break;
				case 8: 	dwFinal = dwFinal + (Special + Step*9);		break;
				case 9:		dwFinal = dwFinal + (Special + Step*10);	break;
				case 10:	dwFinal = dwFinal + (Special + Step*11);	break;
				case 11:	dwFinal = dwFinal + (Special + Step*12);	break;
				case 12:	dwFinal = dwFinal + (Special + Step*13);	break;
				case 13:	dwFinal = dwFinal + (Special + Step*14);	break;
				case 14:	dwFinal = dwFinal + (Special + Step*15);	break;
			} break;
		case 10:
			snum =  m_combo4.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (Mana + Step);		break;
				case 1: 	dwFinal = dwFinal + (Mana + Step*2);	break;
				case 2: 	dwFinal = dwFinal + (Mana + Step*3);	break;
				case 3: 	dwFinal = dwFinal + (Mana + Step*4);	break;
				case 4: 	dwFinal = dwFinal + (Mana + Step*5);	break;
				case 5: 	dwFinal = dwFinal + (Mana + Step*6);	break;
				case 6: 	dwFinal = dwFinal + (Mana + Step*7);	break;
				case 7: 	dwFinal = dwFinal + (Mana + Step*8);	break;
				case 8: 	dwFinal = dwFinal + (Mana + Step*9);	break;
				case 9:		dwFinal = dwFinal + (Mana + Step*10);	break;
				case 10:	dwFinal = dwFinal + (Mana + Step*11);	break;
				case 11:	dwFinal = dwFinal + (Mana + Step*12);	break;
				case 12:	dwFinal = dwFinal + (Mana + Step*13);	break;
				case 13:	dwFinal = dwFinal + (Mana + Step*14);	break;
				case 14:	dwFinal = dwFinal + (Mana + Step*15);	break;
			} break;
		case 11:
			snum =  m_combo4.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (CIC + Step);		break;
				case 1: 	dwFinal = dwFinal + (CIC + Step*2);		break;
				case 2: 	dwFinal = dwFinal + (CIC + Step*3);		break;
				case 3: 	dwFinal = dwFinal + (CIC + Step*4);		break;
				case 4: 	dwFinal = dwFinal + (CIC + Step*5);		break;
				case 5: 	dwFinal = dwFinal + (CIC + Step*6);		break;
				case 6: 	dwFinal = dwFinal + (CIC + Step*7);		break;
				case 7: 	dwFinal = dwFinal + (CIC + Step*8);		break;
				case 8: 	dwFinal = dwFinal + (CIC + Step*9);		break;
				case 9:		dwFinal = dwFinal + (CIC + Step*10);	break;
				case 10:	dwFinal = dwFinal + (CIC + Step*11);	break;
				case 11:	dwFinal = dwFinal + (CIC + Step*12);	break;
				case 12:	dwFinal = dwFinal + (CIC + Step*13);	break;
				case 13:	dwFinal = dwFinal + (CIC + Step*14);	break;
				case 14:	dwFinal = dwFinal + (CIC + Step*15);	break;
			} break;
	}

	cursel = m_combo1.GetCurSel();
	switch(cursel) {
		case 1:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (PoisonResist + Step2);			break;
				case 1: 	dwFinal = dwFinal + (PoisonResist + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (PoisonResist + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (PoisonResist + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (PoisonResist + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (PoisonResist + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (PoisonResist + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (PoisonResist + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (PoisonResist + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (PoisonResist + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (PoisonResist + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (PoisonResist + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (PoisonResist + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (PoisonResist + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (PoisonResist + Step2*15);		break;
			} break;
		case 2:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (HitProb + Step2);			break;
				case 1: 	dwFinal = dwFinal + (HitProb + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (HitProb + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (HitProb + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (HitProb + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (HitProb + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (HitProb + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (HitProb + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (HitProb + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (HitProb + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (HitProb + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (HitProb + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (HitProb + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (HitProb + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (HitProb + Step2*15);		break;
			} break;
		case 3:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (DefProb + Step2);			break;
				case 1: 	dwFinal = dwFinal + (DefProb + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (DefProb + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (DefProb + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (DefProb + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (DefProb + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (DefProb + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (DefProb + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (DefProb + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (DefProb + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (DefProb + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (DefProb + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (DefProb + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (DefProb + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (DefProb + Step2*15);		break;
			} break;
		case 4:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (HPRecov + Step2);			break;
				case 1: 	dwFinal = dwFinal + (HPRecov + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (HPRecov + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (HPRecov + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (HPRecov + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (HPRecov + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (HPRecov + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (HPRecov + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (HPRecov + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (HPRecov + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (HPRecov + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (HPRecov + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (HPRecov + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (HPRecov + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (HPRecov + Step2*15);		break;
			} break;
		case 5:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (SPRecov + Step2);			break;
				case 1: 	dwFinal = dwFinal + (SPRecov + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (SPRecov + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (SPRecov + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (SPRecov + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (SPRecov + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (SPRecov + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (SPRecov + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (SPRecov + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (SPRecov + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (SPRecov + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (SPRecov + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (SPRecov + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (SPRecov + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (SPRecov + Step2*15);		break;
			} break;
		case 6:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (MPRecov + Step2);			break;
				case 1: 	dwFinal = dwFinal + (MPRecov + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (MPRecov + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (MPRecov + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (MPRecov + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (MPRecov + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (MPRecov + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (MPRecov + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (MPRecov + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (MPRecov + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (MPRecov + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (MPRecov + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (MPRecov + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (MPRecov + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (MPRecov + Step2*15);		break;
			} break;
		case 7:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (MagicResist + Step2);			break;
				case 1: 	dwFinal = dwFinal + (MagicResist + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (MagicResist + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (MagicResist + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (MagicResist + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (MagicResist + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (MagicResist + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (MagicResist + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (MagicResist + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (MagicResist + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (MagicResist + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (MagicResist + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (MagicResist + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (MagicResist + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (MagicResist + Step2*15);		break;
			} break;
		case 8:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (PhysAbsorpt + Step2);			break;
				case 1: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (PhysAbsorpt + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (PhysAbsorpt + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (PhysAbsorpt + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (PhysAbsorpt + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (PhysAbsorpt + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (PhysAbsorpt + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (PhysAbsorpt + Step2*15);		break;
			} break;
		case 9:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (MagAbsorpt + Step2);		break;
				case 1: 	dwFinal = dwFinal + (MagAbsorpt + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (MagAbsorpt + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (MagAbsorpt + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (MagAbsorpt + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (MagAbsorpt + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (MagAbsorpt + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (MagAbsorpt + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (MagAbsorpt + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (MagAbsorpt + Step2*10);	break;
				case 10:	dwFinal = dwFinal + (MagAbsorpt + Step2*11);	break;
				case 11:	dwFinal = dwFinal + (MagAbsorpt + Step2*12);	break;
				case 12:	dwFinal = dwFinal + (MagAbsorpt + Step2*13);	break;
				case 13:	dwFinal = dwFinal + (MagAbsorpt + Step2*14);	break;
				case 14:	dwFinal = dwFinal + (MagAbsorpt + Step2*15);	break;
			} break;
		case 10:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (REP + Step2);			break;
				case 1: 	dwFinal = dwFinal + (REP + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (REP + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (REP + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (REP + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (REP + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (REP + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (REP + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (REP + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (REP + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (REP + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (REP + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (REP + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (REP + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (REP + Step2*15);		break;
			} break;

		case 11:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (EXP + Step2);			break;
				case 1: 	dwFinal = dwFinal + (EXP + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (EXP + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (EXP + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (EXP + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (EXP + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (EXP + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (EXP + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (EXP + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (EXP + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (EXP + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (EXP + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (EXP + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (EXP + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (EXP + Step2*15);		break;
			} break;

		case 12:
			snum =  m_combo5.GetCurSel();
			switch(snum) {
				case 0: 	dwFinal = dwFinal + (GOLD + Step2);			break;
				case 1: 	dwFinal = dwFinal + (GOLD + Step2*2);		break;
				case 2: 	dwFinal = dwFinal + (GOLD + Step2*3);		break;
				case 3: 	dwFinal = dwFinal + (GOLD + Step2*4);		break;
				case 4: 	dwFinal = dwFinal + (GOLD + Step2*5);		break;
				case 5: 	dwFinal = dwFinal + (GOLD + Step2*6);		break;
				case 6: 	dwFinal = dwFinal + (GOLD + Step2*7);		break;
				case 7: 	dwFinal = dwFinal + (GOLD + Step2*8);		break;
				case 8: 	dwFinal = dwFinal + (GOLD + Step2*9);		break;
				case 9:		dwFinal = dwFinal + (GOLD + Step2*10);		break;
				case 10:	dwFinal = dwFinal + (GOLD + Step2*11);		break;
				case 11:	dwFinal = dwFinal + (GOLD + Step2*12);		break;
				case 12:	dwFinal = dwFinal + (GOLD + Step2*13);		break;
				case 13:	dwFinal = dwFinal + (GOLD + Step2*14);		break;
				case 14:	dwFinal = dwFinal + (GOLD + Step2*15);		break;
			} break;
		default:
			break;
	}
			
/*			
0Normal;+0
1Poison Resist;+7+14+21+28
2Hit probability;+7+14+21+28
3Defense probability;+7+14+21+28
4HP Recovery;+7+14+21+28
5SP Recovery;+7+14+21+28
6MP Recovery;+7+14+21+28
7Magic Resist;+7+14+21+28
8Physical Absorption;+3+6+9+12
9Magical Absorption;+3+6+9+12
10Consectutive Attack Damage;+1+2+3+4
11Exp;+10+20+30+40
12Gold+10+20+30+40


DWORD	PoisonResist	0x1100;
DWORD	HitProb			0x2100;
DWORD	DefProb			0x3100;
DWORD	HPRecov			0x4100;
DWORD	SPRecov			0x5100;
DWORD	MPRecov			0x6100;
DWORD	MagicResist		0x7100;
DWORD	PhysAbsorpt		0x8100;
DWORD	MagAbsorpt		0x9100;
DWORD	REP				0xA100;
DWORD	EXP				0xB100;
DWORD	GOLD			0xC100;
			
*/
/*
	0Normal;+0
	1Critical;+1+2+3+4
	2Poision;+5+10+15+20
	3Righteous;+0
	4Agile;+0
	5Light;+4+8+12+16
	6Sharp;+0
	7Strong;+7+14+21+28
	8Ancient;+0
	9Special (Casting Prob.);+3+6+9+12
	10Mana Converting;+1+2+3+4
	11Critical Increase Chance+1+2+3+4

	DWORD	Agile		0x500000;
	DWORD	Light		0x600000;
	DWORD	Strong		0x800000;
	DWORD	Poison		0x200000;
	DWORD	Critical	0x100000;
	DWORD	Sharp		0x700000;
	DWORD	Righteous	0x300000;
	DWORD	Ancient		0x900000;
	DWORD	Special		0xA00000;
	DWORD	Mana		0xB00000;
	DWORD	CIC			0xC00000;
*/
	wsprintf(cTxt, "%lu", dwFinal);
	m_edit1 = cTxt;
	UpdateData(FALSE);
}

void CHBxToolsDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CAboutDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//ShellExecute()
//	ShellExecute(m_hWnd, "open"," http://www.helbreathx.com/ ",NULL,NULL,SW_SHOWNORMAL);
	(32 >= (int)ShellExecute(NULL, "open", "http://www.helbreathx.net/", NULL, NULL, SW_SHOWNORMAL));
}

void CAboutDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	(32 >= (int)ShellExecute(NULL, "open", "http://forum.helbreathx.net/", NULL, NULL, SW_SHOWNORMAL));
}

void CHBxToolsDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	DWORD dwStatus = atoi(m_edit1);
	::MessageBox(m_hWnd, m_edit1, m_edit1, MB_ICONEXCLAMATION | MB_OK);
}