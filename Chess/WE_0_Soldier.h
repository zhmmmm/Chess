#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//小兵 0 
class WE_0_Soldier :public Piece, public Piece_Logic
{
	int mWE_0_Soldier_Bmpid = 0;

	int mWE_0_Soldier_X = 0;
	int mWE_0_Soldier_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_0_Soldier()
	{
		mWE_0_Soldier_X = 50;
		mWE_0_Soldier_Y = 410;
	}
	~WE_0_Soldier()
	{
		GoBitmap->ReleaseBmp(mWE_0_Soldier_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mWE_0_Soldier_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Soldier.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_0_Soldier_X, mWE_0_Soldier_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mWE_0_Soldier_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};