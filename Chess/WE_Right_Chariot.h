#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

//右边的車
class WE_Right_Chariot :public Piece, public Piece_Logic,public _____Elephant__TO__Soldier__Logic__
{
	int mChariot_Bmpid = 0;
	int mWE_Right_Chariot_X = 0;
	int mWE_Right_Chariot_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Right_Chariot()
	{
		mWE_Right_Chariot_X = 530;
		mWE_Right_Chariot_Y = 590;
	}
	~WE_Right_Chariot()
	{
		GoBitmap->ReleaseBmp(mChariot_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mChariot_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Chariot.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Right_Chariot_X, mWE_Right_Chariot_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mChariot_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{

	}
};