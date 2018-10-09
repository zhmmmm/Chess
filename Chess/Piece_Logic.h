#pragma once
#include <iostream>
#include <Windows.h>
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "WE_Command_Logic.h"

/*
��ʿ��ʼ������ķ�Χ�߼����Ǽ̳й�����
*/

struct BlueCur
{
	int x;
	int y;
};
struct CurCoor
{
	int x;
	int y;
};

//�������ӵ��߼�����
class Piece_Logic:public Command_Logic
{
    static int mMap[12][11];//��ͼ
public:
	static int mMouseDownRange[12][11];//��갴�·�Χ�����ֵ

	//������������ʾ�ķ�Χ
	//�ҷ�����
public:
	static int mWE_Command_X;//�ҷ�������X
	static int mWE_CommandState;//�������Ӹ�������Ƿ���һ���������
	static int mWE_Command_Y;

	//�з�����





	//ͨ�������ӵ��õĴ�ֵ���ﵽ���Ǹ������ƶ����ƶ�����
	static int ReturnCommand_State_X;
	static int ReturnCommand_State_Y;



	//==============================================
	//����Ϊ��̬��
	int BlueCur_Bmpid = 0;
	BlueCur mBlueCur;//��ɫ����ǰ�г�ʼ�������
	CurCoor mBlueStandardCoor[10][9];//��ɫ�����ı�׼����

	Matrix3 m;
	Vector2D mCoor;
public:
	Piece_Logic();
	void InitData();
	void InitBlue_Cursor();//��ʼ����ɫ���
	void RenderBlue_Cursor();//������ɫ���
	void BlueCursorStandardCoor(int Mouse_X,int Mouse_Y);//�õ���ɫ���ı�׼λ��

	void __Piece_Logic__(int Which, int State, int Mouse_X, int Mouse_Y);//���ӡ����� ���߼�
	int __WE__PieceCommand_Logic___(BOOL BoolForward, BOOL BoolBack, BOOL Left, BOOL Right);//�ҷ����ӽ����߼�
	void __WE__mWE_CommandState(int WE_CommandState);//�ƶ�����Ϊ���ӽ���
	int __Return__ReturnCommand_State_X();//����X����ƶ�
	int __Return__ReturnCommand_State_Y();//����Y����ƶ�
	void __Change__ReturnCommand_State_X(int ReturnCommand_State_X);//�ı�X����ƶ�
	void __Change__ReturnCommand_State_Y(int ReturnCommand_State_Y);//�ı�Y����ƶ�
};