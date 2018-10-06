#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"

//С�� 4
class WE_4_Soldier :public Piece, public Piece_Logic
{
	int mWE_4_Soldier_Bmpid = 0;

	int mWE_4_Soldier_X = 0;
	int mWE_4_Soldier_Y = 0;


	Matrix3 m;
	Vector2D mCoor;
public:
	WE_4_Soldier()
	{
		mWE_4_Soldier_X = 530;
		mWE_4_Soldier_Y = 410;
	}
	~WE_4_Soldier()
	{
		GoBitmap->ReleaseBmp(mWE_4_Soldier_Bmpid);
	}
	void InitPiece()                    //��������
	{
		mWE_4_Soldier_Bmpid = GoBitmap->Load_Bmp("Image\\Piece\\Blue_Square\\Soldier.bmp");
	}
	void RenderPiece()            //��Ⱦ����
	{
		m.Translate(mWE_4_Soldier_X, mWE_4_Soldier_Y);
		GoBitmap->SetWorldTransform(m);
		GoBitmap->DrawBmp2(mWE_4_Soldier_Bmpid, -30, -30, 60, 60, 0, 0, 60, 60, 0XFF00FF);
		m.Identity();
		GoBitmap->SetWorldTransform(m);
	}
	void PieceLogicUpdata(int Which, int State, int x, int y)  //�����߼�����
	{

	}
};