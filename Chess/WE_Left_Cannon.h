#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//左边的炮
class WE_Left_Cannon :public Piece, public Piece_Logic
{
	int mCannon_Bmpid = 0;
	int mWE_Left_Cannon_X = 0;
	int mWE_Left_Cannon_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Cannon()
	{
		mWE_Left_Cannon_X = 110;
		mWE_Left_Cannon_Y = 470;
	}
	~WE_Left_Cannon()
	{
		GoBitmap->ReleaseBmp(mCannon_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mCannon_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Cannon.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Left_Cannon_X, mWE_Left_Cannon_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mCannon_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};