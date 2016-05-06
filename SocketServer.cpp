// SoscketServer.cpp : implementation file
//

#include "stdafx.h"
#include "SocketServer.h"

// CSoscketServer

CSocketServer::CSocketServer()
{
}

CSocketServer::~CSocketServer()
{
}

// CSoscketServer member functions

void CSocketServer::OnAccept(int nErrorCode){
	CServiceSocket* pServiceSocket = new CServiceSocket();
	Accept(*pServiceSocket);
	//add to collection
	AddService(pServiceSocket);
	//send welcome to this socket
	CString mess("OK -- Connexion établie avec le serveur\n");
	int size = mess.GetLength();
	LPTSTR p = mess.GetBuffer();
	pServiceSocket->Send(p, size);
	CAsyncSocket::OnAccept(nErrorCode);
}

void CSocketServer::AddService(CServiceSocket * pService){
	m_listOfServices.Add(pService);
}