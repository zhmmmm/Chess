#include "ENEMY_Command.h"

RedCur ENEMY_Command::mReturnRedCurStandardCoor = { 0,0 };

ENEMY_Command::ENEMY_Command()
{
	mENEMY_Command_X = 290;
	mENEMY_Command_Y = 50;
	mRedCur.x = 290;
	mRedCur.y = 290;
	for (int i = 0; i < 10; i++)//�õ���׼����
	{
		int Temp_x = 50;
		int Temp_y = 50;
		for (int j = 0; j < 9; j++)
		{
			mRedStandardCoor[i][j].x = Temp_x + (j * 60);
			mRedStandardCoor[i][j].y = Temp_y + (i * 60);
		}
	}//�õ�ÿһ�����ӵı�׼����
}
ENEMY_Command::~ENEMY_Command()
{
	GoBitmap->ReleaseBmp(mCommand_Bmpid);
}
void ENEMY_Command::InitPiece()
{
	mCommand_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Command.bmp");
	mRedCursor_Bmpid = GoBitmap->Load_Bmp("Image\\Cursor\\RedCursor.bmp");
}
void ENEMY_Command::RenderPiece()
{
	m.Translate(mENEMY_Command_X, mENEMY_Command_Y);
	GoBitmap->SetWorldTransform(m);
	GoBitmap->DrawBmp2(mCommand_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
	m.Identity();
	GoBitmap->SetWorldTransform(m);
}
void ENEMY_Command::RenderCursor()
{
	m.Translate(mRedCur.x, mRedCur.y);
	GoBitmap->SetWorldTransform(m);
	GoBitmap->DrawBmp2(mRedCursor_Bmpid, -32, -32, 64, 64, 0, 0, 64, 64, 0XFFFFFF);
	m.Identity();
	GoBitmap->SetWorldTransform(m);
}
void ENEMY_Command::PieceLogicUpdata(int Which, int State, int x, int y)
{
	if (Piece::Reutrn_mWe() == 1)//�õз�������
	{
		RedCursorStandardCoor(Which, State, x, y);
		RenderCursor();//��Ⱦ��ɫ���
		if (Which == 1 && State == 1)
		{
			if (x >= mENEMY_Command_X - 30 && x <= mENEMY_Command_X + 30
				&& y >= mENEMY_Command_Y - 30 && y <= mENEMY_Command_Y + 30
				&& Which == 1 && State == 1)
			{
				if (Piece_Logic::mWE_CommandState || Piece_Logic::mWE_CommandState == 0)//����������
				{
					Piece_Logic::mWE_CommandState = 50;
				}
			}

			if (Piece_Logic::mWE_CommandState == 50)//�����������ߵķ�Χ
			{
				BOOL BoolForward = FALSE;
				BoolForward = ENEMY_Command_Logic::Command_MoveForwardTarget(mENEMY_Command_X, mENEMY_Command_Y, x, y);
				BOOL BoolBack = FALSE;
				BoolBack = ENEMY_Command_Logic::Command_MoveBackTarget(mENEMY_Command_X, mENEMY_Command_Y, x, y);
				BOOL BoolLeft = FALSE;
				BoolLeft = ENEMY_Command_Logic::Command_MoveLeftTarget(mENEMY_Command_X, mENEMY_Command_Y, x, y);
				BOOL BoolRight = FALSE;
				BoolRight = ENEMY_Command_Logic::Command_MoveRightTarget(mENEMY_Command_X, mENEMY_Command_Y, x, y);
				__ENEMY_Command_Logic__(BoolForward, BoolBack, BoolLeft, BoolRight);
			}
		}
	}
}
int ENEMY_Command::__ENEMY_Command_Logic__(BOOL BoolForward, BOOL BoolBack, BOOL BoolLeft, BOOL BoolRight)
{
	if (BoolForward)
	{
		for (int i = 0; i < 12; i++)
		{
			bool ifok = false;
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 50)//���������ӽ���
				{
					if (Piece_Logic::mMouseDownRange[i + 1][j] >= 200 && Piece_Logic::mMouseDownRange[i + 1][j] != 999)//����ǰ���ǿյ�
					{
						//���ƶ�����֮���������ý���������
						int Temp = Piece_Logic::mMouseDownRange[i][j];
						Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i + 1][j];
						Piece_Logic::mMouseDownRange[i + 1][j] = Temp;
						mENEMY_Command_Y += 60;
						Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
	if (BoolBack)
	{
		for (int i = 0; i < 12; i++)
		{
			bool ifok = false;
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 50)//���������ӽ���
				{
					if (Piece_Logic::mMouseDownRange[i - 1][j] >= 200 && Piece_Logic::mMouseDownRange[i - 1][j] != 999)//���������ǿյ�
					{
						//���ƶ�����֮���������ý���������
						int Temp = Piece_Logic::mMouseDownRange[i][j];
						Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i - 1][j];
						Piece_Logic::mMouseDownRange[i - 1][j] = Temp;
						mENEMY_Command_Y -= 60;
						Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
	if (BoolLeft)
	{
		for (int i = 0; i < 12; i++)
		{
			bool ifok = false;
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 50)//���������ӽ���
				{
					if (Piece_Logic::mMouseDownRange[i][j + 1] >= 200 && Piece_Logic::mMouseDownRange[i][j + 1] != 999)//��������ǿյ�
					{
						//���ƶ�����֮���������ý���������
						int Temp = Piece_Logic::mMouseDownRange[i][j];
						Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j + 1];
						Piece_Logic::mMouseDownRange[i][j + 1] = Temp;
						mENEMY_Command_X += 60;
						Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
	if (BoolRight)
	{
		for (int i = 0; i < 12; i++)
		{
			bool ifok = false;
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 50)//���������ӽ���
				{
					if (Piece_Logic::mMouseDownRange[i][j - 1] >= 200 && Piece_Logic::mMouseDownRange[i][j - 1] != 999)//�����ұ��ǿյ�
					{
						//���ƶ�����֮���������ý���������
						int Temp = mMouseDownRange[i][j];
						Piece_Logic::mMouseDownRange[i][j] = Piece_Logic::mMouseDownRange[i][j - 1];
						Piece_Logic::mMouseDownRange[i][j - 1] = Temp;
						mENEMY_Command_X -= 60;
						Piece_Logic::__WE__mWE_CommandState(0);//������Ҫ
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
void ENEMY_Command::RedCursorStandardCoor(int Which, int State, int Mouse_X, int Mouse_Y)//�õ���ɫ���ı�׼λ��
{
	if (Which == 1 && State == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (Mouse_X >= mRedStandardCoor[i][j].x - 30 && Mouse_X <= mRedStandardCoor[i][j].x + 30
					&& Mouse_Y >= mRedStandardCoor[i][j].y - 30 && Mouse_Y <= mRedStandardCoor[i][j].y + 30)
				{
					//�õ���ɫ���ı�׼����
					mRedCur.x = mRedStandardCoor[i][j].x;
					mRedCur.y = mRedStandardCoor[i][j].y;
					mReturnRedCurStandardCoor.x = 0;
					mReturnRedCurStandardCoor.y = 0;
					mReturnRedCurStandardCoor.x = mRedStandardCoor[i][j].x;
					mReturnRedCurStandardCoor.y = mRedStandardCoor[i][j].y;
				}
			}
		}
	}
}
RedCur ENEMY_Command::__mReturnRedCurStandardCoor__()
{
	return mReturnRedCurStandardCoor;
}