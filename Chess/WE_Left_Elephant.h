#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

//�����
class WE_Left_Elephant:public Piece,public Piece_Logic,public _____Elephant__TO__Soldier__Logic__
{
	int mElephant_Bmpid = 0;
	int mWE_Left_Elephant_X = 0;
	int mWE_Left_Elephant_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Elephant()
	{
		mWE_Left_Elephant_X = 170;
		mWE_Left_Elephant_Y = 590;
	}
	~WE_Left_Elephant()
	{
		GoBitmap->ReleaseBmp(mElephant_Bmpid);
	}
	void InitPiece()                    //��������
	{
		mElephant_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Elephant.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mWE_Left_Elephant_X, mWE_Left_Elephant_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mElephant_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //�����߼�����
	{
		if (Piece::Reutrn_mWe() == 0)//0��ʾ�ҿ���������
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mWE_Left_Elephant_X - 30 && Mouse_X <= mWE_Left_Elephant_X + 30
					&& Mouse_Y >= mWE_Left_Elephant_Y - 30 && Mouse_Y <= mWE_Left_Elephant_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 7;//���������
					}
				}
				if (Piece_Logic::mWE_CommandState == 7)
				{
					BOOL BoolLeftForward = FALSE;
					BOOL BoolRightForward = FALSE;
					BOOL BoolLeftBack = FALSE;
					BOOL BoolRightBack = FALSE;
					BoolLeftForward = _____Elephant__TO__Soldier__Logic__::Elephant_MoveForwardTarget(mWE_Left_Elephant_X, mWE_Left_Elephant_Y,Mouse_X,Mouse_Y);
					BoolRightForward = _____Elephant__TO__Soldier__Logic__::Elephant_MoveBackTarget(mWE_Left_Elephant_X, mWE_Left_Elephant_Y, Mouse_X, Mouse_Y);
					BoolLeftBack = _____Elephant__TO__Soldier__Logic__::Elephant_MoveLeftTarget(mWE_Left_Elephant_X, mWE_Left_Elephant_Y, Mouse_X, Mouse_Y);
					BoolRightBack = _____Elephant__TO__Soldier__Logic__::Elephant_MoveRightTarget(mWE_Left_Elephant_X, mWE_Left_Elephant_Y, Mouse_X, Mouse_Y);
					__WE_Left_Elephant_Logic___(BoolLeftForward, BoolRightForward, BoolLeftBack, BoolRightBack);
				}
			}
		}
	}
	int __WE_Left_Elephant_Logic___(BOOL BoolLeftForward, BOOL BoolRightForward, BOOL BoolLeftBack, BOOL BoolRightBack)
	{
		__BoolLeftForward(BoolLeftForward, mWE_Left_Elephant_X, mWE_Left_Elephant_Y,7);
		__BoolRightForward(BoolRightForward, mWE_Left_Elephant_X, mWE_Left_Elephant_Y, 7);
		__BoolLeftBack(BoolLeftBack, mWE_Left_Elephant_X, mWE_Left_Elephant_Y, 7);
		__BoolRightBack(BoolRightBack, mWE_Left_Elephant_X, mWE_Left_Elephant_Y, 7);
		return 0;
	}
	int __BoolLeftForward(BOOL BoolLeftForward,int &mWE_Right_Elephant_X,int &mWE_Left_Elephant_Y,int Piece_Code)
	{
		if (BoolLeftForward)//��ǰ
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ���
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j - 1] >= 200 
							&& ((Piece_Logic::mMouseDownRange[i - 2][j - 2] == 10) || Piece_Logic::mMouseDownRange[i - 2][j - 2] > 17
								&& Piece_Logic::mMouseDownRange[i - 2][j - 2] < 200 && Piece_Logic::mMouseDownRange[i - 2][j - 2] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 2][j - 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Elephant_X -= 120;
							mWE_Left_Elephant_Y -= 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j - 2] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j - 2] != 999)//����ǰ���ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 2][j - 2];
							Piece_Logic::mMouseDownRange[i - 2][j - 2] = Temp;

							mWE_Right_Elephant_X -= 120;
							mWE_Left_Elephant_Y -= 120;
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
		return 0;
	}
	int __BoolRightForward(BOOL BoolRightForward, int &mWE_Right_Elephant_X, int &mWE_Left_Elephant_Y, int Piece_Code)
	{
		if (BoolRightForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ���
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j + 1] >= 200
							&& ((Piece_Logic::mMouseDownRange[i - 2][j + 2] == 10) || Piece_Logic::mMouseDownRange[i - 2][j + 2] > 17
								&& Piece_Logic::mMouseDownRange[i - 2][j + 2] < 200 && Piece_Logic::mMouseDownRange[i - 2][j + 2] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 2][j + 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Elephant_X += 120;
							mWE_Left_Elephant_Y -= 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i - 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j + 2] >= 200 && Piece_Logic::mMouseDownRange[i - 2][j + 2] != 999)//���������ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 2][j + 2];
							Piece_Logic::mMouseDownRange[i - 2][j + 2] = Temp;

							mWE_Right_Elephant_X += 120;
							mWE_Left_Elephant_Y -= 120;
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
		return 0;
	}
	int __BoolLeftBack(BOOL BoolLeftBack, int &mWE_Right_Elephant_X, int &mWE_Left_Elephant_Y, int Piece_Code)
	{
		if (BoolLeftBack)//���
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ���
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j - 1] >= 200
							&& ((Piece_Logic::mMouseDownRange[i + 2][j - 2] == 10) || Piece_Logic::mMouseDownRange[i + 2][j - 2] > 17
								&& Piece_Logic::mMouseDownRange[i + 2][j - 2] < 200 && Piece_Logic::mMouseDownRange[i + 2][j - 2] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 2][j - 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Elephant_X -= 120;
							mWE_Left_Elephant_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j - 2] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j - 2] != 999)//��������ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 2][j - 2];
							Piece_Logic::mMouseDownRange[i + 2][j - 2] = Temp;


							mWE_Right_Elephant_X -= 120;
							mWE_Left_Elephant_Y += 120;
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
		return 0;
	}
	int __BoolRightBack(BOOL BoolRightBack, int &mWE_Right_Elephant_X, int &mWE_Left_Elephant_Y, int Piece_Code)
	{
		if (BoolRightBack)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ���
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j + 1] >= 200
							&& ((Piece_Logic::mMouseDownRange[i + 2][j + 2] == 10) || Piece_Logic::mMouseDownRange[i + 2][j + 2] > 17
								&& Piece_Logic::mMouseDownRange[i + 2][j + 2] < 200 && Piece_Logic::mMouseDownRange[i + 2][j + 2] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 2][j + 2] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Elephant_X += 120;
							mWE_Left_Elephant_Y += 120;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
							ifok = true;
							break;
						}
						else if (Piece_Logic::mMouseDownRange[i + 1][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j + 2] >= 200 && Piece_Logic::mMouseDownRange[i + 2][j + 2] != 999)//�����ұ��ǿյ�
						{
							//���ƶ�����֮���������ý���������
							int Temp = mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 2][j + 2];
							Piece_Logic::mMouseDownRange[i + 2][j + 2] = Temp;

							mWE_Right_Elephant_X += 120;
							mWE_Left_Elephant_Y += 120;
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
		return 0;
	}
};