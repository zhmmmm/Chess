#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//右边的马
class WE_Right_Horse :public Piece, public Piece_Logic
{
	int mHorse_Bmpid = 0;
	int mWE_Right_Horse_X = 0;
	int mWE_Right_Horse_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Right_Horse()
	{
		mWE_Right_Horse_X = 470;
		mWE_Right_Horse_Y = 590;
	}
	~WE_Right_Horse()
	{
		GoBitmap->ReleaseBmp(mHorse_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mHorse_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Horse.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Right_Horse_X, mWE_Right_Horse_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mHorse_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};