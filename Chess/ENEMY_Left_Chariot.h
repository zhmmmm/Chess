#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

class ENEMY_Left_Chariot :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__
{
	int mENEMY_Left_Chariot_Bmpid = 0;
	float mENEMY_Left_Chariot_X;
	float mENEMY_Left_Chariot_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Left_Chariot()
	{
		mENEMY_Left_Chariot_X = 50;
		mENEMY_Left_Chariot_Y = 50;
	}
	~ENEMY_Left_Chariot()
	{
		GoBitmap->ReleaseBmp(mENEMY_Left_Chariot_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mENEMY_Left_Chariot_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Chariot.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mENEMY_Left_Chariot_X, mENEMY_Left_Chariot_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_Left_Chariot_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{
		if (Piece::Reutrn_mWe() == 1)//1表示我可以走棋了
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mENEMY_Left_Chariot_X - 30 && Mouse_X <= mENEMY_Left_Chariot_X + 30
					&& Mouse_Y >= mENEMY_Left_Chariot_Y - 30 && Mouse_Y <= mENEMY_Left_Chariot_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 90;//左边的車被锁定
					}
				}
				if (Piece_Logic::mWE_CommandState == 90)//左边的車被锁定
				{
					BOOL BoolForward = FALSE;
					BoolForward = _____Elephant__TO__Soldier__Logic__::Chariot_MoveForwardTarget(mENEMY_Left_Chariot_X, mENEMY_Left_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolBack = FALSE;
					BoolBack = _____Elephant__TO__Soldier__Logic__::Chariot_MoveBackTarget(mENEMY_Left_Chariot_X, mENEMY_Left_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeft = FALSE;
					BoolLeft = _____Elephant__TO__Soldier__Logic__::Chariot_MoveLeftTarget(mENEMY_Left_Chariot_X, mENEMY_Left_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolRight = FALSE;
					BoolRight = _____Elephant__TO__Soldier__Logic__::Chariot_MoveRightTarget(mENEMY_Left_Chariot_X, mENEMY_Left_Chariot_Y, Mouse_X, Mouse_Y);
					int TempVar = __ENEMY_Left_Chariot___(BoolForward, BoolBack, BoolLeft, BoolRight);
				}
			}
		}
	}
	int __ENEMY_Left_Chariot___(BOOL BoolForward, BOOL BoolBack, BOOL BoolLeft, BOOL BoolRight)
	{
		if (BoolForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == 90)//索引到棋子左边的車
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标

						int Move_Y = (mENEMY_Left_Chariot_Y - Temp_Y) / 60;//得到要移动的次数，同时也是目标的Y坐标

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
							if (IfOkMove && k == Move_Y - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - Move_Y][j];
								Piece_Logic::mMouseDownRange[i - Move_Y][j] = Temp;
								mENEMY_Left_Chariot_Y -= (Move_Y * 60);

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
					if (Piece_Logic::mMouseDownRange[i][j] == 90)//索引到棋子左边的車
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标

						int Move_Y = (Temp_Y - mENEMY_Left_Chariot_Y) / 60;//得到要移动的次数，同时也是目标的Y坐标

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
							if (IfOkMove && k == Move_Y - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + Move_Y][j];
								Piece_Logic::mMouseDownRange[i + Move_Y][j] = Temp;
								mENEMY_Left_Chariot_Y += (Move_Y * 60);

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
					if (Piece_Logic::mMouseDownRange[i][j] == 90)//索引到棋子左边的車
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标

						int Move_X = (mENEMY_Left_Chariot_X - Temp_X) / 60;//得到要移动的次数，同时也是目标的Y坐标

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
							if (IfOkMove && k == Move_X - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - Move_X];
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Temp;
								mENEMY_Left_Chariot_X -= (Move_X * 60);

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
					if (Piece_Logic::mMouseDownRange[i][j] == 90)//索引到棋子左边的車
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标

						int Move_X = (Temp_X - mENEMY_Left_Chariot_X) / 60;//得到要移动的次数，同时也是目标的Y坐标

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
							if (IfOkMove && k == Move_X - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + Move_X];
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Temp;
								mENEMY_Left_Chariot_X += (Move_X * 60);

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