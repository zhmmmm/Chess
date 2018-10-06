#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"


////继承了棋子和棋子逻辑
class ENEMY_Command :public Piece,public Piece_Logic //敌方主帅
{
	int mCommand_Bmpid = 0;
	float mCommand_X = 0;
	float mCommand_Y = 0;


	float temp = 0.0f;


	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Command()
	{
		mCommand_X = 290.0f;
		mCommand_Y = 50.0f;
	}
	~ENEMY_Command()
	{
		GoBitmap->ReleaseBmp(mCommand_Bmpid);
	}
	void InitPiece()
	{
		mCommand_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Command.bmp");
	}
	void RenderPiece()
	{
		m.Rotate_d(temp).Translate(mCommand_X, mCommand_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mCommand_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)
	{
		//if (State == 1)
		//{
		//	temp += 6.0f;
		//}
	}
};