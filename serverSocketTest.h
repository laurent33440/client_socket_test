// server_socket_test.h�: fichier d'en-t�te principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CserverSocketTestApp:
// Consultez server_socket_test.cpp pour l'impl�mentation de cette classe
//

class CserverSocketTestApp : public CWinApp
{
public:
	CserverSocketTestApp();

// Substitutions
	public:
	virtual BOOL InitInstance();

// Impl�mentation

	DECLARE_MESSAGE_MAP()
};

extern CserverSocketTestApp theApp;