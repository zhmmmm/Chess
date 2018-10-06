#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//小兵 3
class WE_3_Soldier :public Piece, public Piece_Logic
{
	int mWE_3_Soldier_Bmpid = 0;

	int mWE_3_Soldier_X = 0;
	int mWE_3_Soldier_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_3_Soldier()
	{
		mWE_3_Soldier_X = 410;
		mWE_3_Soldier_Y = 410;
	}
	~WE_3_Soldier()
	{
		GoBitmap->ReleaseBmp(mWE_3_Soldier_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mWE_3_Soldier_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Soldier.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_3_Soldier_X, mWE_3_Soldier_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mWE_3_Soldier_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};