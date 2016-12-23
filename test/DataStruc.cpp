#include "stdafx.h"
#include "DataStruc.h"


DataStruc::DataStruc()
{
	int i = 0, j = 0;
	//初始化数据
	for ( i = 0; i < 10; i++)
	{
		for ( j = 0; j < 10; j++)
		{
			this->data[i][j] = 0;
		}
	}
}

void DataStruc::draw(HDC hdc)
{
	int i = 0, j = 0;
	//画方格
	for (i = 0; i < 11; i++)
	{
		MoveToEx(hdc, this->startx, this->starty + i*this->nwh,nullptr);
		LineTo(hdc, this->startx+ this->nwh * 10,this->starty+i*this->nwh);
	}
	for (i = 0; i < 11; i++)
	{
		MoveToEx(hdc, this->startx + this->nwh * i, this->starty, nullptr);
		LineTo(hdc, this->startx + this->nwh * i, this->starty + 10*this->nwh);
	}
	//画勾勾叉叉
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (this->data[i][j] == 1){//勾勾
				
				MoveToEx(hdc, this->startx + i*this->nwh, this->starty + j*this->nwh + this->nwh / 2, nullptr);
				LineTo(hdc, this->startx + i*this->nwh + this->nwh / 2, this->starty + (j + 1)*this->nwh);
				LineTo(hdc, this->startx + (i+1)*this->nwh, this->starty + j *this->nwh);
			}
			//叉叉
			if (this->data[i][j] == 2)
			{
				MoveToEx(hdc, this->startx + i*this->nwh, this->starty + j*this->nwh, nullptr);
				LineTo(hdc, this->startx + (i + 1)*this->nwh, this->starty + (j + 1)*this->nwh);
				MoveToEx(hdc, this->startx + i*this->nwh, this->starty + (j + 1)*this->nwh, nullptr);
				LineTo(hdc, this->startx + (i + 1)*this->nwh, this->starty + j *this->nwh);
			}
		}
	}
}

int DataStruc::click(int x, int y)
{
	int w, h;
	if (x<this->startx || y<this->starty)
	{
		return 0;
	}
	w = (x - this->startx) / this->nwh;
	h = (y - this->starty) / this->nwh;
	if (w>9 || h>9 || w<0 || h<0)
	{
		return 0;
	}
	if (this->data[w][h]==2)
	{
		return 0;
	}
	if (this->data[w][h] == 0)
	{
		data[w][h] = 1;
		return 1;
	}
	else {
		data[w][h] = 0;
		return 1;
	}
}

void DataStruc::invalid()
{
	int i = 0, j = 0;
	//初始化数据
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (this->data[i][j] == 1) {
				this->data[i][j] = 2;
			}
		}
	}
}


DataStruc::~DataStruc()
{
}
