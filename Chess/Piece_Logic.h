#pragma once
#include <iostream>
#include <Windows.h>
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "WE_Command_Logic.h"

/*
从士开始，后面的范围逻辑都是继承过来的
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

//所有棋子的逻辑集合
class Piece_Logic:public Command_Logic
{
    static int mMap[12][11];//地图
public:
	static int mMouseDownRange[12][11];//鼠标按下范围代表的值

	//所有棋子所表示的范围
	//我方棋子
public:
	static int mWE_Command_X;//我方主将的X
	static int mWE_CommandState;//左右棋子根据这个是否哪一个棋可以走
	static int mWE_Command_Y;

	//敌方棋子





	//通过让棋子调用的此值，达到朝那个方向移动，移动多少
	static int ReturnCommand_State_X;
	static int ReturnCommand_State_Y;



	//==============================================
	//上面为静态的
	int BlueCur_Bmpid = 0;
	BlueCur mBlueCur;//蓝色方当前有初始光标坐标
	CurCoor mBlueStandardCoor[10][9];//蓝色方光标的标准坐标

	Matrix3 m;
	Vector2D mCoor;
public:
	Piece_Logic();
	void InitData();
	void InitBlue_Cursor();//初始化蓝色光标
	void RenderBlue_Cursor();//绘制蓝色光标
	void BlueCursorStandardCoor(int Mouse_X,int Mouse_Y);//得到蓝色光标的标准位置

	void __Piece_Logic__(int Which, int State, int Mouse_X, int Mouse_Y);//棋子《将》 的逻辑
	int __WE__PieceCommand_Logic___(BOOL BoolForward, BOOL BoolBack, BOOL Left, BOOL Right);//我方棋子将军逻辑
	void __WE__mWE_CommandState(int WE_CommandState);//移动完了为棋子解锁
	int __Return__ReturnCommand_State_X();//返回X轴的移动
	int __Return__ReturnCommand_State_Y();//返回Y轴的移动
	void __Change__ReturnCommand_State_X(int ReturnCommand_State_X);//改变X轴的移动
	void __Change__ReturnCommand_State_Y(int ReturnCommand_State_Y);//改变Y轴的移动
};