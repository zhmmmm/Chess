#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

struct RedCur
{
	int x;
	int y;
};
struct RedCurCoor
{
	int x;
	int y;
};

////继承了棋子和棋子逻辑
class ENEMY_Command :public Piece,public Piece_Logic //敌方主帅
{
	int mCommand_Bmpid = 0;
	int mRedCursor_Bmpid = 0;

	float mCommand_X = 0;
	float mCommand_Y = 0;


	RedCur mRedCur;//红色方当前有初始光标坐标
	RedCurCoor mRedStandardCoor[10][9];//红色方光标的标准坐标

	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Command()
	{
		mCommand_X = 290.0f;
		mCommand_Y = 50.0f;
		mRedCur.x = 290;
		mRedCur.y = 290;
		for (int i = 0; i < 10; i++)//得到标准坐标
		{
			int Temp_x = 50;
			int Temp_y = 50;
			for (int j = 0; j < 9; j++)
			{
				mRedStandardCoor[i][j].x = Temp_x + (j * 60);
				mRedStandardCoor[i][j].y = Temp_y + (i * 60);
			}
		}//得到每一个落子的标准坐标
	}
	~ENEMY_Command()
	{
		GoBitmap->ReleaseBmp(mCommand_Bmpid);
	}
	void InitPiece()
	{
		mCommand_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Red_Square\\Command.bmp");
		mRedCursor_Bmpid = GoBitmap->Load_Bmp("Image\\Cursor\\RedCursor.bmp");
	}
	void RenderPiece()
	{
		m.Translate(mCommand_X, mCommand_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mCommand_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void RenderCursor()
	{
		m.Translate(mRedCur.x, mRedCur.y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mRedCursor_Bmpid, -32, -32, 64, 64, 0, 0, 64, 64, 0XFFFFFF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)
	{
		if (Piece::Reutrn_mWe() == 1)//该敌方走棋了
		{
			RedCursorStandardCoor(Which, State, x, y);
			RenderCursor();//渲染红色光标


		}

	}
	void RedCursorStandardCoor(int Which, int State,int Mouse_X, int Mouse_Y)//得到红色光标的标准位置
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
						//蓝色光标的得到标准坐标
						mRedCur.x = mRedStandardCoor[i][j].x;
						mRedCur.y = mRedStandardCoor[i][j].y;
					}
				}
			}
		}
	}
};