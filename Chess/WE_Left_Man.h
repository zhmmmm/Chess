#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//左边的士
class WE_Left_Man:public Piece,public Piece_Logic
{
	int mWE_Left_Man_Bmpid = 0;

	int mWE_Left_Man_X = 0;
	int mWE_Left_Man_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Man() 
	{
		mWE_Left_Man_X = 230;
		mWE_Left_Man_Y = 590;
	}
	~WE_Left_Man() 
	{
		GoBitmap->ReleaseBmp(mWE_Left_Man_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mWE_Left_Man_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Man.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Left_Man_X, mWE_Left_Man_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mWE_Left_Man_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};