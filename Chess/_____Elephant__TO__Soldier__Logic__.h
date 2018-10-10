#pragma once
#include <iostream>
#include <Windows.h>

//这里是所有棋子的逻辑，无论敌方还是我方都可以继承这个类
//从象到兵的移动范围逻辑，无论是左边的还是右边的，还是敌方的左边还是右边都继承这个
//敌方从士开始
class _____Elephant__TO__Soldier__Logic__
{

public:
	//我方象，左前
	BOOL Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//右前
	BOOL Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//左后
	BOOL Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//右后
	BOOL Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);

	//敌方象，左前
	BOOL ENEMY_Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//右前
	BOOL ENEMY_Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//左后
	BOOL ENEMY_Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//右后
	BOOL ENEMY_Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);

	//士向前
	BOOL Man_MoveForwardTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);
	//向右前
	BOOL Man_MoveBackTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);
	//向左后
	BOOL Man_MoveLeftTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);
	//向右后
	BOOL Man_MoveRightTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);

	//马的八个方向
//马向前
	BOOL _0__Horse_MoveForwardTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);
	//马右前
	BOOL _1__Horse_MoveBackTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);
	//马左后
	BOOL _2__Horse_MoveLeftTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);
	//马右后
	BOOL _3__Horse_MoveRightTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);
	//马向前
	BOOL _4__Horse_MoveForwardTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);
	//马右前
	BOOL _5__Horse_MoveBackTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);
	//马左后
	BOOL _6__Horse_MoveLeftTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);
	//马右后
	BOOL _7__Horse_MoveRightTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y);

};