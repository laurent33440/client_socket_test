// serverSocketTestDlg.h : fichier d'en-tête
// serveur socket
//

#pragma once

#include "SocketServer.h"
#include "Resource.h" //IDD

// boîte de dialogue CserverSocketTestDlg
class CserverSocketTestDlg : public CDialog
{
// Construction
public:
	CserverSocketTestDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
	enum { IDD = IDD_SERVER_SOCKET_TEST_DIALOG };
	CComboBox m_portList;
	CButton m_buttonStartServer;
	CListBox m_dataListFromClient;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV

private:
	CSocketServer m_socketServer; 
	CString m_currentPort;

// Implémentation
private:
	void InitComboBox(CComboBox& combo, DWORD refList, byte numberItem);
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedStartServer();
	afx_msg void OnCbnSelchangeComboPortList();
	DECLARE_MESSAGE_MAP()
	
};
