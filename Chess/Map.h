#pragma once
#include "Bitbmp.h"

struct Line
{
	int Start_Point_x;
	int Start_Point_y;

	int End_Point_x;
	int End_Point_y;
};

class Map
{
	int Map_Bmpid = 0;
	int Font_Id = 0;
	HPEN hPen = NULL;
	Line LeftUp_Y;//左上纵线
	Line LeftUp_X;//左上横线

	Line LeftDown_Y;//左下纵线
	Line LeftDown_X;//左下横线

	Line RightUp_Y;//右上纵线
	Line RightUp_X;//右上横线

	Line RightDown_Y;//右下纵线
	Line RightDown_X;//右下横线

	HDC mMDC;
public:
	Map() {}
	void InitMap(HDC hdc)
	{
		Map_Bmpid = GoBitmap->Load_Bmp("Image\\Map\\Map.bmp");
		Font_Id = GoBitmap->LoadFont("楷体", 25, 50);
		mMDC = GoBitmap->GetMDC();
	}
	void DrawRectangle()
	{
		GoBitmap->DrawBmp1(Map_Bmpid, 0, 0, 580, 640, 0, 0);
		//框
		GoBitmap->DrawRectangle2(43, 43, 3, 554, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(537, 43, 3, 554, 0X000000, 0X000000);

		GoBitmap->DrawRectangle2(43, 43, 494, 3, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(43, 597, 497, 3, 0X000000, 0X000000);
		//横
		GoBitmap->DrawRectangle2(50, 50, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 110, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 170, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 230, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 290, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 350, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 410, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 470, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 530, 480, 2, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(50, 590, 482, 2, 0X000000, 0X000000);
		//纵
		GoBitmap->DrawRectangle2(50, 50, 2, 540, 0X000000, 0X000000);

		GoBitmap->DrawRectangle2(110, 50, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(170, 50, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(230, 50, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(290, 50, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(350, 50, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(410, 50, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(470, 50, 2, 240, 0X000000, 0X000000);

		GoBitmap->DrawRectangle2(530, 50, 2, 540, 0X000000, 0X000000);

		GoBitmap->DrawRectangle2(110, 350, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(170, 350, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(230, 350, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(290, 350, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(350, 350, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(410, 350, 2, 240, 0X000000, 0X000000);
		GoBitmap->DrawRectangle2(470, 350, 2, 240, 0X000000, 0X000000);
	}
	void RenderMap()
	{
		DrawRectangle();

		RenderString(mMDC);

		if (true)//这里与定义hPen的是一套
		{
			hPen = (HPEN)GetStockObject(BLACK_PEN);
			hPen = CreatePen(PS_DASHDOT, 2, 0X000000);
			SelectObject(mMDC, hPen);//这里并未封装,应该是绘制到mdc，放到逻辑更新才不会出问题，由于是hdc，只能放这
		}
		RenderLine(mMDC);
	}
	void MapLeftUp(HDC mdc,
		int Start_Point_x_X = 0, int Start_Point_y_X = 0, int End_Point_x_X = 0, int End_Point_y_X = 0, //横线
		int Start_Point_x_Y = 0, int Start_Point_y_Y = 0, int End_Point_x_Y = 0, int End_Point_y_Y = 0)//纵线
	{
		//横线的起点和终点
		this->LeftUp_X.Start_Point_x = 90 + Start_Point_x_X;
		this->LeftUp_X.Start_Point_y = 168 + Start_Point_y_X;
		this->LeftUp_X.End_Point_x = 108 + End_Point_x_X;
		this->LeftUp_X.End_Point_y = 168 + End_Point_y_X;
		//横线
		MoveToEx(mdc, this->LeftUp_X.Start_Point_x, this->LeftUp_X.Start_Point_y, NULL);
		LineTo(mdc, this->LeftUp_X.End_Point_x, this->LeftUp_X.End_Point_y);
		//纵线的起点和终点
		this->LeftUp_Y.Start_Point_x = 108 + Start_Point_x_Y;
		this->LeftUp_Y.Start_Point_y = 150 + Start_Point_y_Y;
		this->LeftUp_Y.End_Point_x = 108 + End_Point_x_Y;
		this->LeftUp_Y.End_Point_y = 168 + End_Point_y_Y;
		//纵线
		MoveToEx(mdc, this->LeftUp_Y.Start_Point_x, this->LeftUp_Y.Start_Point_y, NULL);
		LineTo(mdc, this->LeftUp_Y.End_Point_x, this->LeftUp_Y.End_Point_y);
	}
	void MapLeftDown(HDC mdc,
		int Start_Point_x_X = 0, int Start_Point_y_X = 0, int End_Point_x_X = 0, int End_Point_y_X = 0, //横线
		int Start_Point_x_Y = 0, int Start_Point_y_Y = 0, int End_Point_x_Y = 0, int End_Point_y_Y = 0)//纵线
	{
		//横线的起点和终点
		this->LeftDown_X.Start_Point_x = 90 + Start_Point_x_X;
		this->LeftDown_X.Start_Point_y = 175 + Start_Point_y_X;
		this->LeftDown_X.End_Point_x = 108 + End_Point_x_X;
		this->LeftDown_X.End_Point_y = 175 + End_Point_y_X;
		//横线
		MoveToEx(mdc, this->LeftDown_X.Start_Point_x, this->LeftDown_X.Start_Point_y, NULL);
		LineTo(mdc, this->LeftDown_X.End_Point_x, this->LeftDown_X.End_Point_y);
		//纵线的起点和终点
		this->LeftDown_Y.Start_Point_x = 108 + Start_Point_x_Y;
		this->LeftDown_Y.Start_Point_y = 174 + Start_Point_y_Y;
		this->LeftDown_Y.End_Point_x = 108 + End_Point_x_Y;
		this->LeftDown_Y.End_Point_y = 192 + End_Point_y_Y;
		//纵线
		MoveToEx(mdc, this->LeftDown_Y.Start_Point_x, this->LeftDown_Y.Start_Point_y, NULL);
		LineTo(mdc, this->LeftDown_Y.End_Point_x, this->LeftDown_Y.End_Point_y);
	}
	void MapRightUp(HDC mdc,
		int Start_Point_x_X = 0, int Start_Point_y_X = 0, int End_Point_x_X = 0, int End_Point_y_X = 0, //横线
		int Start_Point_x_Y = 0, int Start_Point_y_Y = 0, int End_Point_x_Y = 0, int End_Point_y_Y = 0)//纵线
	{
		//横线的起点和终点
		this->RightUp_X.Start_Point_x = 115 + Start_Point_x_X;
		this->RightUp_X.Start_Point_y = 168 + Start_Point_y_X;
		this->RightUp_X.End_Point_x = 133 + End_Point_x_X;
		this->RightUp_X.End_Point_y = 168 + End_Point_y_X;
		//横线
		MoveToEx(mdc, this->RightUp_X.Start_Point_x, this->RightUp_X.Start_Point_y, NULL);
		LineTo(mdc, this->RightUp_X.End_Point_x, this->RightUp_X.End_Point_y);
		//纵线的起点和终点
		this->RightUp_Y.Start_Point_x = 115 + Start_Point_x_Y;
		this->RightUp_Y.Start_Point_y = 150 + Start_Point_y_Y;
		this->RightUp_Y.End_Point_x = 115 + End_Point_x_Y;
		this->RightUp_Y.End_Point_y = 168 + End_Point_y_Y;
		//纵线
		MoveToEx(mdc, this->RightUp_Y.Start_Point_x, this->RightUp_Y.Start_Point_y, NULL);
		LineTo(mdc, this->RightUp_Y.End_Point_x, this->RightUp_Y.End_Point_y);
	}
	void MapRightDown(HDC mdc,
		int Start_Point_x_X = 0, int Start_Point_y_X = 0, int End_Point_x_X = 0, int End_Point_y_X = 0, //横线
		int Start_Point_x_Y = 0, int Start_Point_y_Y = 0, int End_Point_x_Y = 0, int End_Point_y_Y = 0)//纵线
	{
		//横线的起点和终点
		this->RightDown_X.Start_Point_x = 115 + Start_Point_x_X;
		this->RightDown_X.Start_Point_y = 175 + Start_Point_y_X;
		this->RightDown_X.End_Point_x = 133 + End_Point_x_X;
		this->RightDown_X.End_Point_y = 175 + End_Point_y_X;
		//横线
		MoveToEx(mdc, this->RightDown_X.Start_Point_x, this->RightDown_X.Start_Point_y, NULL);
		LineTo(mdc, this->RightDown_X.End_Point_x, this->RightDown_X.End_Point_y);
		//纵线的起点和终点
		this->RightDown_Y.Start_Point_x = 115 + Start_Point_x_Y;
		this->RightDown_Y.Start_Point_y = 174 + Start_Point_y_Y;
		this->RightDown_Y.End_Point_x = 115 + End_Point_x_Y;
		this->RightDown_Y.End_Point_y = 192 + End_Point_y_Y;
		//纵线
		MoveToEx(mdc, this->RightDown_Y.Start_Point_x, this->RightDown_Y.Start_Point_y, NULL);
		LineTo(mdc, this->RightDown_Y.End_Point_x, this->RightDown_Y.End_Point_y);
	}

	void MapLeft(HDC mdc,
		int Start_Point_x_X = 0, int Start_Point_y_X = 0, int End_Point_x_X = 0, int End_Point_y_X = 0, //横线
		int Start_Point_x_Y = 0, int Start_Point_y_Y = 0, int End_Point_x_Y = 0, int End_Point_y_Y = 0)//纵线
	{
		MapLeftUp(mdc, Start_Point_x_X, Start_Point_y_X, End_Point_x_X, End_Point_y_X, Start_Point_x_Y, Start_Point_y_Y, End_Point_x_Y, End_Point_y_Y);
		MapLeftDown(mdc, Start_Point_x_X, Start_Point_y_X, End_Point_x_X, End_Point_y_X, Start_Point_x_Y, Start_Point_y_Y, End_Point_x_Y, End_Point_y_Y);
	}
	void MapRight(HDC mdc,
		int Start_Point_x_X = 0, int Start_Point_y_X = 0, int End_Point_x_X = 0, int End_Point_y_X = 0, //横线
		int Start_Point_x_Y = 0, int Start_Point_y_Y = 0, int End_Point_x_Y = 0, int End_Point_y_Y = 0)//纵线
	{
		MapRightUp(mdc, Start_Point_x_X, Start_Point_y_X, End_Point_x_X, End_Point_y_X, Start_Point_x_Y, Start_Point_y_Y, End_Point_x_Y, End_Point_y_Y);
		MapRightDown(mdc, Start_Point_x_X, Start_Point_y_X, End_Point_x_X, End_Point_y_X, Start_Point_x_Y, Start_Point_y_Y, End_Point_x_Y, End_Point_y_Y);
	}

	void RenderString(HDC mdc)
	{
		GoBitmap->DrawString_1(Font_Id, 90, 300, "楚 河", 0XFFFF00);
		GoBitmap->DrawString_1(Font_Id, 390, 300, "汉 界", 0XFFFF00);
	}
	void RenderLine(HDC mdc)
	{
		MapRight(mdc, -60, 60, -60, 60, -60, 60, -60, 60);
		MapLeft(mdc, 420,60, 420, 60, 420, 60, 420, 60);

		MapLeftUp(mdc, 0, 0, 0, 0, 0, 0, 0, 0);//           Default 左上 
		MapLeftDown(mdc, 0, 0, 0, 0, 0, 0, 0, 0);//      Default 左下
		MapRightUp(mdc, 0, 0, 0, 0, 0, 0, 0, 0);//         Default 左上
		MapRightDown(mdc, 0, 0, 0, 0, 0, 0, 0, 0);//    Default 左下

		MapLeftUp(mdc, 360, 0, 360, 0, 360, 0, 360, 0);
		MapLeftDown(mdc, 360, 0, 360, 0, 360, 0, 360, 0);
		MapRightUp(mdc, 360, 0, 360, 0, 360, 0, 360, 0);
		MapRightDown(mdc, 360, 0, 360, 0, 360, 0, 360, 0);

		MapLeftUp(mdc, 60, 60, 60, 60, 60, 60, 60, 60);
		MapLeftDown(mdc, 60, 60, 60, 60, 60, 60, 60, 60);
		MapRightUp(mdc, 60, 60, 60, 60, 60, 60, 60, 60);
		MapRightDown(mdc, 60, 60, 60, 60, 60, 60, 60, 60);

		MapLeftUp(mdc, 180, 60, 180, 60, 180, 60, 180, 60);
		MapLeftDown(mdc, 180, 60, 180, 60, 180, 60, 180, 60);
		MapRightUp(mdc, 180, 60, 180, 60, 180, 60, 180, 60);
		MapRightDown(mdc, 180, 60, 180, 60, 180, 60, 180, 60);

		MapLeftUp(mdc, 300, 60, 300, 60, 300, 60, 300, 60);
		MapLeftDown(mdc, 300, 60, 300, 60, 300, 60, 300, 60);
		MapRightUp(mdc, 300, 60, 300, 60, 300, 60, 300, 60);
		MapRightDown(mdc, 300, 60, 300, 60, 300, 60, 300, 60);
		//==========================================
		MapRight(mdc, -60, 240, -60, 240, -60, 240, -60, 240);
		MapLeft(mdc, 420, 240, 420, 240, 420, 240, 420, 240);

		MapLeftUp(mdc, 0, 300, 0, 300, 0, 300, 0, 300);
		MapLeftDown(mdc, 0, 300, 0, 300, 0, 300, 0, 300);
		MapRightUp(mdc, 0, 300, 0, 300, 0, 300, 0, 300);
		MapRightDown(mdc, 0, 300, 0, 300, 0, 300, 0, 300);

		MapLeftUp(mdc, 360, 300, 360, 300, 360, 300, 360, 300);
		MapLeftDown(mdc, 360, 300, 360, 300, 360, 300, 360, 300);
		MapRightUp(mdc, 360, 300, 360, 300, 360, 300, 360, 300);
		MapRightDown(mdc, 360, 300, 360, 300, 360, 300, 360, 300);

		MapLeftUp(mdc, 60, 240, 60, 240, 60, 240, 60, 240);
		MapLeftDown(mdc, 60, 240, 60, 240, 60, 240, 60, 240);
		MapRightUp(mdc, 60, 240, 60, 240, 60, 240, 60, 240);
		MapRightDown(mdc, 60, 240, 60, 240, 60, 240, 60, 240);

		MapLeftUp(mdc, 180, 240, 180, 240, 180, 240, 180, 240);
		MapLeftDown(mdc, 180, 240, 180, 240, 180, 240, 180, 240);
		MapRightUp(mdc, 180, 240, 180, 240, 180, 240, 180, 240);
		MapRightDown(mdc, 180, 240, 180, 240, 180, 240, 180, 240);

		MapLeftUp(mdc, 300, 240, 300, 240, 300, 240, 300, 240);
		MapLeftDown(mdc, 300, 240, 300, 240, 300, 240, 300, 240);
		MapRightUp(mdc, 300, 240, 300, 240, 300, 240, 300, 240);
		MapRightDown(mdc, 300, 240, 300, 240, 300, 240, 300, 240);

		//士的交叉路线
		MoveToEx(mdc, 230, 50, NULL);
		LineTo(mdc, 350, 170);
		MoveToEx(mdc, 352, 50, NULL);
		LineTo(mdc, 232, 170);

		MoveToEx(mdc, 230, 470, NULL);
		LineTo(mdc, 350, 590);
		MoveToEx(mdc, 352, 470, NULL);
		LineTo(mdc, 232, 590);
	}
	~Map()
	{
		GoBitmap->ReleaseBmp(Map_Bmpid);
		DeleteObject(hPen);
	}
};