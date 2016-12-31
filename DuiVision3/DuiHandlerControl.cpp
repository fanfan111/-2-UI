#include "StdAfx.h"
#include "DuiHandlerControl.h"
#include "ceshi.h"
#include "sort1.h"
#define SLEEP_TIME 2000
//////////////////////////////////////////////////////////////
// CDuiHandlerControl
BOOL CDuiHandlerControl::StatusFLAG=FALSE;
int CDuiHandlerControl::pautime=50;
CDuiHandlerControl::CDuiHandlerControl(void) : CDuiHandler()
{
    m_uTimerAni = 0;
    m_nAniIndex = 0;
}

CDuiHandlerControl::~CDuiHandlerControl(void)
{
}
CDlgBase*  CDuiHandlerControl::pDlg;
// ��ʼ��
void CDuiHandlerControl::OnInit(CDlgBase* m_pDlg)
{
	CDuiHandlerControl::pDlg=m_pDlg;
	CDuiHandlerControl::StatusFLAG=FALSE;
	/*�����и�����ťȡ��չʾ����Ϊ�������ҳ�����Բ���ˢ�¿ؼ�*/
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.esc_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f1_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f2_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f3_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f4_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f5_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f6_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f7_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f8_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f9_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f10_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f11_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f12_T"))))->SetControlVisible(FALSE);

	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.`_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.1_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.2_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.3_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.4_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.5_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.6_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.7_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.8_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.9_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.0_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.-_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.=_T"))))->SetControlVisible(FALSE);
	
	
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.backspace_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.tab_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.q_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.w_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.e_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.r_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.t_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.y_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.u_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.i_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.o_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.p_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.[_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.]_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.fxg_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.lock_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.a_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.s_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.d_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.f_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.g_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.h_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.j_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.k_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.l_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.;_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.'_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.enter_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.lshift_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.z_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.x_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.c_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.v_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.b_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.n_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.m_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.,_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.._T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.xg_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.rshift_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.lctrl_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.lwin_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.lalt_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.space_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.ralt_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.rwin_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.app_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.rctrl_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.prtsc_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.scrlock_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.pause_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.insert_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.home_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.pgup_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.delete_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.end_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.pgdn_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.shang_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.zuo_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.xia_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.you_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.numberlock_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp +_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp -_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp cheng_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp xg_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp ._T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp enter_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 0_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 1_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 2_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 3_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 4_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 5_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 6_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 7_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 8_T"))))->SetControlVisible(FALSE);
	((CDuiTabCtrl*)(m_pDlg->GetControl(_T("keyboard.kp 9_T"))))->SetControlVisible(FALSE);
}


// DUI��ʱ���¼�����
void CDuiHandlerControl::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
    {
    }
}



// ��ťbutton.start����Ϣ����
LRESULT CDuiHandlerControl::OnDuiBtnHookStart(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	
	
	/* 
	HANDLE WINAPI CreateThread( 
    LPSECURITY_ATTRIBUTES   lpThreadAttributes, //�̰߳�ȫ��ص����ԣ�����ΪNULL 
    SIZE_T                  dwStackSize,        //���̵߳ĳ�ʼ��ջ�ڴ�С��������Ϊ0 
    LPTHREAD_START_ROUTINE  lpStartAddress,     //���߳�ִ�еĻص�������Ҳ��Ϊ�̺߳��� 
    LPVOID                  lpParameter,        //�����̺߳����Ĳ��������贫�ݲ���ʱΪNULL 
    DWORD                   dwCreationFlags,    //�����̴߳����ı�־ 
    LPDWORD                 lpThreadId          //�������������ڻ���߳�ID�����ΪNULL�򲻷����߳�ID 
); 
*/ 
	if(!CDuiHandlerControl::StatusFLAG)
	{
		CDuiHandlerControl::StatusFLAG = TRUE;
		//�����߳� ��ȡ�߳�
		DWORD dwReadThreadID;
		HANDLE hReadThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CDuiHandlerControl::HookInthere, NULL, 0, &dwReadThreadID);
		CloseHandle(hReadThread);
	
	}
	else
	{
		DuiSystem::DuiMessageBox(NULL, _T("���̼���Ѿ���ʼ��")); 
	}
	
    return TRUE;
}

typedef BOOL(*lpAdd)(bool falg); //�궨�庯��ָ������
typedef LPWORD(*lpGet)(); //�궨�庯��ָ������
typedef BOOL(*lpIsEmpty)(); //�궨�庯��ָ������

VOID WINAPI CDuiHandlerControl::timeCalc()
{
	while(CDuiHandlerControl::pautime!=0){
		CDuiHandlerControl::pautime = 0;
		Sleep(SLEEP_TIME);
	}
	
	CDlgBase* pDlg_m =CDuiHandlerControl::pDlg;
	CDuiTabCtrl* pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.pause_T")));
	pTabCtrl_F->SetControlVisible(FALSE);
	pTabCtrl_F->UpdateControl(TRUE,TRUE);

}
VOID WINAPI CDuiHandlerControl::HookInthere()
{
	/*ceshi*/
	//��ʼ���

	int length =6,length1=236;
	while(CDuiHandlerControl::StatusFLAG)
	{
		for(int num=0;num<length1;num++){
			for(int i=0;i<length;i++){
				unsigned char a =ceshi[num][i];
				struct returnchar result = Sort::find(a);
				char* p= result.name;
				if(strcmp(p,"wait")==0 ||strcmp(p,"error")==0){
				
				}
				else{
					if(result.flag){
						CString m;
						m.Format(_T("%s"), CStringW(p));
						CDlgBase* pDlg_m =CDuiHandlerControl::pDlg;
						CDuiTabCtrl* pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(m));
						pTabCtrl_F->SetControlVisible(TRUE);
						pTabCtrl_F->UpdateControl(TRUE);
						
						if(strcmp(p,"keyboard.pause_T")==0){	
							CDuiHandlerControl::pautime = SLEEP_TIME;
							DWORD dwReadThreadID;
							HANDLE hReadThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)CDuiHandlerControl::timeCalc, NULL, 0, &dwReadThreadID);
							CloseHandle(hReadThread);
						}
						
					}else{
						CString m;
						m.Format(_T("%s"), CStringW(p));
						CDlgBase* pDlg_m =CDuiHandlerControl::pDlg;
						CDuiTabCtrl* pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(m));
						pTabCtrl_F->SetControlVisible(FALSE);
						pTabCtrl_F->UpdateControl(TRUE,TRUE);
					}
					
				}
			}
			Sleep(50);
		}
		
	}



	/*hook
	HINSTANCE hDll; //DLL��� 
	lpAdd startOrEndAdd; //����ָ��
	lpGet getFun;
	lpIsEmpty emptyFun;
	hDll = LoadLibrary(L"..\\x64\\Debug\\Hook.dll");
	//hDll = LoadLibrary(L".\\Hook.dll");

	//��ʼ���
	startOrEndAdd = (lpAdd)GetProcAddress(hDll, "startOrEndAdd");
	startOrEndAdd(true);
	//MSG msg;
	//GetMessage(&msg,NULL,0,0);

	getFun = (lpGet)GetProcAddress(hDll, "get");
	emptyFun = (lpIsEmpty)GetProcAddress(hDll, "isEmpty");
	
	while(CDuiHandlerControl::StatusFLAG||emptyFun()==TRUE)
	{
		if(emptyFun()==TRUE){
			unsigned char a = (unsigned char)getFun();
			CString t;
			t.Format(_T("%d"), a);
			DuiSystem::DuiMessageBox(NULL,t);
		}
		Sleep(50);
	}
	startOrEndAdd(false);
	FreeLibrary(hDll);		

	*/



}
// ��ťbutton.end����Ϣ����
LRESULT CDuiHandlerControl::OnDuiBtnHookEnd(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	CDuiHandlerControl::StatusFLAG = FALSE;	
    return TRUE;
}
LRESULT CDuiHandlerControl::OnDuiBtnHookOpen(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam){
	ShellExecute(NULL, NULL, _T("explorer.exe"), _T("C:\\Windows"), NULL, SW_NORMAL);
	return TRUE;
}



//��ʾ����
		/*
		CDlgBase* pDlg_m =CDuiHandlerControl::pDlg;
		CDuiTabCtrl* pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.esc")));
		pTabCtrl_F->SetControlVisible(FALSE);
		pTabCtrl_F->UpdateControl(TRUE);

		CDuiTabCtrl* pTabCtrl_T = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.esc_T")));	
		pTabCtrl_T->SetControlVisible(TRUE);
		pTabCtrl_T->UpdateControl(TRUE);
		Sleep(SLEEP_TIME);
		pTabCtrl_T->SetControlVisible(FALSE);
		pTabCtrl_T->UpdateControl(TRUE);
		pTabCtrl_F->SetControlVisible(TRUE);
		pTabCtrl_F->UpdateControl(TRUE);


		pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.f1")));
		pTabCtrl_F->SetControlVisible(FALSE);
		pTabCtrl_F->UpdateControl(TRUE);

		pTabCtrl_T = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.f1_T")));	
		pTabCtrl_T->SetControlVisible(TRUE);
		pTabCtrl_T->UpdateControl(TRUE);
		Sleep(SLEEP_TIME);
		pTabCtrl_T->SetControlVisible(FALSE);
		pTabCtrl_T->UpdateControl(TRUE);
		pTabCtrl_F->SetControlVisible(TRUE);
		pTabCtrl_F->UpdateControl(TRUE);


		pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.f2")));
		pTabCtrl_F->SetControlVisible(FALSE);
		pTabCtrl_F->UpdateControl(TRUE);

		pTabCtrl_T = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.f2_T")));	
		pTabCtrl_T->SetControlVisible(TRUE);
		pTabCtrl_T->UpdateControl(TRUE);
		Sleep(SLEEP_TIME);
		pTabCtrl_T->SetControlVisible(FALSE);
		pTabCtrl_T->UpdateControl(TRUE);
		pTabCtrl_F->SetControlVisible(TRUE);
		pTabCtrl_F->UpdateControl(TRUE);

		pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.f3")));
		pTabCtrl_F->SetControlVisible(FALSE);
		pTabCtrl_F->UpdateControl(TRUE);

		pTabCtrl_T = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.f3_T")));	
		pTabCtrl_T->SetControlVisible(TRUE);
		pTabCtrl_T->UpdateControl(TRUE);
		Sleep(SLEEP_TIME);
		pTabCtrl_T->SetControlVisible(FALSE);
		pTabCtrl_T->UpdateControl(TRUE);
		pTabCtrl_F->SetControlVisible(TRUE);
		pTabCtrl_F->UpdateControl(TRUE);	*/	




/*CDlgBase* pDlg_m =CDuiHandlerControl::pDlg;
			CDuiTabCtrl* pTabCtrl_F = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.esc")));
			pTabCtrl_F->SetControlVisible(FALSE);
			pTabCtrl_F->UpdateControl(TRUE);

			CDuiTabCtrl* pTabCtrl_T = (CDuiTabCtrl*)(pDlg_m->GetControl(_T("keyboard.escT")));	
			pTabCtrl_T->SetControlVisible(TRUE);
			pTabCtrl_T->UpdateControl(TRUE);
			Sleep(SLEEP_TIME);
			pTabCtrl_T->SetControlVisible(FALSE);
			pTabCtrl_T->UpdateControl(TRUE);
			pTabCtrl_F->SetControlVisible(TRUE);
			pTabCtrl_F->UpdateControl(TRUE);*/