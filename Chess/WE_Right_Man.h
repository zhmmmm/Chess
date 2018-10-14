#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "WE_Right_Man_Logic.h"

//�ұߵ�ʿ
class WE_Right_Man :public Piece, public Piece_Logic,public WE_Right_Man_Logic
{
	int mWE_Right_Man_Bmpid = 0;

	int mWE_Right_Man_X = 0;
	int mWE_Right_Man_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Right_Man()
	{
		mWE_Right_Man_X = 350;
		mWE_Right_Man_Y = 590;
	}
	~WE_Right_Man()
	{
		GoBitmap->ReleaseBmp(mWE_Right_Man_Bmpid);
	}
	void InitPiece()                    //��������
	{
		mWE_Right_Man_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Man.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mWE_Right_Man_X, mWE_Right_Man_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mWE_Right_Man_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //�����߼�����
	{
		if (Piece::Reutrn_mWe() == 0)//0��ʾ�ҿ���������
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mWE_Right_Man_X - 30 && Mouse_X <= mWE_Right_Man_X + 30
					&& Mouse_Y >= mWE_Right_Man_Y - 30 && Mouse_Y <= mWE_Right_Man_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 4;//�ұߵ�ʿ������
					}
				}
				if (Piece_Logic::mWE_CommandState == 4)//�ұߵ�ʿ������
				{
					BOOL BoolLeftForward = FALSE;
					BoolLeftForward = WE_Right_Man_Logic::Man_MoveForwardTarget(mWE_Right_Man_X, mWE_Right_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolRightForward = FALSE;
					BoolRightForward = WE_Right_Man_Logic::Man_MoveBackTarget(mWE_Right_Man_X, mWE_Right_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeftBack = FALSE;
					BoolLeftBack = WE_Right_Man_Logic::Man_MoveLeftTarget(mWE_Right_Man_X, mWE_Right_Man_Y, Mouse_X, Mouse_Y);
					BOOL BoolRightBack = FALSE;
					BoolRightBack = WE_Right_Man_Logic::Man_MoveRightTarget(mWE_Right_Man_X, mWE_Right_Man_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_Right_Man___(BoolLeftForward, BoolRightForward, BoolLeftBack, BoolRightBack);
				}
			}
		}
	}
	int __WE_Right_Man___(BOOL BoolLeftForward, BOOL BoolRightForward, BOOL BoolLeftBack, BOOL BoolRightBack)
	{
		__BoolLeftForward(BoolLeftForward, mWE_Right_Man_X, mWE_Right_Man_Y, 4);
		__BoolRightForward(BoolRightForward, mWE_Right_Man_X, mWE_Right_Man_Y, 4);
		__BoolLeftBack(BoolLeftBack, mWE_Right_Man_X, mWE_Right_Man_Y, 4);
		__BoolRightBack(BoolRightBack, mWE_Right_Man_X, mWE_Right_Man_Y, 4);
		return 0;
	}
	int __BoolLeftForward(BOOL BoolLeftForward, int &mWE_Right_Man_X,int &mWE_Right_Man_Y,int Piece_Code)
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
						if (Piece_Logic::mMouseDownRange[i - 1][j - 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i - 1][j - 1] > 17 && Piece_Logic::mMouseDownRange[i - 1][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j - 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 1][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
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
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�ʿ
					{
						if (Piece_Logic::mMouseDownRange[i - 1][j + 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i - 1][j + 1] > 17 && Piece_Logic::mMouseDownRange[i - 1][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i - 1][j + 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i - 1][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y -= 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
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
		if (BoolLeftBack)//���
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�ʿ
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j - 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i + 1][j - 1] > 17 && Piece_Logic::mMouseDownRange[i + 1][j - 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j - 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 1][j - 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X -= 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
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
					if (Piece_Logic::mMouseDownRange[i][j] == Piece_Code)//������������ߵ�ʿ
					{
						if (Piece_Logic::mMouseDownRange[i + 1][j + 1] == 10 ||
							(Piece_Logic::mMouseDownRange[i + 1][j + 1] > 17 && Piece_Logic::mMouseDownRange[i + 1][j + 1] < 200
								&& Piece_Logic::mMouseDownRange[i + 1][j + 1] != 999))
						{
							Piece_Logic::mMouseDownRange[i + 1][j + 1] = Piece_Logic::mMouseDownRange[i][j];
							Piece_Logic::mMouseDownRange[i][j] = 258;

							mWE_Right_Man_X += 60;
							mWE_Right_Man_Y += 60;
							Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
							Piece::Change_mWe(1);
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