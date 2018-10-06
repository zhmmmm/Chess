#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//С�� 2
class WE_2_Soldier :public Piece, public Piece_Logic
{
	int mWE_2_Soldier_Bmpid = 0;

	int mWE_2_Soldier_X = 0;
	int mWE_2_Soldier_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_2_Soldier()
	{
		mWE_2_Soldier_X = 290;
		mWE_2_Soldier_Y = 410;
	}
	~WE_2_Soldier()
	{
		GoBitmap->ReleaseBmp(mWE_2_Soldier_Bmpid);
	}
	void InitPiece()                    //��������
	{
		mWE_2_Soldier_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Soldier.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mWE_2_Soldier_X, mWE_2_Soldier_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mWE_2_Soldier_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //�����߼�����
	{

	}
};