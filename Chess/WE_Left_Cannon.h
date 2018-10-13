#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

//左边的炮
class WE_Left_Cannon :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__
{
	int mCannon_Bmpid = 0;
	int mWE_Left_Cannon_X = 0;
	int mWE_Left_Cannon_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Cannon()
	{
		mWE_Left_Cannon_X = 110;
		mWE_Left_Cannon_Y = 470;
	}
	~WE_Left_Cannon()
	{
		GoBitmap->ReleaseBmp(mCannon_Bmpid);
	}
	void InitPiece()                    //加载棋子
	{
		mCannon_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Cannon.bmp");
	}
	void RenderPiece()            //渲染棋子
	{
		m.Translate(mWE_Left_Cannon_X, mWE_Left_Cannon_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mCannon_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //棋子逻辑更新
	{
		if (Piece::Reutrn_mWe() == 0)//0表示我可以走棋了
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mWE_Left_Cannon_X - 30 && Mouse_X <= mWE_Left_Cannon_X + 30
					&& Mouse_Y >= mWE_Left_Cannon_Y - 30 && Mouse_Y <= mWE_Left_Cannon_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 12;//左边的炮被锁定
					}
				}
				if (Piece_Logic::mWE_CommandState == 12)//左边的炮被锁定
				{
					BOOL BoolForward = FALSE;
					BoolForward = _____Elephant__TO__Soldier__Logic__::Cannon_MoveForwardTarget(mWE_Left_Cannon_X, mWE_Left_Cannon_Y, Mouse_X, Mouse_Y);
					BOOL BoolBack = FALSE;
					BoolBack = _____Elephant__TO__Soldier__Logic__::Cannon_MoveBackTarget(mWE_Left_Cannon_X, mWE_Left_Cannon_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeft = FALSE;
					BoolLeft = _____Elephant__TO__Soldier__Logic__::Cannon_MoveLeftTarget(mWE_Left_Cannon_X, mWE_Left_Cannon_Y, Mouse_X, Mouse_Y);
					BOOL BoolRight = FALSE;
					BoolRight = _____Elephant__TO__Soldier__Logic__::Cannon_MoveRightTarget(mWE_Left_Cannon_X, mWE_Left_Cannon_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_Left_Cannon_Logic___(BoolForward, BoolBack, BoolLeft, BoolRight);
				}
			}
		}
	}
	int __WE_Left_Cannon_Logic___(BOOL BoolForward, BOOL BoolBack, BOOL BoolLeft, BOOL BoolRight)
	{
		if (BoolForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//索引到棋子左边的炮
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标
						int Move_Y = (mWE_Left_Cannon_Y - Temp_Y) / 60;//得到要移动的次数，同时也是目标的Y坐标
						int Index = 0;//通过这个索引来执行吃棋
						int Index_I = 0;//记录索引到的第一个棋
						int Index_J = 0;//记录索引到的第一个棋
						int Index_I_J = 0;//记录索引到的第一个棋的次数
						int Index_N = 0;//记录从索引到第一个棋的又开始索引的棋子个数是否违反规则
						int Index_N_I = 0;//记录索引了几次才索引到被攻击的棋子
						int Index_Frequency = 0;//保证只执行一次
						for (int k = 0; k < Move_Y; k++)//进行巡路是否可以行走，可以走多少
						{
							Index_I_J++;//记录索引到的第一个棋的次数
							if ((Piece_Logic::mMouseDownRange[i - (k + 1)][j] == 10) || //这里是車的原因，保证索引到的是敌方的并且只隔开一个棋子
								(Piece_Logic::mMouseDownRange[i - (k + 1)][j] < 200 &&
									Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 999))
							{
								if (Index_Frequency == 0)//保证只执行一次
								{
									Index++;//只要是棋子,不管敌方还是我方，都能作为桥梁
									Index_I = (i - (k + 1));//记录索引到的第一个桥梁
									Index_J = j;//记录索引到的第一个桥梁
									if (Index == 1)//通过这个桥梁找敌方棋子
									{
										for (int n = 0; n <= Move_Y - Index_I_J - 1; n++)//通过剩下的所有的索引来找这个桥梁找敌方被吃掉棋子的次数
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] > 17 &&
													Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] < 200 && 
													Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] != 999))
											{
												Index_N++;//如果只有一个则可以吃了，如果>1 则违反了规则
											}
											if (Index_N == 1 && n == Move_Y - Index_I_J - 1)//保证只有一个棋并且是你点击的地方
											{
												Index = 2;
												Index_Frequency = 1;//保证一次索引到位
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//炮找到了攻击的对象
							{
								Piece_Logic::mMouseDownRange[i - Move_Y][Index_J] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_Y -= (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================普通移动
							if (Piece_Logic::mMouseDownRange[i - (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 999)
							{
								if (k == Move_Y - 1)//证明这条路可以走得通
								{
									IfOkMove = true;
								}
							}
							else//不是吃棋或者移动，那还执行个鸡巴
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_Y - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - Move_Y][j];
								Piece_Logic::mMouseDownRange[i - Move_Y][j] = Temp;
								mWE_Left_Cannon_Y -= (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
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
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//索引到棋子左边的炮
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标
						int Move_Y = (Temp_Y- mWE_Left_Cannon_Y) / 60;//得到要移动的次数，同时也是目标的Y坐标
						int Index = 0;//通过这个索引来执行吃棋
						int Index_I = 0;//记录索引到的第一个棋
						int Index_J = 0;//记录索引到的第一个棋
						int Index_I_J = 0;//记录索引到的第一个棋的次数
						int Index_N = 0;//记录从索引到第一个棋的又开始索引的棋子个数是否违反规则
						int Index_N_I = 0;//记录索引了几次才索引到被攻击的棋子
						int Index_Frequency = 0;//保证只执行一次
						for (int k = 0; k < Move_Y; k++)//进行巡路是否可以行走，可以走多少
						{
							Index_I_J++;//记录索引到的第一个棋的次数
							if ((Piece_Logic::mMouseDownRange[i + (k + 1)][j] == 10) || //这里是車的原因，保证索引到的是敌方的并且只隔开一个棋子
								(Piece_Logic::mMouseDownRange[i + (k + 1)][j] < 200 &&
									Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 999))
							{
								if (Index_Frequency == 0)//保证只执行一次
								{
									Index++;//只要是棋子,不管敌方还是我方，都能作为桥梁
									Index_I = (i + (k + 1));//记录索引到的第一个桥梁
									Index_J = j;//记录索引到的第一个桥梁
									if (Index == 1)//通过这个桥梁找敌方棋子
									{
										for (int n = 0; n <= Move_Y - Index_I_J - 1; n++)//通过剩下的所有的索引来找这个桥梁找敌方被吃掉棋子的次数
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] > 17 
													&& Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] < 200 
													&& Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] != 999))
											{
												Index_N++;//如果只有一个则可以吃了，如果>1 则违反了规则
											}
											if (Index_N == 1 && n == Move_Y - Index_I_J - 1)//保证只有一个棋并且是你点击的地方
											{
												Index = 2;
												Index_Frequency = 1;//保证一次索引到位
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//炮找到了攻击的对象
							{
								Piece_Logic::mMouseDownRange[i + Move_Y][Index_J] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_Y += (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================普通移动
							if (Piece_Logic::mMouseDownRange[i + (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 999)
							{
								if (k == Move_Y - 1)//证明这条路可以走得通
								{
									IfOkMove = true;
								}
							}
							else//不是吃棋或者移动，那还执行个鸡巴
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_Y - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + Move_Y][j];
								Piece_Logic::mMouseDownRange[i + Move_Y][j] = Temp;
								mWE_Left_Cannon_Y += (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
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
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//索引到棋子左边的炮
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标
						int Move_X = (mWE_Left_Cannon_X - Temp_X) / 60;//得到要移动的次数，同时也是目标的Y坐标
						int Index = 0;//通过这个索引来执行吃棋
						int Index_I = 0;//记录索引到的第一个棋
						int Index_J = 0;//记录索引到的第一个棋
						int Index_I_J = 0;//记录索引到的第一个棋的次数
						int Index_N = 0;//记录从索引到第一个棋的又开始索引的棋子个数是否违反规则
						int Index_N_I = 0;//记录索引了几次才索引到被攻击的棋子
						int Index_Frequency = 0;//保证只执行一次
						for (int k = 0; k < Move_X; k++)//进行巡路是否可以行走，可以走多少
						{
							Index_I_J++;//记录索引到的第一个棋的次数
							if ((Piece_Logic::mMouseDownRange[i][j - (k + 1)] == 10) || //这里是車的原因，保证索引到的是敌方的并且只隔开一个棋子
								(Piece_Logic::mMouseDownRange[i][j - (k + 1)] < 200 && 
									Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 999))
							{
								if (Index_Frequency == 0)//保证只执行一次
								{
									Index++;//只要是棋子,不管敌方还是我方，都能作为桥梁
									Index_I = i;//记录索引到的第一个桥梁
									Index_J = (j - (k + 1));//记录索引到的第一个桥梁
									if (Index == 1)//通过这个桥梁找敌方棋子
									{
										for (int n = 0; n <= Move_X - Index_I_J - 1; n++)//通过剩下的所有的索引来找这个桥梁找敌方被吃掉棋子的次数
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] > 17
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] < 200
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] != 999))
											{
												Index_N++;//如果只有一个则可以吃了，如果>1 则违反了规则
											}
											if (Index_N == 1 && n == Move_X - Index_I_J - 1)//保证只有一个棋并且是你点击的地方
											{
												Index = 2;
												Index_Frequency = 1;//保证一次索引到位
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//炮找到了攻击的对象
							{
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_X -= (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================普通移动
							if (Piece_Logic::mMouseDownRange[i][j - (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 999)
							{
								if (k == Move_X - 1)//证明这条路可以走得通
								{
									IfOkMove = true;
								}
							}
							else//不是吃棋或者移动，那还执行个鸡巴
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_X - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - Move_X];
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Temp;
								mWE_Left_Cannon_X -= (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
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
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//索引到棋子左边的炮
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//得到鼠标点击的标准坐标
						int Move_X = (Temp_X - mWE_Left_Cannon_X) / 60;//得到要移动的次数，同时也是目标的Y坐标
						int Index = 0;//通过这个索引来执行吃棋
						int Index_I = 0;//记录索引到的第一个棋
						int Index_J = 0;//记录索引到的第一个棋
						int Index_I_J = 0;//记录索引到的第一个棋的次数
						int Index_N = 0;//记录从索引到第一个棋的又开始索引的棋子个数是否违反规则
						int Index_N_I = 0;//记录索引了几次才索引到被攻击的棋子
						int Index_Frequency = 0;//保证只执行一次
						for (int k = 0; k < Move_X; k++)//进行巡路是否可以行走，可以走多少
						{
							Index_I_J++;//记录索引到的第一个棋的次数
							if ((Piece_Logic::mMouseDownRange[i][j + (k + 1)] == 10) || //这里是車的原因，保证索引到的是敌方的并且只隔开一个棋子
								(Piece_Logic::mMouseDownRange[i][j + (k + 1)] < 200 && 
									Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 999))
							{
								if (Index_Frequency == 0)//保证只执行一次
								{
									Index++;//只要是棋子,不管敌方还是我方，都能作为桥梁
									Index_I = i;//记录索引到的第一个桥梁
									Index_J = (j + (k + 1));//记录索引到的第一个桥梁
									if (Index == 1)//通过这个桥梁找敌方棋子
									{
										for (int n = 0; n <= Move_X - Index_I_J - 1; n++)//通过剩下的所有的索引来找这个桥梁找敌方被吃掉棋子的次数
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] > 17
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] < 200
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] != 999))
											{
												Index_N++;//如果只有一个则可以吃了，如果>1 则违反了规则
											}
											if (Index_N == 1 && n == Move_X - Index_I_J - 1)//保证只有一个棋并且是你点击的地方
											{
												Index = 2;
												Index_Frequency = 1;//保证一次索引到位
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//炮找到了攻击的对象
							{
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_X += (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================普通移动
							if (Piece_Logic::mMouseDownRange[i][j + (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 999)
							{
								if (k == Move_X - 1)//证明这条路可以走得通
								{
									IfOkMove = true;
								}
							}
							else//不是吃棋或者移动，那还执行个鸡巴
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_X - 1)//证明这条路可以走得通
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + Move_X];
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Temp;
								mWE_Left_Cannon_X += (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//这里重要
								Piece::Change_mWe(1);
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