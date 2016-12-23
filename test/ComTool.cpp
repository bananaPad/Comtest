#include "stdafx.h"
#include "ComTool.h"
#include <string>

ComTool::ComTool()
{
}
//得到所有可用串口(从http://blog.csdn.net/mingojiang/article/details/7713529代码修改得到)
void ComTool::getAllCom(HWND hwnd, int ID)
{
	HKEY hKey;
	if (ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DEVICEMAP\\SERIALCOMM"), 0, KEY_READ, &hKey)){
		
		TCHAR   achClass[MAX_PATH] = TEXT(""); // buffer for class name
		DWORD   cchClassName = MAX_PATH; // size of class string
		DWORD   cSubKeys = 0;                  // number of subkeys
		DWORD   cbMaxSubKey;             // longest subkey size
		DWORD   cchMaxClass;             // longest class string
		DWORD   cValues;             // number of values for key
		DWORD   cchMaxValue;         // longest value name
		DWORD   cbMaxValueData;      // longest value data
		DWORD   cbSecurityDescriptor; // size of security descriptor
		FILETIME ftLastWriteTime;     // last write time
		DWORD i, retCode;
		TCHAR achValue[MAX_VALUE_NAME];
		DWORD cchValue = MAX_VALUE_NAME;

		BYTE strDSName[10];
		DWORD nValueType = 0, nBuffLen = 10;
		// Get the class name and the value count.
		retCode = RegQueryInfoKey(
			hKey,                   // key handle
			achClass,               // buffer for class name
			&cchClassName,          // size of class string
			NULL,                   // reserved
			&cSubKeys,              // number of subkeys
			&cbMaxSubKey,           // longest subkey size
			&cchMaxClass,           // longest class string
			&cValues,               // number of values for this key
			&cchMaxValue,           // longest value name
			&cbMaxValueData,        // longest value data
			&cbSecurityDescriptor,  // security descriptor
			&ftLastWriteTime);      // last write time	
		if (cValues> 0 && retCode ==ERROR_SUCCESS) {
			for (i = 0; i<cValues;i++){
				achValue[0] = '\0';
				if (ERROR_SUCCESS == RegEnumValue(hKey, i, achValue, &cchValue, NULL, NULL, NULL, NULL)) {
						if (NULL != wcsstr(achValue, _T("Serial")) || NULL != wcsstr(achValue, _T("VCom"))) {
							memset(strDSName, 0, 10);
							if (ERROR_SUCCESS == RegQueryValueExW(hKey, (LPCTSTR)achValue, NULL,
								&nValueType, strDSName, &nBuffLen)) {
								SendMessage(GetDlgItem(hwnd, ID), CB_ADDSTRING, (WPARAM)0, (LPARAM)strDSName);
							}
						}
				}
			}	
			SendMessage(GetDlgItem(hwnd, ID), CB_SELECTSTRING, (WPARAM)0, (LPARAM)L"COM");
		}
		else {
			MessageBox(hwnd,L"PC机没有COM口.....",L"没有串口",0);
		}
	}
	else {
		MessageBox(hwnd, L"PC机没有COM口.....", L"没有串口", 0);
	}
	RegCloseKey(hKey);
}
//打开串口并配置波特率
bool ComTool::openCom(WCHAR * name, int baud)
{
	return false;
}


ComTool::~ComTool()
{
}
