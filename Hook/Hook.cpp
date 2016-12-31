// Hook.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Hook.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

//#define _WIN32_WINNT  0x0500        //设置系统版本，可以使用底层键盘钩子  
//#define WM_MY_SHORTS (WM_USER + 105)  

//全局变量   
//LPWORD      g_lpdwVirtualKey = NULL;    //Keycode 数组的指针   
//int         g_nLength = 0;          //Keycode 数组的大小   
HINSTANCE   g_hInstance = NULL;     //模块实例句柄    
HHOOK       g_hHook = NULL;         //钩子句柄   
//HWND        g_hWnd  = NULL;    


#pragma data_seg("DLLSharedSection")      // 声明共享数据段，并命名该数据段
  queue<LPWORD> keyDataQueue;      // 必须在定义的同时进行初始化!!!!
#pragma data_seg()
#pragma comment(linker,"/section:.DLLSharedSection,rws")

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call,LPVOID lpReserved)   
{    
    //保存模块实例句柄   
    g_hInstance = (HINSTANCE)hModule;   
      
    //在进程结束或线程结束时卸载钩子    
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
    //如果已经安装键盘钩子则返回 FALSE    
    if (g_hHook != NULL) return FALSE;  
  
    //安装底层键盘钩子    
    g_hHook = SetWindowsHookExW(WH_KEYBOARD,KeyboardProc,g_hInstance,NULL);  
    if (g_hHook == NULL) return FALSE; 

    return TRUE;    
}    

BOOL WINAPI StopCatch()   
{   //卸载钩子   
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


// 这是导出变量的一个示例
HOOK_API int nHook=0;

// 这是导出函数的一个示例。
HOOK_API int fnHook(void)
{
	return 42;
}


