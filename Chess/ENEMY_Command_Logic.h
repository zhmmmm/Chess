#pragma once
#include <iostream>

//�з������߼�
class ENEMY_Command_Logic
{

public:
	ENEMY_Command_Logic(){}
	//������ǰ
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
	//�������
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
	//��������
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
	//��������
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
