// MyFirstApp.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "pxcsession.h"
#include "pxcsmartptr.h"


int _tmain(int argc, _TCHAR* argv[])
{
	PXCSmartPtr<PXCSession> session;
	PXCSession_Create(&session);
	for (int i = 0; ; i++) {
		PXCSession::ImplDesc desc;
		pxcStatus sts = session->QueryImpl(0, i, &desc);
		if (sts < PXC_STATUS_NO_ERROR) break;
		wprintf(L"Module: %s, iuid=0x%x\n", desc.friendlyName, desc.iuid);
	}

	return 0;
}
