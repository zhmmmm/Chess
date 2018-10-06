#include "Piece_Logic.h"

int Piece_Logic::mMap[12][11] = //1��17Ϊ�ҷ��������ӣ�10��170Ϊ�з�����
{
		999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 999,
		999,  90,    80,   70,   60,    50,   40,   30,    20,   10,  999,
		999,  0,       0,      0,     0,      0,     0,      0,      0,     0,   999,
		999,  0,     120,    0,     0,       0,     0,      0,    110,  0,   999,
		999, 170,     0,   160,   0,    150,   0,    140,   0,  130, 999,
		999,  0,        0,     0,       0,       0,    0,      0,     0,      0,  999,
		/*
		����                                                ����
		*/
		999,  0,        0,     0,       0,       0,    0,      0,     0,      0,     999,
		999, 17,       0,     16,     0,      15,   0,     14,   0,     13,    999,
		999,  0,       12,    0,       0,        0,    0,      0,    11,    0,     999,
		999,  0,        0,     0,       0,        0,    0,      0,     0,      0,     999,
		999,  9,        8,     7,       6,        5,    4,      3,     2,      1,     999,
		999, 999,   999, 999,  999,    999, 999, 999, 999, 999, 999,
};
int Piece_Logic::mMouseDownRange[12][11] = //200��257Ϊ�յ�
{
	999,     999,      999,     999,     999,     999,     999,   999,    999,    999,   999,
	999,     90,        80,        70,        60,       50,        40,     30,      20,      10,     999,
	999,     200,     201,      202,     203,      204,     205,   206,     207,   208,   999,
	999,    209,      120,      210,     211,       212,    213,    214,    110,   215,   999,
	999,    170,      216,      160,     217,       150,    218,    140,    219,   130,   999,
	999,    220,      221,      222,     223,       224,    225,    226,    227,   228,   999,
	/*
	����                                                ����
	*/
	999,    229,        230,     231,       232,       233,     234,       235,     236,      237,     999,
	999,    17,          238,     16,         239,        15,       240,      14,        241,      13,        999,
	999,    242,       12,        243,       244,        245,     246,      247,      11,       248,      999,
	999,    249,       250,     251,        252,        253,     254,      255,      256,      257,     999,
	999,    9,           8,           7,             6,             5,         4,            3,          2,           1,         999,
	999,    999,      999,      999,        999,       999,     999,      999,      999,      999,       999,
};

//�з�

