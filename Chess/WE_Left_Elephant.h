#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//左边象
class WE_Left_Elephant:public Piece,public Piece_Logic
{
	int mElephant_Bmpid = 0;
	int mWE_Left_Elephant_X = 0;
	int mWE_Left_Elephant_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Elephant()
	{
		mWE_Left_Elephant_X = 170;
		mWE_Left_Elephant_Y = 590;
	}
	~WE_Left_Elephant()
	{
		GoBitmap->ReleaseBmp(mElephant_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mElephant_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Elephant.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Left_Elephant_X, mWE_Left_Elephant_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mElephant_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}

};