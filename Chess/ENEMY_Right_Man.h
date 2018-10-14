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
	void InitPiece()                    //��������
	{
		mENEMY_Right_Man_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Man.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mENEMY_Right_Man_X, mENEMY_Right_Man_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mENEMY_Right_Man_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //�����߼�����
	{
		if (Piece::Reutrn_mWe() == 1)//1�õз�������
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mENEMY_Right_Man_X - 30 && Mouse_X <= mENEMY_Right_Man_X + 30
					&& Mouse_Y >= mENEMY_Right_Man_Y - 30 && Mouse_Y <= mENEMY_Right_Man_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 40;//��ߵ�ʿ������
					}
				}
				if (Piece_Logic::mWE_CommandState == 40)//��ߵ�ʿ������
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
		__BoolLeftForward(BoolLeftForward, mENEMY_Right_Man_X, mENEMY_Right_Man_Y, 40, 0);
		__BoolRightForward(BoolRightForward, mENEMY_Right_Man_X, mENEMY_Right_Man_Y, 40, 0);
		__BoolLeftBack(BoolLeftBack, mENEMY_Right_Man_X, mENEMY_Right_Man_Y, 40, 0);
		__BoolRightBack(BoolRightBack, mENEMY_Right_Man_X, mENEMY_Right_Man_Y, 40, 0);
		return 0;
	}
	int __BoolLeftForward(BOOL BoolLeftForward, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code, int Piece_Change_mWe)
	{
		if (BoolLeftForward)//��ǰ
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�ʿ
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j - 1] != 10 &&
							(Piece_Logic::mMouseDownRange[i - 1][j - 1] <= 17 && Piece_Logic::mMouseDownRange[i - 1][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j - 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 1][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j - 1] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j - 1];
							Piece_Logic::mMouseDownRange[i - 1][j - 1] = Temp;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
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
	int __BoolRightForward(BOOL BoolRightForward, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code, int Piece_Change_mWe)
	{
		if (BoolRightForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�ʿ
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j + 1] != 10 &&
							(Piece_Logic::mMouseDownRange[i - 1][j + 1] <= 17 && Piece_Logic::mMouseDownRange[i - 1][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j + 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 1][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j + 1] != 999)//���������ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j + 1];
							Piece_Logic::mMouseDownRange[i - 1][j + 1] = Temp;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
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
	int __BoolLeftBack(BOOL BoolLeftBack, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code, int Piece_Change_mWe)
	{
		if (BoolLeftBack)//���
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�ʿ
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j - 1] != 10 &&
							(Piece_Logic::mMouseDownRange[i + 1][j - 1] <= 17 && Piece_Logic::mMouseDownRange[i + 1][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j - 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 1][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j - 1] != 999)//��������ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j - 1];
							Piece_Logic::mMouseDownRange[i + 1][j - 1] = Temp;


							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
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
	int __BoolRightBack(BOOL BoolRightBack, int &mWE_Right_Man_X, int &mWE_Right_Man_Y, int Piece_Code, int Piece_Change_mWe)
	{
		if (BoolRightBack)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�ʿ
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j + 1] != 10 &&
							(Piece_Logic::mMouseDownRange[i + 1][j + 1] <= 17 && Piece_Logic::mMouseDownRange[i + 1][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j + 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 1][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j + 1] != 999)//�����ұ��ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j + 1];
							Piece_Logic::mMouseDownRange[i + 1][j + 1] = Temp;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(Piece_Change_mWe);
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