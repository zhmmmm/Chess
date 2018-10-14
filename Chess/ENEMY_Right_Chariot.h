#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"
#include "ENEMY_Command.h"

class ENEMY_Right_Chariot :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__, public ENEMY_Command
{
	int mENEMY_Right_Chariot_Bmpid = 0;
	int mENEMY_Right_Chariot_X;
	int mENEMY_Right_Chariot_Y;



	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Right_Chariot()
	{
		mENEMY_Right_Chariot_X = 530;
		mENEMY_Right_Chariot_Y = 50;
	}
	~ENEMY_Right_Chariot()
	{
		GoBitmap->ReleaseBmp(mENEMY_Right_Chariot_Bmpid);
	}
	void InitPiece()                    //��������
	{
		mENEMY_Right_Chariot_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Chariot.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mENEMY_Right_Chariot_X, mENEMY_Right_Chariot_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_Right_Chariot_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //�����߼�����
	{
		if (Piece::Reutrn_mWe() == 1)//1��ʾ�ҿ���������
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mENEMY_Right_Chariot_X - 30 && Mouse_X <= mENEMY_Right_Chariot_X + 30
					&& Mouse_Y >= mENEMY_Right_Chariot_Y - 30 && Mouse_Y <= mENEMY_Right_Chariot_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 10;//�ұߵ�܇������
					}
				}
				if (Piece_Logic::mWE_CommandState == 10)//�ұߵ�܇������
				{
					BOOL BoolForward = FALSE;
					BoolForward = _____Elephant__TO__Soldier__Logic__::Chariot_MoveForwardTarget(mENEMY_Right_Chariot_X, mENEMY_Right_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolBack = FALSE;
					BoolBack = _____Elephant__TO__Soldier__Logic__::Chariot_MoveBackTarget(mENEMY_Right_Chariot_X, mENEMY_Right_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeft = FALSE;
					BoolLeft = _____Elephant__TO__Soldier__Logic__::Chariot_MoveLeftTarget(mENEMY_Right_Chariot_X, mENEMY_Right_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolRight = FALSE;
					BoolRight = _____Elephant__TO__Soldier__Logic__::Chariot_MoveRightTarget(mENEMY_Right_Chariot_X, mENEMY_Right_Chariot_Y, Mouse_X, Mouse_Y);
					int TempVar = __ENEMY_Right_Chariot___(BoolForward, BoolBack, BoolLeft, BoolRight);
				}
			}
		}
	}
	int __ENEMY_Right_Chariot___(BOOL BoolForward, BOOL BoolBack, BOOL BoolLeft, BOOL BoolRight)
	{
		__BoolForward(BoolForward, mENEMY_Right_Chariot_Y, 10);
		__BoolBack(BoolBack, mENEMY_Right_Chariot_Y, 10);
		__BoolLeft(BoolLeft, mENEMY_Right_Chariot_X, 10);
		__BoolRight(BoolRight, mENEMY_Right_Chariot_X, 10);
		return 0;
	}
	int __BoolForward(BOOL BoolForward, int &mWE_Left_Chariot_Y, int Piece_Code)
	{
		if (BoolForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�܇
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//�õ�������ı�׼����

						int Move_Y = (mWE_Left_Chariot_Y - Temp_Y) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						int Index = 0;
						int Index_I = 0;//��֤�Ե������м�û���κ�����
						for (int k = 0; k < Move_Y; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							if (Piece_Logic::mMouseDownRange[i - (k + 1)][j] == 10 || Piece_Logic::mMouseDownRange[i - (k + 1)][j] < 200)//��֤�Ե������м�û���κ�����
							{
								Index_I++;
							}
							if (Piece_Logic::mMouseDownRange[i - (k + 1)][j] <= 17 &&
								Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 10 &&
								Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 999)//�ų��ҷ�����
							{
								if (k == Move_Y - 1 && Index_I == 1)//��֤�������ǵ���ĵط�,���ұ�֤�Ե������м�û���κ�����,����Ҫ���Ե��Ķ���
								{
									Index = 1;
								}
							}
							if (Index == 1)
							{
								Piece_Logic::mMouseDownRange[i - Move_Y][j] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Chariot_Y -= (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
							//=========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i - (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i - (k + 1)][j] != 999)
							{
								if (k == Move_Y - 1)
								{
									IfOkMove = true;
								}
							}
							if (IfOkMove && k == Move_Y - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - Move_Y][j];
								Piece_Logic::mMouseDownRange[i - Move_Y][j] = Temp;
								mWE_Left_Chariot_Y -= (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
		return 0;
	}
	int __BoolBack(BOOL BoolBack, int &mWE_Left_Chariot_Y, int Piece_Code)
	{
		if (BoolBack)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�܇
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//�õ�������ı�׼����

						int Move_Y = (Temp_Y - mWE_Left_Chariot_Y) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						int Index = 0;
						int Index_I = 0;//��֤�Ե������м�û���κ�����
						for (int k = 0; k < Move_Y; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							if (Piece_Logic::mMouseDownRange[i + (k + 1)][j] == 10 || Piece_Logic::mMouseDownRange[i + (k + 1)][j] < 200)//��֤�Ե������м�û���κ�����
							{
								Index_I++;
							}
							if (Piece_Logic::mMouseDownRange[i + (k + 1)][j] <= 17 &&
								Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 10 &&
								Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 999)//�ų��ҷ�����
							{
								if (k == Move_Y - 1 && Index_I == 1)//��֤�������ǵ���ĵط�,���ұ�֤�Ե������м�û���κ�����,����Ҫ���Ե��Ķ���
								{
									Index = 1;
								}
							}
							if (Index == 1)
							{
								Piece_Logic::mMouseDownRange[i + Move_Y][j] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Chariot_Y += (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
							//=========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i + (k + 1)][j] >= 200 && Piece_Logic::mMouseDownRange[i + (k + 1)][j] != 999)
							{
								if (k == Move_Y - 1)
								{
									IfOkMove = true;
								}
							}
							if (IfOkMove && k == Move_Y - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + Move_Y][j];
								Piece_Logic::mMouseDownRange[i + Move_Y][j] = Temp;
								mWE_Left_Chariot_Y += (Move_Y * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
		return 0;
	}
	int __BoolLeft(BOOL BoolLeft, int &mWE_Left_Chariot_X, int Piece_Code)
	{
		if (BoolLeft)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�܇
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//�õ�������ı�׼����

						int Move_X = (mWE_Left_Chariot_X - Temp_X) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						int Index = 0;
						int Index_I = 0;//��֤�Ե������м�û���κ�����
						for (int k = 0; k < Move_X; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							if (Piece_Logic::mMouseDownRange[i][j - (k + 1)] == 10 || Piece_Logic::mMouseDownRange[i][j - (k + 1)] < 200)//��֤�Ե������м�û���κ�����
							{
								Index_I++;
							}
							if (Piece_Logic::mMouseDownRange[i][j - (k + 1)] <= 17 &&
								Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 10 &&
								Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 999)//�ų��ҷ�����
							{
								if (k == Move_X - 1 && Index_I == 1)//��֤�������ǵ���ĵط�,���ұ�֤�Ե������м�û���κ�����,����Ҫ���Ե��Ķ���
								{
									Index = 1;
								}
							}
							if (Index == 1)
							{
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Chariot_X -= (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
							//=========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i][j - (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j - (k + 1)] != 999)
							{
								if (k == Move_X - 1)
								{
									IfOkMove = true;
								}
							}
							if (IfOkMove && k == Move_X - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - Move_X];
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Temp;
								mWE_Left_Chariot_X -= (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
		return 0;
	}
	int __BoolRight(BOOL BoolRight, int &mWE_Left_Chariot_X, int Piece_Code)
	{
		if (BoolRight)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�܇
					{
						int Temp_X = ENEMY_Command::__mReturnRedCurStandardCoor__().x;
						int Temp_Y = ENEMY_Command::__mReturnRedCurStandardCoor__().y;//�õ�������ı�׼����

						int Move_X = (Temp_X - mWE_Left_Chariot_X) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						int Index = 0;
						int Index_I = 0;//��֤�Ե������м�û���κ�����
						for (int k = 0; k < Move_X; k++)//����Ѳ·�Ƿ�������ߣ������߶���
						{
							if (Piece_Logic::mMouseDownRange[i][j + (k + 1)] == 10 || Piece_Logic::mMouseDownRange[i][j + (k + 1)] < 200)//��֤�Ե������м�û���κ�����
							{
								Index_I++;
							}
							if (Piece_Logic::mMouseDownRange[i][j + (k + 1)] <= 17 &&
								Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 10 &&
								Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 999)//�ų��ҷ�����
							{
								if (k == Move_X - 1 && Index_I == 1)//��֤�������ǵ���ĵط�,���ұ�֤�Ե������м�û���κ�����,����Ҫ���Ե��Ķ���
								{
									Index = 1;
								}
							}
							if (Index == 1)
							{
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = 258;
								mWE_Left_Chariot_X += (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
								Piece::Change_mWe(0);
								ifok = true;
								break;
							}
							//=========================��ͨ�ƶ�
							if (Piece_Logic::mMouseDownRange[i][j + (k + 1)] >= 200 && Piece_Logic::mMouseDownRange[i][j + (k + 1)] != 999)
							{
								if (k == Move_X - 1)
								{
									IfOkMove = true;
								}
							}
							if (IfOkMove && k == Move_X - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + Move_X];
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Temp;
								mWE_Left_Chariot_X += (Move_X * 60);

								Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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