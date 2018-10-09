#pragma once
#include <iostream>
#include <Windows.h>

//这里是所有棋子的逻辑，无论敌方还是我方都可以继承这个类
//从象到兵的移动范围逻辑，无论是左边的还是右边的，还是敌方的左边还是右边都继承这个
class _____Elephant__TO__Soldier__Logic__
{

public:
	//象，左前
	BOOL Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//右前
	BOOL Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//左后
	BOOL Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//右后
	BOOL Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);

};