#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

class ENEMY_Left_Elephant:public Piece,public Piece_Logic
{
	int mENEMY_Left_Elephant_Bmpid = 0;
	float mENEMY_Left_Elephant_X;
	float mENEMY_Left_Elephant_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Left_Elephant()
	{
		mENEMY_Left_Elephant_X = 170;
		mENEMY_Left_Elephant_Y = 50;
	}
	~ENEMY_Left_Elephant()
	{
		GoBitmap->ReleaseBmp(mENEMY_Left_Elephant_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mENEMY_Left_Elephant_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Elephant.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mENEMY_Left_Elephant_X, mENEMY_Left_Elephant_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_Left_Elephant_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};