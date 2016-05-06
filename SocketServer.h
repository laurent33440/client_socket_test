#pragma once

#include "afxtempl.h"
#include "ServiceSocket.h"

//class CServiceSocket;

// CSoscketServer command target

class CSocketServer : public CAsyncSocket
{
public:
	CSocketServer();
	virtual ~CSocketServer();

	void OnAccept(int nErrorCode);

private:
	void AddService(CServiceSocket * pService);

private:
	CArray<CServiceSocket*,CServiceSocket*> m_listOfServices;

};




