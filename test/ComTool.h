#pragma once
#define MAX_KEY_LENGTH   255
#define MAX_VALUE_NAME  16383
class ComTool
{
public:
	ComTool();
	void getAllCom(HWND hwnd, int ID);
	bool openCom(WCHAR* name, int baud);
	~ComTool();
};

