// Hook.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Hook.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

//#define _WIN32_WINNT  0x0500        //����ϵͳ�汾������ʹ�õײ���̹���  
//#define WM_MY_SHORTS (WM_USER + 105)  

//ȫ�ֱ���   
//LPWORD      g_lpdwVirtualKey = NULL;    //Keycode �����ָ��   
//int         g_nLength = 0;          //Keycode ����Ĵ�С   
HINSTANCE   g_hInstance = NULL;     //ģ��ʵ�����    
HHOOK       g_hHook = NULL;         //���Ӿ��   
//HWND        g_hWnd  = NULL;    


#pragma data_seg("DLLSharedSection")      // �����������ݶΣ������������ݶ�
  queue<LPWORD> keyDataQueue;      // �����ڶ����ͬʱ���г�ʼ��!!!!
#pragma data_seg()
#pragma comment(linker,"/section:.DLLSharedSection,rws")

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call,LPVOID lpReserved)   
{    
    //����ģ��ʵ�����   
    g_hInstance = (HINSTANCE)hModule;   
      
    //�ڽ��̽������߳̽���ʱж�ع���    
    switch (ul_reason_for_call)   
    {   
    case DLL_PROCESS_ATTACH:   
           break;    
    case DLL_THREAD_ATTACH:  
         break;       
    case DLL_PROCESS_DETACH:   
      case DLL_THREAD_DETACH:    
        if (g_hHook != NULL) UnhookWindowsHookEx(g_hHook);   
        break;  
    }  
    return TRUE;  
} 

LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam)  
{  
	
	char keyInfo[100];
	
	if (nCode == HC_ACTION)
	{
		MessageBoxA(NULL, "hi", "hi", MB_OK);
		PKBDLLHOOKSTRUCT p;
		p = (PKBDLLHOOKSTRUCT)lParam;
		cout<<p->vkCode;
		//keyDataQueue.push((LPWORD)wParam);
		//int num = keyDataQueue.size();
		
		//char num = (char)p->vkCode;
		//sprintf(keyInfo, "%d", num);
		//MessageBoxA(NULL, keyInfo, "key", MB_OK);
	}

 return CallNextHookEx( g_hHook, nCode, wParam, lParam );    
} 

BOOL WINAPI StartCatch()//LPWORD lpdwVirtualKey, int nLength)//,  HWND  pWnd)   
{    
    //����Ѿ���װ���̹����򷵻� FALSE    
    if (g_hHook != NULL) return FALSE;  
  
    //��װ�ײ���̹���    
    g_hHook = SetWindowsHookExW(WH_KEYBOARD,KeyboardProc,g_hInstance,NULL);  
    if (g_hHook == NULL) return FALSE; 

    return TRUE;    
}    

BOOL WINAPI StopCatch()   
{   //ж�ع���   
    if (UnhookWindowsHookEx(g_hHook) == 0) return FALSE;   
    g_hHook = NULL;   
    return TRUE;   
}

HOOK_API BOOL startOrEndAdd(bool flag){
	if(flag){
		
		BOOL reflag =StartCatch();
		return reflag;
	}else{
		BOOL reflag =StopCatch();
		return reflag;
	}
	return FALSE;
}
HOOK_API LPWORD get()
{
	LPWORD a =keyDataQueue.front();
    keyDataQueue.pop();
    return a;
}
HOOK_API BOOL isEmpty(){
	BOOL flag = FALSE;
	char keyInfo[100];
	int num = keyDataQueue.size();
	sprintf(keyInfo, "%d", num);
	//MessageBoxA(NULL, keyInfo, "num", MB_OK);
	if(keyDataQueue.size()!=0){
		flag = TRUE;
	}
	return flag;
}


// ���ǵ���������һ��ʾ��
HOOK_API int nHook=0;

// ���ǵ���������һ��ʾ����
HOOK_API int fnHook(void)
{
	return 42;
}


