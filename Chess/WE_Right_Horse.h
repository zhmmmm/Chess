#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

//�ұߵ���
class WE_Right_Horse :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__
{
	int mHorse_Bmpid = 0;
	int mWE_Right_Horse_X = 0;
	int mWE_Right_Horse_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Right_Horse()
	{
		mWE_Right_Horse_X = 470;
		mWE_Right_Horse_Y = 590;
	}
	~WE_Right_Horse()
	{
		GoBitmap->ReleaseBmp(mHorse_Bmpid);
	}
	void InitPiece()                    //��������
	{
		mHorse_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Horse.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mWE_Right_Horse_X, mWE_Right_Horse_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mHorse_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //�����߼�����
	{
		if (Piece::Reutrn_mWe() == 0)//0��ʾ�ҿ���������
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mWE_Right_Horse_X - 30 && Mouse_X <= mWE_Right_Horse_X + 30
					&& Mouse_Y >= mWE_Right_Horse_Y - 30 && Mouse_Y <= mWE_Right_Horse_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 2;//�ұߵ�������
					}
				}
				if (Piece_Logic::mWE_CommandState == 2)//�ұߵ�������
				{
					BOOL Bool_0_LeftForward = FALSE;
					BOOL Bool_1_RightForward = FALSE;
					BOOL Bool_2_LeftBack = FALSE;
					BOOL Bool_3_RightBack = FALSE;
					BOOL Bool_4_LeftForward = FALSE;
					BOOL Bool_5_RightForward = FALSE;
					BOOL Bool_6_LeftBack = FALSE;
					BOOL Bool_7_RightBack = FALSE;
					Bool_0_LeftForward = _____Elephant__TO__Soldier__Logic__::_0__Horse_MoveForwardTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_1_RightForward = _____Elephant__TO__Soldier__Logic__::_1__Horse_MoveBackTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_2_LeftBack = _____Elephant__TO__Soldier__Logic__::_2__Horse_MoveLeftTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_3_RightBack = _____Elephant__TO__Soldier__Logic__::_3__Horse_MoveRightTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_4_LeftForward = _____Elephant__TO__Soldier__Logic__::_4__Horse_MoveForwardTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_5_RightForward = _____Elephant__TO__Soldier__Logic__::_5__Horse_MoveBackTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_6_LeftBack = _____Elephant__TO__Soldier__Logic__::_6__Horse_MoveLeftTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					Bool_7_RightBack = _____Elephant__TO__Soldier__Logic__::_7__Horse_MoveRightTarget(mWE_Right_Horse_X, mWE_Right_Horse_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_Right_Horse_Logic___(Bool_0_LeftForward, Bool_1_RightForward, Bool_2_LeftBack, Bool_3_RightBack, Bool_4_LeftForward, Bool_5_RightForward, Bool_6_LeftBack, Bool_7_RightBack);
				}
			}
		}
	}
	int __WE_Right_Horse_Logic___(BOOL Bool_0_LeftForward, BOOL Bool_1_RightForward, BOOL Bool_2_LeftBack, BOOL Bool_3_RightBack,
		BOOL Bool_4_LeftForward, BOOL Bool_5_RightForward, BOOL Bool_6_LeftBack, BOOL Bool_7_RightBack)
	{
		if (Bool_0_LeftForward)//��ǰ
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j - 1] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 2][j - 1];
							Piece_Logic::mMouseDownRange[i - 2][j - 1] = Temp;

							mWE_Right_Horse_X -= 60;
							mWE_Right_Horse_Y -= 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
		if (Bool_1_RightForward)//��ǰ
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j + 1] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 2][j + 1];
							Piece_Logic::mMouseDownRange[i - 2][j + 1] = Temp;

							mWE_Right_Horse_X += 60;
							mWE_Right_Horse_Y -= 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
		if (Bool_2_LeftBack)//��ǰ2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j - 2] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j - 2] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j - 2];
							Piece_Logic::mMouseDownRange[i - 1][j - 2] = Temp;

							mWE_Right_Horse_X -= 120;
							mWE_Right_Horse_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
		if (Bool_3_RightBack)//��ǰ2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j + 2] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j + 2] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j + 2];
							Piece_Logic::mMouseDownRange[i - 1][j + 2] = Temp;

							mWE_Right_Horse_X += 120;
							mWE_Right_Horse_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
		//����
		if (Bool_4_LeftForward)//���
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j - 2] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j - 1] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j - 2];
							Piece_Logic::mMouseDownRange[i + 1][j - 2] = Temp;

							mWE_Right_Horse_X -= 120;
							mWE_Right_Horse_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 5;
		}
		if (Bool_5_RightForward)//�Һ�
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j + 2] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j + 1] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j + 2];
							Piece_Logic::mMouseDownRange[i + 1][j + 2] = Temp;

							mWE_Right_Horse_X += 120;
							mWE_Right_Horse_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 6;
		}
		if (Bool_6_LeftBack)//���2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j - 2] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 2][j - 1];
							Piece_Logic::mMouseDownRange[i + 2][j - 1] = Temp;

							mWE_Right_Horse_X -= 60;
							mWE_Right_Horse_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
					}
				}
				if (ifok) { break; }
			}
			return 7;
		}
		if (Bool_7_RightBack)//�Һ�2
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == 2)//�����������ұߵ���
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j + 2] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮�����������������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 2][j + 1];
							Piece_Logic::mMouseDownRange[i + 2][j + 1] = Temp;

							mWE_Right_Horse_X += 60;
							mWE_Right_Horse_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
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