#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

class ENEMY_3_Soldier :public Piece, public Piece_Logic
{
	int mENEMY_3_Soldier_Bmpid = 0;
	float mENEMY_3_Soldier_X;
	float mENEMY_3_Soldier_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_3_Soldier()
	{
		mENEMY_3_Soldier_X = 410;
		mENEMY_3_Soldier_Y = 230;
	}
	~ENEMY_3_Soldier()
	{
		GoBitmap->ReleaseBmp(mENEMY_3_Soldier_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mENEMY_3_Soldier_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Soldier.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mENEMY_3_Soldier_X, mENEMY_3_Soldier_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_3_Soldier_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //棋子逻辑更新
	{

	}
};