// ServiceSocket.cpp : implementation file
//

#include "stdafx.h"
#include "ServiceSocket.h"
#include "serverSocketTestDlg.h"


// CServiceSocket

CServiceSocket::CServiceSocket()
{
}

CServiceSocket::~CServiceSocket()
{
}

// CServiceSocket member functions

// receive from client
void CServiceSocket::OnReceive(int nErrorCode){
	char message[200];
	long size = Receive(message,200);
	message[size]=0;
	GetDialog()->m_dataListFromClient.InsertString(-1,message);
	CAsyncSocket::OnReceive(nErrorCode);
}

void CServiceSocket::OnSend(int nErrorCode){

}

CserverSocketTestDlg* CServiceSocket::GetDialog(){
	return (CserverSocketTestDlg*) ::AfxGetMainWnd();
}

