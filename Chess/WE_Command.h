#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//继承了棋子和棋子逻辑
class WE_Command :public Piece, public Piece_Logic//棋子，我方主将
{
	int mCommand_Bmpid = 0;
	float mCommand_X;
	float mCommand_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Command()
	{
		mCommand_X = 290;
		mCommand_Y = 590;
	}
	~WE_Command()
	{
		GoBitmap->ReleaseBmp(mCommand_Bmpid);
	}
	void InitPiece()
	{
		mCommand_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Command.bmp");
	}
	void RenderPiece()
	{
		m.Translate(mCommand_X, mCommand_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mCommand_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);

	}
	void PieceLogicUpdata(int Which, int State, int x, int y)
	{
		if (Piece::Reutrn_mWe() == 0)
		{
			Piece_Logic::RenderBlue_Cursor();
			Piece_Logic::__Piece_Logic__(Which, State, x, y);

			//前
			if (Piece_Logic::__Return__ReturnCommand_State_Y() < 0)
			{
				for (int i = 1; i <= 2; i++)
				{
					if (Piece_Logic::__Return__ReturnCommand_State_Y() + i == 0)//表示往X轴的左边移动一个刻度
					{
						mCommand_Y -= 60;
						Piece::Change_mWe(1);
						Piece_Logic::__WE__mWE_CommandState(0);
						Piece_Logic::__Change__ReturnCommand_State_Y(0);
						break;
					}
				}
			}
			//后
			if (Piece_Logic::__Return__ReturnCommand_State_Y() > 0)
			{
				for (int i = 1; i <= 2; i++)
				{
					if (Piece_Logic::__Return__ReturnCommand_State_Y() - i == 0)//表示往X轴的左边移动一个刻度
					{
						mCommand_Y += 60;
						Piece_Logic::__WE__mWE_CommandState(0);
						Piece_Logic::__Change__ReturnCommand_State_Y(0);
						break;
					}
				}
			}
			//左
			if (Piece_Logic::__Return__ReturnCommand_State_X() < 0)
			{
				for (int i = 1; i <= 2; i++)
				{
					if (Piece_Logic::__Return__ReturnCommand_State_X() + i == 0)//表示往X轴的左边移动一个刻度
					{
						mCommand_X -= 60;
						Piece_Logic::__WE__mWE_CommandState(0);
						Piece_Logic::__Change__ReturnCommand_State_X(0);
						break;
					}
				}
			}
			//右
			if (Piece_Logic::__Return__ReturnCommand_State_X() > 0)
			{
				for (int i = 1; i <= 2; i++)
				{
					int temp = Piece_Logic::__Return__ReturnCommand_State_X();
					if (Piece_Logic::__Return__ReturnCommand_State_X() - i == 0)//表示往X轴的左边移动一个刻度
					{
						mCommand_X += 60;
						Piece_Logic::__WE__mWE_CommandState(0);
						Piece_Logic::__Change__ReturnCommand_State_X(0);
						break;
					}
				}
			}

		}//
	}
};