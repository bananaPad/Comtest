#pragma once
class DataStruc
{
public:
	
	DataStruc();
	void draw(HDC hdc);
	int click(int x, int y);
	void invalid();
	~DataStruc();
private:
	char data[10][10];//为0，初始。为1，已经选择。为3，无效状态。
	int startx=80;
	int starty = 80;
	int nwh = 25;
};

