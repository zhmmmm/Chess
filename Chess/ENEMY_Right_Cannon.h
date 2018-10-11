#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"
#include "ENEMY_Command.h"

class ENEMY_Right_Cannon :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__,public ENEMY_Command
{
	int mENEMY_Right_Cannon_Bmpid = 0;
	float mENEMY_Right_Cannon_X;
	float mENEMY_Right_Cannon_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Right_Cannon()
	{
		mENEMY_Right_Cannon_X = 470;
		mENEMY_Right_Cannon_Y = 170;
	}
	~ENEMY_Right_Cannon()
	{
		GoBitmap->ReleaseBmp(mENEMY_Right_Cannon_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mENEMY_Right_Cannon_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Cannon.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mENEMY_Right_Cannon_X, mENEMY_Right_Cannon_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_Right_Cannon_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{
		if (Piece::Reutrn_mWe() == 1)//1表示我可以走棋了
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mENEMY_Right_Cannon_X - 30 && Mouse_X <= mENEMY_Right_Cannon_X + 30
					&& Mouse_Y >= mENEMY_Right_Cannon_Y - 30 && Mouse_Y <= mENEMY_Right_Cannon_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 110;//右边的炮被锁定
					}
				}
				if (Piece_Logic::mWE_CommandState == 110)//右边的炮被锁定
				{
					BOOL BoolForward = FALSE;
					BoolForward = _____Elephant__TO__Soldier__Logic__::Cannon_MoveForwardTarget(mENEMY_Right_Cannon_X, mENEMY_Right_Cannon_Y, Mouse_X, Mouse_Y);
					BOOL BoolBack = FALSE;
					BoolBack = _____Elephant__TO__Soldier__Logic__::Cannon_MoveBackTarget(mENEMY_Right_Cannon_X, mENEMY_Right_Cannon_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeft = FALSE;
					BoolLeft = _____Elephant__TO__Soldier__Logic__::Cannon_MoveLeftTarget(mENEMY_Right_Cannon_X, mENEMY_Right_Cannon_Y, Mouse_X, Mouse_Y);
					BOOL BoolRight = FALSE;
					BoolRight = _____Elephant__TO__Soldier__Logic__::Cannon_MoveRightTarget(mENEMY_Right_Cannon_X, mENEMY_Right_Cannon_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_Right_Cannon_Logic___(BoolForward, BoolBack, BoolLeft, BoolRight);
				}
			}
		}
	}
	int __WE_Right_Cannon_Logic___(BOOL BoolForward, BOOL BoolBack, BOOL BoolLeft, BOOL BoolRight)
	{
		if (BoolForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == 110)//索引到棋子右边的炮
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//得到鼠标点击的标准坐标

						int Move_Y = (mENEMY_Right_Cannon_Y - Temp_Y) / 60;//得到要移动的次数，同时也是目标的Y坐标

						for (int k = 0; k < Move_Y; k++)//进行巡路是否可以行走，可以走多少
						{
							if (Piece_Logic::mMouseDownRange[i - (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 999)
							{
								IfOkMove = true;
							}
							else
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove == false) //只要是一次false就是不行的
							{
								break;
							}
							if (true)
							{
								//这里可以判断炮可以吃棋了
							}
							if (IfOkMove && k == Move_Y - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - Move_Y][j];
								Piece_Logic::mMouseDownRange[i - Move_Y][j] = Temp;
								mENEMY_Right_Cannon_Y -= (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
						}
					}
				}
				if (ifok) { break; }
			}
			return 1;
		}
		if (BoolBack)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == 110)//索引到棋子右边的炮
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//得到鼠标点击的标准坐标

						int Move_Y = (Temp_Y - mENEMY_Right_Cannon_Y) / 60;//得到要移动的次数，同时也是目标的Y坐标

						for (int k = 0; k < Move_Y; k++)//进行巡路是否可以行走，可以走多少
						{
							if (Piece_Logic::mMouseDownRange[i + (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 999)
							{
								IfOkMove = true;
							}
							else
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove == false) //只要是一次false就是不行的
							{
								break;
							}
							if (true)
							{
								//这里可以判断炮可以吃棋了
							}
							if (IfOkMove && k == Move_Y - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + Move_Y][j];
								Piece_Logic::mMouseDownRange[i + Move_Y][j] = Temp;
								mENEMY_Right_Cannon_Y += (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
						}
					}
				}
				if (ifok) { break; }
			}
			return 2;
		}
		if (BoolLeft)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == 110)//索引到棋子右边的炮
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//得到鼠标点击的标准坐标

						int Move_X = (mENEMY_Right_Cannon_X - Temp_X) / 60;//得到要移动的次数，同时也是目标的Y坐标

						for (int k = 0; k < Move_X; k++)//进行巡路是否可以行走，可以走多少
						{
							if (Piece_Logic::mMouseDownRange[i][j - (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 999)
							{
								IfOkMove = true;
							}
							else
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove == false) //只要是一次false就是不行的
							{
								break;
							}
							if (true)
							{
								//这里可以判断炮可以吃棋了
							}
							if (IfOkMove && k == Move_X - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - Move_X];
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Temp;
								mENEMY_Right_Cannon_X -= (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
						}
					}
				}
				if (ifok) { break; }
			}
			return 3;
		}
		if (BoolRight)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == 110)//索引到棋子右边的炮
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//得到鼠标点击的标准坐标

						int Move_X = (Temp_X - mENEMY_Right_Cannon_X) / 60;//得到要移动的次数，同时也是目标的Y坐标

						for (int k = 0; k < Move_X; k++)//进行巡路是否可以行走，可以走多少
						{
							if (Piece_Logic::mMouseDownRange[i][j + (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 999)
							{
								IfOkMove = true;
							}
							else
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove == false) //只要是一次false就是不行的
							{
								break;
							}
							if (true)
							{
								//这里可以判断炮可以吃棋了
							}
							if (IfOkMove && k == Move_X - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + Move_X];
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Temp;
								mENEMY_Right_Cannon_X += (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
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