#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

class ENEMY_2_Soldier :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__
{
	int mENEMY_2_Soldier_Bmpid = 0;
	float mENEMY_2_Soldier_X;
	float mENEMY_2_Soldier_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_2_Soldier()
	{
		mENEMY_2_Soldier_X = 290;
		mENEMY_2_Soldier_Y = 230;
	}
	~ENEMY_2_Soldier()
	{
		GoBitmap->ReleaseBmp(mENEMY_2_Soldier_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mENEMY_2_Soldier_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Soldier.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mENEMY_2_Soldier_X, mENEMY_2_Soldier_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_2_Soldier_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{
		if (Piece::Reutrn_mWe() == 1)//1表示我可以走棋了
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mENEMY_2_Soldier_X - 30 && Mouse_X <= mENEMY_2_Soldier_X + 30
					&& Mouse_Y >= mENEMY_2_Soldier_Y - 30 && Mouse_Y <= mENEMY_2_Soldier_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 150;//小兵被锁定
					}
				}
				if (Piece_Logic::mWE_CommandState == 150)//小兵被锁定
				{
					BOOL BoolForward = FALSE;
					BOOL BoolLeft = FALSE;
					BOOL BoolRight = FALSE;
					BoolForward = _____Elephant__TO__Soldier__Logic__::ENEMY__Soldier_MoveForwardTarget(mENEMY_2_Soldier_X, mENEMY_2_Soldier_Y, Mouse_X, Mouse_Y);
					BoolLeft = _____Elephant__TO__Soldier__Logic__::ENEMY__Soldier_MoveLeftTarget(mENEMY_2_Soldier_X, mENEMY_2_Soldier_Y, Mouse_X, Mouse_Y);
					BoolRight = _____Elephant__TO__Soldier__Logic__::ENEMY__Soldier_MoveRightTarget(mENEMY_2_Soldier_X, mENEMY_2_Soldier_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_0_Sodier_Logic___(BoolForward, BoolLeft, BoolRight, Mouse_Y);
				}
			}
		}
	}
	int __WE_0_Sodier_Logic___(BOOL BoolForward, BOOL BoolLeft, BOOL BoolRight, int Mouse_Y)
	{
		if (BoolForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 150)
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j] != 999)//前面是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j];
							Piece_Logic::mMouseDownRange[i + 1][j] = Temp;

							mENEMY_2_Soldier_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 1;
		}
		if (BoolLeft)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 150)
					{
						if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i][j - 1] != 999)//前面是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - 1];
							Piece_Logic::mMouseDownRange[i][j - 1] = Temp;

							mENEMY_2_Soldier_X -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 2;
		}
		if (BoolRight)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 150)
					{
						if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i][j + 1] != 999)//前面是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + 1];
							Piece_Logic::mMouseDownRange[i][j + 1] = Temp;

							mENEMY_2_Soldier_X += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 3;
		}
		return 0;
	}
};