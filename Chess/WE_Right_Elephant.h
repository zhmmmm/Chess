#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//右边象
class WE_Right_Elephant :public Piece, public Piece_Logic
{
	int mElephant_Bmpid = 0;
	int mWE_Right_Elephant_X = 0;
	int mWE_Right_Elephant_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Right_Elephant()
	{
		mWE_Right_Elephant_X = 410;
		mWE_Right_Elephant_Y = 590;
	}
	~WE_Right_Elephant()
	{
		GoBitmap->ReleaseBmp(mElephant_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mElephant_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Elephant.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Right_Elephant_X, mWE_Right_Elephant_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mElephant_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}

};