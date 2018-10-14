#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

class ENEMY_Right_Horse:public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__
{
	int mENEMY_Right_Horse_Bmpid = 0;
	int mENEMY_Right_Horse_X;
	int mENEMY_Right_Horse_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Right_Horse()
	{
		mENEMY_Right_Horse_X = 470;
		mENEMY_Right_Horse_Y = 50;
	}
	~ENEMY_Right_Horse()
	{
		GoBitmap->ReleaseBmp(mENEMY_Right_Horse_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mENEMY_Right_Horse_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Horse.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_Right_Horse_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{
		if (Piece::Reutrn_mWe() == 1)//1表示我可以走棋了
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mENEMY_Right_Horse_X - 30 && Mouse_X <= mENEMY_Right_Horse_X + 30
					&& Mouse_Y >= mENEMY_Right_Horse_Y - 30 && Mouse_Y <= mENEMY_Right_Horse_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 20;//右边的马被锁定
					}
				}
				if (Piece_Logic::mWE_CommandState == 20)//右边的马被锁定
				{
					BOOL Bool_0_LeftForward = FALSE;
					BOOL Bool_1_RightForward = FALSE;
					BOOL Bool_2_LeftBack = FALSE;
					BOOL Bool_3_RightBack = FALSE;
					BOOL Bool_4_LeftForward = FALSE;
					BOOL Bool_5_RightForward = FALSE;
					BOOL Bool_6_LeftBack = FALSE;
					BOOL Bool_7_RightBack = FALSE;
					Bool_0_LeftForward = _____Elephant__TO__Soldier__Logic__::_0__Horse_MoveForwardTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_1_RightForward = _____Elephant__TO__Soldier__Logic__::_1__Horse_MoveBackTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_2_LeftBack = _____Elephant__TO__Soldier__Logic__::_2__Horse_MoveLeftTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_3_RightBack = _____Elephant__TO__Soldier__Logic__::_3__Horse_MoveRightTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_4_LeftForward = _____Elephant__TO__Soldier__Logic__::_4__Horse_MoveForwardTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_5_RightForward = _____Elephant__TO__Soldier__Logic__::_5__Horse_MoveBackTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_6_LeftBack = _____Elephant__TO__Soldier__Logic__::_6__Horse_MoveLeftTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_7_RightBack = _____Elephant__TO__Soldier__Logic__::_7__Horse_MoveRightTarget(mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_Right_Horse_Logic___(Bool_0_LeftForward, Bool_1_RightForward, Bool_2_LeftBack, Bool_3_RightBack, Bool_4_LeftForward, Bool_5_RightForward, Bool_6_LeftBack, Bool_7_RightBack);
				}
			}
		}
	}
	int __WE_Right_Horse_Logic___(BOOL Bool_0_LeftForward, BOOL Bool_1_RightForward, BOOL Bool_2_LeftBack, BOOL Bool_3_RightBack,
		BOOL Bool_4_LeftForward, BOOL Bool_5_RightForward, BOOL Bool_6_LeftBack, BOOL Bool_7_RightBack)
	{
		__Bool_0_LeftForward(Bool_0_LeftForward, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		__Bool_1_RightForward(Bool_1_RightForward, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		__Bool_2_LeftBack(Bool_2_LeftBack, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		__Bool_3_RightBack(Bool_3_RightBack, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		//后面
		__Bool_4_LeftForward(Bool_4_LeftForward, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		__Bool_5_RightForward(Bool_5_RightForward, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		__Bool_6_LeftBack(Bool_6_LeftBack, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		__Bool_7_RightBack(Bool_7_RightBack, mENEMY_Right_Horse_X, mENEMY_Right_Horse_Y, 20);
		return 0;
	}
	int __Bool_0_LeftForward(BOOL Bool_0_LeftForward, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_0_LeftForward)//左前
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的马
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j] >= 200
							&& (Piece_Logic::mMouseDownRange[i - 2][j - 1] != 10 && (Piece_Logic::mMouseDownRange[i - 2][j - 1] <= 17
								&& Piece_Logic::mMouseDownRange[i - 2][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 2][j - 1] != 999)))
						{
							Piece_Logic::mMouseDownRange[i - 2][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X -= 60;
							mWE_Left_Horse_Y -= 120;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j - 1] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 2][j - 1];
							Piece_Logic::mMouseDownRange[i - 2][j - 1] = Temp;

							mWE_Left_Horse_X -= 60;
							mWE_Left_Horse_Y -= 120;
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
	}
	int __Bool_1_RightForward(BOOL Bool_1_RightForward, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_1_RightForward)//右前
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子右边的马
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j] >= 200
							&& (Piece_Logic::mMouseDownRange[i - 2][j + 1] != 10 && (Piece_Logic::mMouseDownRange[i - 2][j + 1] <= 17
								&& Piece_Logic::mMouseDownRange[i - 2][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 2][j + 1] != 999)))
						{
							Piece_Logic::mMouseDownRange[i - 2][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X += 60;
							mWE_Left_Horse_Y -= 120;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j + 1] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 2][j + 1];
							Piece_Logic::mMouseDownRange[i - 2][j + 1] = Temp;

							mWE_Left_Horse_X += 60;
							mWE_Left_Horse_Y -= 120;
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
		return 0;
	}
	int __Bool_2_LeftBack(BOOL Bool_2_LeftBack, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_2_LeftBack)//左前2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的马
					{
						if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200
							&& (Piece_Logic::mMouseDownRange[i - 1][j - 2] != 10 && (Piece_Logic::mMouseDownRange[i - 1][j - 2] <= 17
								&& Piece_Logic::mMouseDownRange[i - 1][j - 2] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j - 2] != 999)))
						{
							Piece_Logic::mMouseDownRange[i - 1][j - 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X -= 120;
							mWE_Left_Horse_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j - 2] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j - 2] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j - 2];
							Piece_Logic::mMouseDownRange[i - 1][j - 2] = Temp;

							mWE_Left_Horse_X -= 120;
							mWE_Left_Horse_Y -= 60;
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
	int __Bool_3_RightBack(BOOL Bool_3_RightBack, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_3_RightBack)//右前2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的马
					{
						if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200
							&& (Piece_Logic::mMouseDownRange[i - 1][j + 2] != 10 && (Piece_Logic::mMouseDownRange[i - 1][j + 2] <= 17
								&& Piece_Logic::mMouseDownRange[i - 1][j + 2] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j + 2] != 999)))
						{
							Piece_Logic::mMouseDownRange[i - 1][j + 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X += 120;
							mWE_Left_Horse_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j + 2] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j + 2] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j + 2];
							Piece_Logic::mMouseDownRange[i - 1][j + 2] = Temp;

							mWE_Left_Horse_X += 120;
							mWE_Left_Horse_Y -= 60;
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
	int __Bool_4_LeftForward(BOOL Bool_4_LeftForward, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_4_LeftForward)//左后
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的马
					{
						if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200
							&& (Piece_Logic::mMouseDownRange[i + 1][j - 2] != 10 && (Piece_Logic::mMouseDownRange[i + 1][j - 2] <= 17
								&& Piece_Logic::mMouseDownRange[i + 1][j - 2] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j - 2] != 999)))
						{
							Piece_Logic::mMouseDownRange[i + 1][j - 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X -= 120;
							mWE_Left_Horse_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j - 2] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j - 1] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j - 2];
							Piece_Logic::mMouseDownRange[i + 1][j - 2] = Temp;

							mWE_Left_Horse_X -= 120;
							mWE_Left_Horse_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 5;
		}
		return 0;
	}
	int __Bool_5_RightForward(BOOL Bool_5_RightForward, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_5_RightForward)//右后
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子右边的马
					{
						if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200
							&& (Piece_Logic::mMouseDownRange[i + 1][j + 2] != 10 && (Piece_Logic::mMouseDownRange[i + 1][j + 2] <= 17
								&& Piece_Logic::mMouseDownRange[i + 1][j + 2] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j + 2] != 999)))
						{
							Piece_Logic::mMouseDownRange[i + 1][j + 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X += 120;
							mWE_Left_Horse_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j + 2] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j + 1] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j + 2];
							Piece_Logic::mMouseDownRange[i + 1][j + 2] = Temp;

							mWE_Left_Horse_X += 120;
							mWE_Left_Horse_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 6;
		}
		return 0;
	}
	int __Bool_6_LeftBack(BOOL Bool_6_LeftBack, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_6_LeftBack)//左后2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的马
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200
							&& (Piece_Logic::mMouseDownRange[i + 2][j - 1] != 10 && (Piece_Logic::mMouseDownRange[i + 2][j - 1] <= 17
								&& Piece_Logic::mMouseDownRange[i + 2][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 2][j - 1] != 999)))
						{
							Piece_Logic::mMouseDownRange[i + 2][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X -= 60;
							mWE_Left_Horse_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j - 2] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 2][j - 1];
							Piece_Logic::mMouseDownRange[i + 2][j - 1] = Temp;

							mWE_Left_Horse_X -= 60;
							mWE_Left_Horse_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 7;
		}
		return 0;
	}
	int __Bool_7_RightBack(BOOL Bool_7_RightBack, int &mWE_Left_Horse_X, int &mWE_Left_Horse_Y, int Piece_Code)
	{
		if (Bool_7_RightBack)//右后2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的马
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200
							&& (Piece_Logic::mMouseDownRange[i + 2][j + 1] != 10 && (Piece_Logic::mMouseDownRange[i + 2][j + 1] <= 17
								&& Piece_Logic::mMouseDownRange[i + 2][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 2][j + 1] != 999)))
						{
							Piece_Logic::mMouseDownRange[i + 2][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Left_Horse_X += 60;
							mWE_Left_Horse_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j + 2] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置马的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 2][j + 1];
							Piece_Logic::mMouseDownRange[i + 2][j + 1] = Temp;

							mWE_Left_Horse_X += 60;
							mWE_Left_Horse_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(0);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 8;
		}
		return 0;
	}
};