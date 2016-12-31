#include "StdAfx.h"
#include "DuiHandlerSelect.h"
#include <Tlhelp32.h>  
//////////////////////////////////////////////////////////////
// CDuiHandlerHome

CDuiHandlerSelect::CDuiHandlerSelect(void) : CDuiHandler()
{
	m_uTimerAni = 0;
	m_nAniIndex = 0;
}

CDuiHandlerSelect::~CDuiHandlerSelect(void)
{
}
 
// 初始化
void CDuiHandlerSelect::OnInit()
{
	
}

// DUI定时器事件处理
void CDuiHandlerSelect::OnTimer(UINT uTimerID, CString strTimerName)
{
    if(uTimerID == m_uTimerAni)
	{
	}
}

LRESULT CDuiHandlerSelect::processScan(UINT uID, CString strName, UINT Msg, WPARAM wParam, LPARAM lParam){
	
	CDuiGridCtrl* pGridCtrl = (CDuiGridCtrl*)GetControl(_T("gridctrl_2"));
	if(pGridCtrl ){
		
		if(pGridCtrl->GetRowCount()!=0)
		{
			pGridCtrl->ClearItems();
		}
		if(pGridCtrl->GetRowCount()!=0){
			return FALSE;
		}
			HANDLE hProcessSnp = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);  
			if(NULL == hProcessSnp)  
			{  
				return TRUE;
			}  
			  
			PROCESSENTRY32 pe32 = {0};  
			pe32.dwSize = sizeof(pe32);  
			BOOL bResult = Process32First(hProcessSnp, &pe32);  
			int i=0;
			while(bResult)  
			{  
				CString strId;
				strId.Format(_T("id_%d"), i);
				int nRow = pGridCtrl->InsertRow(-1,	strId,-1,Color(0, 0, 0, 0),	_T(""),-1,	_T(""),-1);					
				CString strText;
				strText.Format(_T("%s"), pe32.szExeFile);
				CString strContent;
				strContent.Format(_T(""));
				pGridCtrl->SetSubItem(nRow, 0, strText ,strContent,FALSE);
				bResult = Process32Next(hProcessSnp, &pe32);  
				i++;
			}  
			CloseHandle(hProcessSnp); 
			
	}
	 return TRUE;
}