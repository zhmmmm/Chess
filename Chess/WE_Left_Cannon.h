#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

//��ߵ���
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
	void InitPiece()                    //��������
	{
		mCannon_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Cannon.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mWE_Left_Cannon_X, mWE_Left_Cannon_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mCannon_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //�����߼�����
	{
		if (Piece::Reutrn_mWe() == 0)//0��ʾ�ҿ���������
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mWE_Left_Cannon_X - 30 && Mouse_X <= mWE_Left_Cannon_X + 30
					&& Mouse_Y >= mWE_Left_Cannon_Y - 30 && Mouse_Y <= mWE_Left_Cannon_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 12;//��ߵ��ڱ�����
					}
				}
				if (Piece_Logic::mWE_CommandState == 12)//��ߵ��ڱ�����
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
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//������������ߵ���
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����
						int Move_Y = (mWE_Left_Cannon_Y - Temp_Y) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����
						int Index = 0;//ͨ�����������ִ�г���
						int Index_I = 0;//��¼�������ĵ�һ����
						int Index_J = 0;//��¼�������ĵ�һ����
						int Index_I_J = 0;//��¼�������ĵ�һ����Ĵ���
						int Index_N = 0;//��¼����������һ������ֿ�ʼ���������Ӹ����Ƿ�Υ������
						int Index_N_I = 0;//��¼�����˼��β�������������������
						int Index_Frequency = 0;//��ִֻ֤��һ��
						for (int k = 0; k < Move_Y; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							Index_I_J++;//��¼�������ĵ�һ����Ĵ���
							if ((Piece_Logic::mMouseDownRange[i - (k + 1)][j] == 10) || //������܇��ԭ�򣬱�֤���������ǵз��Ĳ���ֻ����һ������
								(Piece_Logic::mMouseDownRange[i - (k + 1)][j] < 200 &&
									Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 999))
							{
								if (Index_Frequency == 0)//��ִֻ֤��һ��
								{
									Index++;//ֻҪ������,���ܵз������ҷ���������Ϊ����
									Index_I = (i - (k + 1));//��¼�������ĵ�һ������
									Index_J = j;//��¼�������ĵ�һ������
									if (Index == 1)//ͨ����������ҵз�����
									{
										for (int n = 0; n <= Move_Y - Index_I_J - 1; n++)//ͨ��ʣ�µ����е�����������������ҵз����Ե����ӵĴ���
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] > 17 &&
													Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] < 200 && 
													Piece_Logic::mMouseDownRange[Index_I - (n + 1)][Index_J] != 999))
											{
												Index_N++;//���ֻ��һ������Գ��ˣ����>1 ��Υ���˹���
											}
											if (Index_N == 1 && n == Move_Y - Index_I_J - 1)//��ֻ֤��һ���岢���������ĵط�
											{
												Index = 2;
												Index_Frequency = 1;//��֤һ��������λ
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//���ҵ��˹����Ķ���
							{
								Piece_Logic::mMouseDownRange[i - Move_Y][Index_J] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_Y -= (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i - (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 999)
							{
								if (k == Move_Y - 1)//֤������·�����ߵ�ͨ
								{
									IfOkMove = true;
								}
							}
							else//���ǳ�������ƶ����ǻ�ִ�и�����
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_Y - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - Move_Y][j];
								Piece_Logic::mMouseDownRange[i - Move_Y][j] = Temp;
								mWE_Left_Cannon_Y -= (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//������������ߵ���
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����
						int Move_Y = (Temp_Y- mWE_Left_Cannon_Y) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����
						int Index = 0;//ͨ�����������ִ�г���
						int Index_I = 0;//��¼�������ĵ�һ����
						int Index_J = 0;//��¼�������ĵ�һ����
						int Index_I_J = 0;//��¼�������ĵ�һ����Ĵ���
						int Index_N = 0;//��¼����������һ������ֿ�ʼ���������Ӹ����Ƿ�Υ������
						int Index_N_I = 0;//��¼�����˼��β�������������������
						int Index_Frequency = 0;//��ִֻ֤��һ��
						for (int k = 0; k < Move_Y; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							Index_I_J++;//��¼�������ĵ�һ����Ĵ���
							if ((Piece_Logic::mMouseDownRange[i + (k + 1)][j] == 10) || //������܇��ԭ�򣬱�֤���������ǵз��Ĳ���ֻ����һ������
								(Piece_Logic::mMouseDownRange[i + (k + 1)][j] < 200 &&
									Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 999))
							{
								if (Index_Frequency == 0)//��ִֻ֤��һ��
								{
									Index++;//ֻҪ������,���ܵз������ҷ���������Ϊ����
									Index_I = (i + (k + 1));//��¼�������ĵ�һ������
									Index_J = j;//��¼�������ĵ�һ������
									if (Index == 1)//ͨ����������ҵз�����
									{
										for (int n = 0; n <= Move_Y - Index_I_J - 1; n++)//ͨ��ʣ�µ����е�����������������ҵз����Ե����ӵĴ���
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] > 17 
													&& Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] < 200 
													&& Piece_Logic::mMouseDownRange[Index_I + (n + 1)][Index_J] != 999))
											{
												Index_N++;//���ֻ��һ������Գ��ˣ����>1 ��Υ���˹���
											}
											if (Index_N == 1 && n == Move_Y - Index_I_J - 1)//��ֻ֤��һ���岢���������ĵط�
											{
												Index = 2;
												Index_Frequency = 1;//��֤һ��������λ
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//���ҵ��˹����Ķ���
							{
								Piece_Logic::mMouseDownRange[i + Move_Y][Index_J] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_Y += (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i + (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 999)
							{
								if (k == Move_Y - 1)//֤������·�����ߵ�ͨ
								{
									IfOkMove = true;
								}
							}
							else//���ǳ�������ƶ����ǻ�ִ�и�����
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_Y - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + Move_Y][j];
								Piece_Logic::mMouseDownRange[i + Move_Y][j] = Temp;
								mWE_Left_Cannon_Y += (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//������������ߵ���
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����
						int Move_X = (mWE_Left_Cannon_X - Temp_X) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����
						int Index = 0;//ͨ�����������ִ�г���
						int Index_I = 0;//��¼�������ĵ�һ����
						int Index_J = 0;//��¼�������ĵ�һ����
						int Index_I_J = 0;//��¼�������ĵ�һ����Ĵ���
						int Index_N = 0;//��¼����������һ������ֿ�ʼ���������Ӹ����Ƿ�Υ������
						int Index_N_I = 0;//��¼�����˼��β�������������������
						int Index_Frequency = 0;//��ִֻ֤��һ��
						for (int k = 0; k < Move_X; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							Index_I_J++;//��¼�������ĵ�һ����Ĵ���
							if ((Piece_Logic::mMouseDownRange[i][j - (k + 1)] == 10) || //������܇��ԭ�򣬱�֤���������ǵз��Ĳ���ֻ����һ������
								(Piece_Logic::mMouseDownRange[i][j - (k + 1)] < 200 && 
									Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 999))
							{
								if (Index_Frequency == 0)//��ִֻ֤��һ��
								{
									Index++;//ֻҪ������,���ܵз������ҷ���������Ϊ����
									Index_I = i;//��¼�������ĵ�һ������
									Index_J = (j - (k + 1));//��¼�������ĵ�һ������
									if (Index == 1)//ͨ����������ҵз�����
									{
										for (int n = 0; n <= Move_X - Index_I_J - 1; n++)//ͨ��ʣ�µ����е�����������������ҵз����Ե����ӵĴ���
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] > 17
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] < 200
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J - (n + 1)] != 999))
											{
												Index_N++;//���ֻ��һ������Գ��ˣ����>1 ��Υ���˹���
											}
											if (Index_N == 1 && n == Move_X - Index_I_J - 1)//��ֻ֤��һ���岢���������ĵط�
											{
												Index = 2;
												Index_Frequency = 1;//��֤һ��������λ
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//���ҵ��˹����Ķ���
							{
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_X -= (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i][j - (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 999)
							{
								if (k == Move_X - 1)//֤������·�����ߵ�ͨ
								{
									IfOkMove = true;
								}
							}
							else//���ǳ�������ƶ����ǻ�ִ�и�����
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_X - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - Move_X];
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Temp;
								mWE_Left_Cannon_X -= (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
					if (Piece_Logic::mMouseDownRange[i][j] == 12)//������������ߵ���
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����
						int Move_X = (Temp_X - mWE_Left_Cannon_X) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����
						int Index = 0;//ͨ�����������ִ�г���
						int Index_I = 0;//��¼�������ĵ�һ����
						int Index_J = 0;//��¼�������ĵ�һ����
						int Index_I_J = 0;//��¼�������ĵ�һ����Ĵ���
						int Index_N = 0;//��¼����������һ������ֿ�ʼ���������Ӹ����Ƿ�Υ������
						int Index_N_I = 0;//��¼�����˼��β�������������������
						int Index_Frequency = 0;//��ִֻ֤��һ��
						for (int k = 0; k < Move_X; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							Index_I_J++;//��¼�������ĵ�һ����Ĵ���
							if ((Piece_Logic::mMouseDownRange[i][j + (k + 1)] == 10) || //������܇��ԭ�򣬱�֤���������ǵз��Ĳ���ֻ����һ������
								(Piece_Logic::mMouseDownRange[i][j + (k + 1)] < 200 && 
									Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 999))
							{
								if (Index_Frequency == 0)//��ִֻ֤��һ��
								{
									Index++;//ֻҪ������,���ܵз������ҷ���������Ϊ����
									Index_I = i;//��¼�������ĵ�һ������
									Index_J = (j + (k + 1));//��¼�������ĵ�һ������
									if (Index == 1)//ͨ����������ҵз�����
									{
										for (int n = 0; n <= Move_X - Index_I_J - 1; n++)//ͨ��ʣ�µ����е�����������������ҵз����Ե����ӵĴ���
										{
											Index_N_I++;
											if ((Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] == 10) ||
												(Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] > 17
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] < 200
													&& Piece_Logic::mMouseDownRange[Index_I][Index_J + (n + 1)] != 999))
											{
												Index_N++;//���ֻ��һ������Գ��ˣ����>1 ��Υ���˹���
											}
											if (Index_N == 1 && n == Move_X - Index_I_J - 1)//��ֻ֤��һ���岢���������ĵط�
											{
												Index = 2;
												Index_Frequency = 1;//��֤һ��������λ
												break;
											}
										}
									}
								}
							}
							if (Index == 2)//���ҵ��˹����Ķ���
							{
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Cannon_X += (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(1);
								ifok = true;
								break;
							}
							else if (Index > 2)
							{
								break;
							}
							//==========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i][j + (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 999)
							{
								if (k == Move_X - 1)//֤������·�����ߵ�ͨ
								{
									IfOkMove = true;
								}
							}
							else//���ǳ�������ƶ����ǻ�ִ�и�����
							{
								IfOkMove = false;
								break;
							}
							if (IfOkMove && k == Move_X - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + Move_X];
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Temp;
								mWE_Left_Cannon_X += (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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