#pragma once
#include <iostream>
#include <Windows.h>

//���ӽ������߼�
class Command_Logic
{
public:
	//������ǰ
	BOOL Command_MoveForwardTarget(int mWE_Command_X,int mWE_Command_Y, int Mouse_X,int Mouse_Y)
	{
		if (Mouse_X >= mWE_Command_X - 30 && Mouse_X <= mWE_Command_X + 30
			&& Mouse_Y >= mWE_Command_Y - 90 && Mouse_Y <= mWE_Command_Y - 30)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}
	//�������
	BOOL Command_MoveBackTarget(int mWE_Command_X, int mWE_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Command_X - 30 && Mouse_X <= mWE_Command_X + 30
			&& Mouse_Y >= mWE_Command_Y + 30 && Mouse_Y <= mWE_Command_Y + 90)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}
	//��������
	BOOL Command_MoveLeftTarget(int mWE_Command_X, int mWE_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Command_X - 90 && Mouse_X <= mWE_Command_X - 30
			&& Mouse_Y >= mWE_Command_Y - 30 && Mouse_Y <= mWE_Command_Y + 30)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}
	//��������
	BOOL Command_MoveRightTarget(int mWE_Command_X, int mWE_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Command_X + 30 && Mouse_X <= mWE_Command_X + 90
			&& Mouse_Y >= mWE_Command_Y - 30 && Mouse_Y <= mWE_Command_Y + 30)
		{
			int temp = 0;
			return TRUE;
		}
		return FALSE;
	}

};
