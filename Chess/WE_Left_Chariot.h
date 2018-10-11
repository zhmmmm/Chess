#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "_____Elephant__TO__Soldier__Logic__.h"

//��ߵ�܇
class WE_Left_Chariot :public Piece, public Piece_Logic, public _____Elephant__TO__Soldier__Logic__
{
	int mChariot_Bmpid = 0;
	int mWE_Left_Chariot_X = 0;
	int mWE_Left_Chariot_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_Left_Chariot()
	{
		mWE_Left_Chariot_X = 50;
		mWE_Left_Chariot_Y = 590;
	}
	~WE_Left_Chariot()
	{
		GoBitmap->ReleaseBmp(mChariot_Bmpid);
	}
	void InitPiece()                    //��������
	{
		mChariot_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Chariot.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mWE_Left_Chariot_X, mWE_Left_Chariot_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mChariot_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int Mouse_X, int Mouse_Y)  //�����߼�����
	{
		if (Piece::Reutrn_mWe() == 0)//0��ʾ�ҿ���������
		{
			if (Which == 1 && State == 1)
			{
				if (Mouse_X >= mWE_Left_Chariot_X - 30 && Mouse_X <= mWE_Left_Chariot_X + 30
					&& Mouse_Y >= mWE_Left_Chariot_Y - 30 && Mouse_Y <= mWE_Left_Chariot_Y + 30)
				{
					if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)
					{
						Piece_Logic::mWE_CommandState = 9;//��ߵ�܇������
					}
				}
				if (Piece_Logic::mWE_CommandState == 9)//��ߵ�܇������
				{
					BOOL BoolForward = FALSE;
					BoolForward = _____Elephant__TO__Soldier__Logic__::Chariot_MoveForwardTarget(mWE_Left_Chariot_X, mWE_Left_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolBack = FALSE;
					BoolBack = _____Elephant__TO__Soldier__Logic__::Chariot_MoveBackTarget(mWE_Left_Chariot_X, mWE_Left_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolLeft = FALSE;
					BoolLeft = _____Elephant__TO__Soldier__Logic__::Chariot_MoveLeftTarget(mWE_Left_Chariot_X, mWE_Left_Chariot_Y, Mouse_X, Mouse_Y);
					BOOL BoolRight = FALSE;
					BoolRight = _____Elephant__TO__Soldier__Logic__::Chariot_MoveRightTarget(mWE_Left_Chariot_X, mWE_Left_Chariot_Y, Mouse_X, Mouse_Y);
					int TempVar = __WE_Left_Chariot___(BoolForward, BoolBack, BoolLeft, BoolRight);
				}
			}
		}
	}
	int __WE_Left_Chariot___(BOOL BoolForward, BOOL BoolBack, BOOL BoolLeft, BOOL BoolRight)
	{
		if (BoolForward)
		{
			for (int i = 0; i < 12; i++)
			{
				bool ifok = false;
				for (int j = 0; j < 11; j++)
				{
					bool IfOkMove = false;
					if (Piece_Logic::mMouseDownRange[i][j] == 9)//������������ߵ�܇
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����

						int Move_Y = (mWE_Left_Chariot_Y - Temp_Y) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						for (int k = 0; k < Move_Y; k++)//����Ѳ·�Ƿ�������ߣ������߶���
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
							if (IfOkMove == false) //ֻҪ��һ��false���ǲ��е�
							{
								break; 
							}
							if (IfOkMove && k == Move_Y - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - Move_Y][j];
								Piece_Logic::mMouseDownRange[i - Move_Y][j] = Temp;
								mWE_Left_Chariot_Y -= (Move_Y * 60);

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
					if (Piece_Logic::mMouseDownRange[i][j] == 9)//������������ߵ�܇
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����

						int Move_Y = (Temp_Y - mWE_Left_Chariot_Y) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						for (int k = 0; k < Move_Y; k++)//����Ѳ·�Ƿ�������ߣ������߶���
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
							if (IfOkMove == false) //ֻҪ��һ��false���ǲ��е�
							{
								break;
							}
							if (IfOkMove && k == Move_Y - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + Move_Y][j];
								Piece_Logic::mMouseDownRange[i + Move_Y][j] = Temp;
								mWE_Left_Chariot_Y += (Move_Y * 60);

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
					if (Piece_Logic::mMouseDownRange[i][j] == 9)//������������ߵ�܇
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����

						int Move_X = (mWE_Left_Chariot_X - Temp_X) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						for (int k = 0; k < Move_X; k++)//����Ѳ·�Ƿ�������ߣ������߶���
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
							if (IfOkMove == false) //ֻҪ��һ��false���ǲ��е�
							{
								break;
							}
							if (IfOkMove && k == Move_X - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - Move_X];
								Piece_Logic::mMouseDownRange[i][j - Move_X] = Temp;
								mWE_Left_Chariot_X -= (Move_X * 60);

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
					if (Piece_Logic::mMouseDownRange[i][j] == 9)//������������ߵ�܇
					{
						int Temp_X = Piece_Logic::__Return_mBlueStandardCoor___().x;
						int Temp_Y = Piece_Logic::__Return_mBlueStandardCoor___().y;//�õ�������ı�׼����

						int Move_X = (Temp_X - mWE_Left_Chariot_X) / 60;//�õ�Ҫ�ƶ��Ĵ�����ͬʱҲ��Ŀ���Y����

						for (int k = 0; k < Move_X; k++)//����Ѳ·�Ƿ�������ߣ������߶���
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
							if (IfOkMove == false) //ֻҪ��һ��false���ǲ��е�
							{
								break;
							}
							if (IfOkMove && k == Move_X - 1)//֤������·�����ߵ�ͨ
							{
								int Temp = Piece_Logic::mMouseDownRange[i][j];
								Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + Move_X];
								Piece_Logic::mMouseDownRange[i][j + Move_X] = Temp;
								mWE_Left_Chariot_X += (Move_X * 60);

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