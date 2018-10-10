#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

class ENEMY_Right_Man :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__
{
	int mENEMY_Right_Man_Bmpid = 0;
	int mENEMY_Right_Man_X;
	int mENEMY_Right_Man_Y;



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
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{
		if (Piece::Reutrn_mWe() == 1)//1该敌方走棋了
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mENEMY_Right_Man_X - 30 && Mouse_X <= mENEMY_Right_Man_X + 30
					&& Mouse_Y >= mENEMY_Right_Man_Y - 30 && Mouse_Y <= mENEMY_Right_Man_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 40;//左边的士被锁定
					}
				}
				if (Piece_Logic::mWE_CommandState == 40)//左边的士被锁定
				{
					BOOL BoolLeftForward = FALSE;
					BoolLeftForward = _____Elephant__TO__Soldier__Logic__::Man_MoveForwardTarget(mENEMY_Right_Man_X, mENEMY_Right_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolRightForward = FALSE;
					BoolRightForward = _____Elephant__TO__Soldier__Logic__::Man_MoveBackTarget(mENEMY_Right_Man_X, mENEMY_Right_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeftBack = FALSE;
					BoolLeftBack = _____Elephant__TO__Soldier__Logic__::Man_MoveLeftTarget(mENEMY_Right_Man_X, mENEMY_Right_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolRightBack = FALSE;
					BoolRightBack = _____Elephant__TO__Soldier__Logic__::Man_MoveRightTarget(mENEMY_Right_Man_X, mENEMY_Right_Man_Y, Mouse_X, Mouse_Y);
					int TempVar = __ENEMY_Right_Man_Logic___(BoolLeftForward, BoolRightForward, BoolLeftBack, BoolRightBack);
				}
			}
		}
	}
	int __ENEMY_Right_Man_Logic___(BOOL BoolLeftForward, BOOL BoolRightForward, BOOL BoolLeftBack, BOOL BoolRightBack)
	{
		if (BoolLeftForward)//左前
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 40)//索引到敌方棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j - 1] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j - 1];
							Piece_Logic::mMouseDownRange[i - 1][j - 1] = Temp;

							mENEMY_Right_Man_X -= 60;
							mENEMY_Right_Man_Y -= 60;
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
		if (BoolRightForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 40)//索引到敌方棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j + 1] != 999)//主将后面是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j + 1];
							Piece_Logic::mMouseDownRange[i - 1][j + 1] = Temp;

							mENEMY_Right_Man_X += 60;
							mENEMY_Right_Man_Y -= 60;
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
		if (BoolLeftBack)//左后
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 40)//索引到敌方棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j - 1] != 999)//主将左边是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j - 1];
							Piece_Logic::mMouseDownRange[i + 1][j - 1] = Temp;


							mENEMY_Right_Man_X -= 60;
							mENEMY_Right_Man_Y += 60;
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
		if (BoolRightBack)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 40)//索引到敌方棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j + 1] != 999)//主将右边是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j + 1];
							Piece_Logic::mMouseDownRange[i + 1][j + 1] = Temp;

							mENEMY_Right_Man_X += 60;
							mENEMY_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 4;
		}
		return 0;
	}
};