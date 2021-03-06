#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "WE_Left_Man_Logic.h"

//左边的士
class WE_Left_Man:public Piece,public Piece_Logic,public WE_Left_Man_Logic
{
	int mWE_Left_Man_Bmpid = 0;
	int mWE_Left_Man_State = 0;
	int mWE_Left_Man_X = 0;
	int mWE_Left_Man_Y = 0;



	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Man() 
	{
		mWE_Left_Man_X = 230;
		mWE_Left_Man_Y = 590;
	}
	~WE_Left_Man() 
	{
		GoBitmap->ReleaseBmp(mWE_Left_Man_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mWE_Left_Man_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Man.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Left_Man_X, mWE_Left_Man_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mWE_Left_Man_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{
		if (Piece::Reutrn_mWe() == 0)//0表示我可以走棋了
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mWE_Left_Man_X - 30 && Mouse_X <= mWE_Left_Man_X + 30
					&& Mouse_Y >= mWE_Left_Man_Y - 30 && Mouse_Y <= mWE_Left_Man_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 6;//左边的士被锁定
					}
				}
				if (Piece_Logic::mWE_CommandState == 6)//左边的士被锁定
				{
					BOOL BoolLeftForward = FALSE;
					//BoolLeftForward = _____Elephant__TO__Soldier__Logic__::Man_MoveForwardTarget(mWE_Left_Man_X, mWE_Left_Man_Y,Mouse_X,Mouse_Y);
					//这样用也可以
					BoolLeftForward = WE_Left_Man_Logic::Man_MoveForwardTarget(mWE_Left_Man_X, mWE_Left_Man_Y,Mouse_X,Mouse_Y);
					BOOL BoolRightForward = FALSE;
					BoolRightForward = WE_Left_Man_Logic::Man_MoveBackTarget(mWE_Left_Man_X, mWE_Left_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeftBack = FALSE;
					BoolLeftBack = WE_Left_Man_Logic::Man_MoveLeftTarget(mWE_Left_Man_X, mWE_Left_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolRightBack = FALSE;
					BoolRightBack = WE_Left_Man_Logic::Man_MoveRightTarget(mWE_Left_Man_X, mWE_Left_Man_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_Left_Man_Logic___(BoolLeftForward, BoolRightForward, BoolLeftBack, BoolRightBack);
				}
			}
		}
	}
	int __WE_Left_Man_Logic___(BOOL BoolLeftForward, BOOL BoolRightForward, BOOL BoolLeftBack, BOOL BoolRightBack)
	{
		__BoolLeftForward(BoolLeftForward, mWE_Left_Man_X, mWE_Left_Man_Y, 6);
		__BoolRightForward(BoolRightForward, mWE_Left_Man_X, mWE_Left_Man_Y, 6);
		__BoolLeftBack(BoolLeftBack, mWE_Left_Man_X, mWE_Left_Man_Y, 6);
		__BoolRightBack(BoolRightBack, mWE_Left_Man_X, mWE_Left_Man_Y, 6);
		return 0;
	}
	int __BoolLeftForward(BOOL BoolLeftForward, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code)
	{
		if (BoolLeftForward)//左前
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j - 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i - 1][j - 1] > 17 && Piece_Logic::mMouseDownRange[i - 1][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j - 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 1][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j - 1] != 999)//主将前面是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j - 1];
							Piece_Logic::mMouseDownRange[i - 1][j - 1] = Temp;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 1;
		}
		return 0;
	}
	int __BoolRightForward(BOOL BoolRightForward, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code)
	{
		if (BoolRightForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j + 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i - 1][j + 1] > 17 && Piece_Logic::mMouseDownRange[i - 1][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j + 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 1][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j + 1] != 999)//主将后面是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j + 1];
							Piece_Logic::mMouseDownRange[i - 1][j + 1] = Temp;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
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
	int __BoolLeftBack(BOOL BoolLeftBack, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code)
	{
		if (BoolLeftBack)//左后
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j - 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i + 1][j - 1] > 17 && Piece_Logic::mMouseDownRange[i + 1][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j - 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 1][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j - 1] != 999)//主将左边是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j - 1];
							Piece_Logic::mMouseDownRange[i + 1][j - 1] = Temp;


							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
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
	int __BoolRightBack(BOOL BoolRightBack, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code)
	{
		if (BoolRightBack)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//索引到棋子左边的士
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j + 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i + 1][j + 1] > 17 && Piece_Logic::mMouseDownRange[i + 1][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j + 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 1][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j + 1] != 999)//主将右边是空地
						{
							//在移动完了之后重新设置将军的坐标
							int Temp = mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j + 1];
							Piece_Logic::mMouseDownRange[i + 1][j + 1] = Temp;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//这里重要
							Piece::Change_mWe(1);
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