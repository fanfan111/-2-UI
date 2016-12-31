// DuiVision message handler base class
#pragma once
#include "StdAfx.h"
#include <stdio.h>
#include "stdlib.h"
#include <windows.h>
#include "CommDlg.h"

class CDuiObject;
// DUI�¼�������

class CDuiHandlerControl : public CDuiHandler
{
public:
    CDuiHandlerControl(void);
    virtual ~CDuiHandlerControl(void);

    virtual void OnInit(CDlgBase* m_pDlg);
	static VOID WINAPI HookInthere( );
	static VOID WINAPI timeCalc();
	static CDlgBase* pDlg;
	static int pautime;
	
	LRESULT OnDuiBtnHookStart(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);
	LRESULT OnDuiBtnHookEnd(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);
	LRESULT OnDuiBtnHookOpen(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam);
    virtual void OnTimer(UINT uTimerID, CString strTimerName);

    UINT m_uTimerAni;   // ������ʱ��
    int m_nAniIndex;    // ��������
	

    // ��Ϣ������
    DUI_DECLARE_MESSAGE_BEGIN(CDuiHandlerControl)
		DUI_CONTROL_NAMEMSG_MESSAGE(L"button.start", MSG_BUTTON_DOWN, OnDuiBtnHookStart)
		DUI_CONTROL_NAMEMSG_MESSAGE(L"button.end", MSG_BUTTON_DOWN, OnDuiBtnHookEnd)
		DUI_CONTROL_NAMEMSG_MESSAGE(L"button.open", MSG_BUTTON_DOWN, OnDuiBtnHookOpen)
    DUI_DECLARE_MESSAGE_END()

public:
	//����״̬
	static BOOL StatusFLAG;
};
