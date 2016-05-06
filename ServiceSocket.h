#pragma once

class CserverSocketTestDlg; // dialog

// CServiceSocket command target

class CServiceSocket : public CAsyncSocket
{
public:
	CServiceSocket();
	virtual ~CServiceSocket();

	void OnReceive(int nErrorCode);
	void OnSend(int nErrorCode);

private :
	CserverSocketTestDlg* GetDialog();
};


