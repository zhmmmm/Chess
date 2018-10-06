#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

class ENEMY_Right_Man :public Piece, public Piece_Logic
{
	int mENEMY_Right_Man_Bmpid = 0;
	float mENEMY_Right_Man_X;
	float mENEMY_Right_Man_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Right_Man()
	{
		mENEMY_Right_Man_X = 350;
		mENEMY_Right_Man_Y = 50;
	}
	~ENEMY_Right_Man()
	{
		GoBitmap->ReleaseBmp(mENEMY_Right_Man_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mENEMY_Right_Man_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Man.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mENEMY_Right_Man_X, mENEMY_Right_Man_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_Right_Man_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};