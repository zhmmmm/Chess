#pragma once
#include <iostream>

//敌方将军逻辑
class ENEMY_Command_Logic
{

public:
	ENEMY_Command_Logic(){}
	//将军向前
	BOOL Command_MoveForwardTarget(int mENEMY_Command_X, int mENEMY_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mENEMY_Command_X - 30 && Mouse_X <= mENEMY_Command_X + 30
			&& Mouse_Y <= mENEMY_Command_Y + 90 && Mouse_Y >= mENEMY_Command_Y + 30)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}
	//将军向后
	BOOL Command_MoveBackTarget(int mENEMY_Command_X, int mENEMY_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mENEMY_Command_X - 30 && Mouse_X <= mENEMY_Command_X + 30
			&& Mouse_Y >= mENEMY_Command_Y - 90 && Mouse_Y <= mENEMY_Command_Y - 30)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}
	//将军向左
	BOOL Command_MoveLeftTarget(int mENEMY_Command_X, int mENEMY_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X <= mENEMY_Command_X + 90 && Mouse_X >= mENEMY_Command_X + 30
			&& Mouse_Y >= mENEMY_Command_Y - 30 && Mouse_Y <= mENEMY_Command_Y + 30)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}
	//将军向右
	BOOL Command_MoveRightTarget(int mENEMY_Command_X, int mENEMY_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mENEMY_Command_X - 90 && Mouse_X <= mENEMY_Command_X - 30
			&& Mouse_Y >= mENEMY_Command_Y - 30 && Mouse_Y <= mENEMY_Command_Y + 30)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}
};
