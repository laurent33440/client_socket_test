// serverSocketTestDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "serverSocketTest.h"
#include "serverSocketTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CserverSocketTestDlg




CserverSocketTestDlg::CserverSocketTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CserverSocketTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CserverSocketTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,ID_START_SERVER, m_buttonStartServer);
	DDX_Control(pDX, IDC_DATA_LIST_FROM_CLIENT,  m_dataListFromClient);
	DDX_Control(pDX, IDC_COMBO_PORT_LIST, m_portList);
}

BEGIN_MESSAGE_MAP(CserverSocketTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_QUIT, &CserverSocketTestDlg::OnBnClickedQuit)
	ON_BN_CLICKED(ID_START_SERVER, &CserverSocketTestDlg::OnBnClickedStartServer)
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO_PORT_LIST, &CserverSocketTestDlg::OnCbnSelchangeComboPortList)
END_MESSAGE_MAP()


// gestionnaires de messages pour CserverSocketTestDlg

BOOL CserverSocketTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Définir l'icône de cette boîte de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO : ajoutez ici une initialisation supplémentaire
	InitComboBox(m_portList, IDS_STRING120, 3);
	//init port number
	OnCbnSelchangeComboPortList();
	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône. Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CserverSocketTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CserverSocketTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CserverSocketTestDlg::OnBnClickedQuit()
{
	if(MessageBox("Voulez-vous réellement quitter?","Quitter", MB_YESNO|MB_ICONQUESTION)==IDNO){
		return; //stay on dialog
	}
	m_socketServer.Close();
	CDialog::OnCancel();//close dialog
}

void CserverSocketTestDlg::OnBnClickedStartServer()
{
	WORD port = atoi(m_currentPort);
	m_socketServer.Create(port);
	m_socketServer.Listen();
	m_buttonStartServer.SetWindowText(_T("Serveur démarré..."));

	return; //stay on dialog

}

void CserverSocketTestDlg::OnCbnSelchangeComboPortList()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	m_portList.GetLBText(m_portList.GetCurSel(), m_currentPort);
}

void CserverSocketTestDlg::InitComboBox(CComboBox& combo, DWORD refList, byte numberItem)
{
	//fill combo
	CString str;
	for (int i = 0; i<numberItem; i++)
	{
		str.LoadString(refList + i);
		combo.AddString(str);
	}
	combo.SetCurSel(0);
	//Adjust size
	CDC* pDC = combo.GetDC();
	CSize sz;
	int newWidth = 0;
	int nWidth = combo.GetDroppedWidth();

	for (int i = 0; i < combo.GetCount(); i++)
	{
		combo.GetLBText(i, str);
		sz = pDC->GetTextExtent(str);
		if (sz.cx > newWidth)
			newWidth = sz.cx;
	}
	// Add allowance for vertical scroll bar and edges
	newWidth += (GetSystemMetrics(SM_CXVSCROLL) + 2 * GetSystemMetrics(SM_CXEDGE));
	nWidth = max(nWidth, newWidth);
	combo.SetDroppedWidth(nWidth);
	combo.ReleaseDC(pDC);
}
