#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//左边的車
class WE_Left_Chariot :public Piece, public Piece_Logic
{
	int mChariot_Bmpid = 0;
	int mWE_Left_Chariot_X = 0;
	int mWE_Left_Chariot_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Chariot()
	{
		mWE_Left_Chariot_X = 50;
		mWE_Left_Chariot_Y = 590;
	}
	~WE_Left_Chariot()
	{
		GoBitmap->ReleaseBmp(mChariot_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mChariot_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Chariot.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Left_Chariot_X, mWE_Left_Chariot_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mChariot_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};