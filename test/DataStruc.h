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
	char data[10][10];//Ϊ0����ʼ��Ϊ1���Ѿ�ѡ��Ϊ3����Ч״̬��
	int startx=80;
	int starty = 80;
	int nwh = 25;
};