//�ҷ�
int Piece_Logic::mWE_Command_X = 290;
int Piece_Logic::mWE_CommandState = 0;//�����Ƿ�����
int Piece_Logic::ReturnCommand_State_X = 0;
int Piece_Logic::ReturnCommand_State_Y = 0;
int Piece_Logic::mWE_Command_Y = 590;
void Piece_Logic::__Piece_Logic__(int Which, int State, int Mouse_X, int Mouse_Y)//���ӡ����� ���߼�
{

	if((Which == 1 && State == 1))
	{
		if (Mouse_X >= mWE_Command_X - 30 && Mouse_X <= mWE_Command_X + 30
			&& Mouse_Y >= mWE_Command_Y - 30 && Mouse_Y <= mWE_Command_Y + 30
			&& Which == 1 && State == 1)//��ɫ����������ҵ�����
		{
			if (mWE_CommandState == 0)
			{
				mWE_CommandState = 1;//�ҷ��������������׼��Ѱ�ҹ���Ŀ��
			}
		}

		BlueCursorStandardCoor(Mouse_X, Mouse_Y);//�õ���ɫ���ı�׼λ��

		if (mWE_CommandState == 1 && (Mouse_X >= 200 && Mouse_X <= 280) || (Mouse_Y >= 440 && Mouse_Y <= 620))/*�����ж�����δ֪Bug	&&Mouse_X >= 200 && Mouse_X <= 280 ��&&������ΪʲôҪ���ߡ��� Mouse_Y >= 440 && Mouse_Y <= 620*/
		{
			BOOL BoolForward = FALSE;
			BoolForward = Command_Logic::Command_MoveForwardTarget(mWE_Command_X, mWE_Command_Y, Mouse_X, Mouse_Y);
			BOOL BoolBack = FALSE;
			BoolBack = Command_Logic::Command_MoveBackTarget(mWE_Command_X, mWE_Command_Y, Mouse_X, Mouse_Y);
			BOOL BoolLeft = FALSE;
			BoolLeft = Command_Logic::Command_MoveLeftTarget(mWE_Command_X, mWE_Command_Y, Mouse_X, Mouse_Y);
			BOOL BoolRight = FALSE;
			BoolRight = Command_Logic::Command_MoveRightTarget(mWE_Command_X, mWE_Command_Y, Mouse_X, Mouse_Y);
			
			int TempReturn = __WE__PieceCommand_Logic___(BoolForward, BoolBack, BoolLeft,BoolRight);
		}


	}
}
//�������ӵ��߼�
int Piece_Logic::__WE__PieceCommand_Logic___(BOOL BoolForward,BOOL BoolBack,BOOL BoolLeft,BOOL BoolRight)//�ҷ����ӽ����߼�
{
	if (BoolForward)
	{
		for (int i = 0; i < 12; i++)
		{
			bool ifok = false;
			for (int j = 0; j < 11; j++)
			{
				if (mMouseDownRange[i][j] == 5)//���������ӽ���
				{
					if (mMouseDownRange[i - 1][j] >= 200)//����ǰ���ǿյ�
					{
						ReturnCommand_State_Y--;
						//���ƶ�����֮���������ý���������
						int Temp = mMouseDownRange[i][j];
						mMouseDownRange[i][j] = mMouseDownRange[i - 1][j];
						mMouseDownRange[i - 1][j] = Temp;
						mWE_Command_Y -= 60;

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
				if (mMouseDownRange[i][j] == 5)//���������ӽ���
				{
					if (mMouseDownRange[i + 1][j] >= 200)//���������ǿյ�
					{
						ReturnCommand_State_Y++;
						//���ƶ�����֮���������ý���������
						int Temp = mMouseDownRange[i][j];
						mMouseDownRange[i][j] = mMouseDownRange[i + 1][j];
						mMouseDownRange[i + 1][j] = Temp;
						mWE_Command_Y += 60;

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
				if (mMouseDownRange[i][j] == 5)//���������ӽ���
				{
					if (mMouseDownRange[i][j - 1] >= 200)//��������ǿյ�
					{
						ReturnCommand_State_X--;
						//���ƶ�����֮���������ý���������
						int Temp = mMouseDownRange[i][j];
						mMouseDownRange[i][j] = mMouseDownRange[i][j - 1];
						mMouseDownRange[i][j - 1] = Temp;
						mWE_Command_X -= 60;

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
				if (mMouseDownRange[i][j] == 5)//���������ӽ���
				{
					if (mMouseDownRange[i][j + 1] >= 200)//�����ұ��ǿյ�
					{
						ReturnCommand_State_X++;
						//���ƶ�����֮���������ý���������
						int Temp = mMouseDownRange[i][j];
						mMouseDownRange[i][j] = mMouseDownRange[i][j + 1];
						mMouseDownRange[i][j + 1] = Temp;
						mWE_Command_X += 60;

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
void Piece_Logic::__WE__mWE_CommandState(int WE_CommandState)//�ƶ�����Ϊ���ӽ���
{
	this->mWE_CommandState = WE_CommandState;
}
int Piece_Logic::__Return__ReturnCommand_State_X()//����X����ƶ�
{
	return ReturnCommand_State_X;
}
int Piece_Logic::__Return__ReturnCommand_State_Y()//����Y����ƶ�
{
	return ReturnCommand_State_Y;
}
void Piece_Logic::__Change__ReturnCommand_State_X(int ReturnCommand_State_X)//�ı�X����ƶ�
{
	this->ReturnCommand_State_X = ReturnCommand_State_X;
}
void Piece_Logic::__Change__ReturnCommand_State_Y(int ReturnCommand_State_Y)//�ı�Y����ƶ�
{
	this->ReturnCommand_State_Y = ReturnCommand_State_Y;
}

//=============================
void Piece_Logic::InitBlue_Cursor()//��ʼ����ɫ���
{
	BlueCur_Bmpid = GoBitmap->Load_Bmp("Image\\Cursor\\BlueCursor.bmp");
}
Piece_Logic::Piece_Logic()//Piece_Logic�Ĺ��캯��
{
	InitDate();
}
void Piece_Logic::InitDate()
{
	mBlueCur.x = 290;
	mBlueCur.y = 350;
	InitBlue_Cursor();
	for (int i = 0; i < 10; i++)//�õ���׼����
	{
		int Temp_x = 50;
		int Temp_y = 50;
		for (int j = 0; j < 9; j++)
		{
			mBlueStandardCoor[i][j].x = Temp_x + (j * 60);
			mBlueStandardCoor[i][j].y = Temp_y + (i * 60);
		}
	}//�õ�ÿһ�����ӵı�׼����
}
void Piece_Logic::RenderBlue_Cursor()//������ɫ���
{
	m.Translate(mBlueCur.x, mBlueCur.y);
	GoBitmap->SetWorldTransform(m);
	GoBitmap->DrawBmp2(BlueCur_Bmpid, -32, -32, 64, 64, 0, 0, 64, 64, 0XFFFFFF);
	m.Identity();
	GoBitmap->SetWorldTransform(m);
}
void Piece_Logic::BlueCursorStandardCoor(int Mouse_X, int Mouse_Y)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Mouse_X >= mBlueStandardCoor[i][j].x - 30 && Mouse_X <= mBlueStandardCoor[i][j].x + 30
				&& Mouse_Y >= mBlueStandardCoor[i][j].y - 30 && Mouse_Y <= mBlueStandardCoor[i][j].y + 30)
			{
				//��ɫ���ĵõ���׼����
				mBlueCur.x = mBlueStandardCoor[i][j].x;
				mBlueCur.y = mBlueStandardCoor[i][j].y;
			}
		}
	}
}