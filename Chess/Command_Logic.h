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
			if (Mouse_Y < 440)//�������ܳ���
			{
				return FALSE;
			}
			else
			{
				int temp = 0;
				return TRUE;
			}
		}
		return FALSE;
	}
	//�������
	BOOL Command_MoveBackTarget(int mWE_Command_X, int mWE_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Command_X - 30 && Mouse_X <= mWE_Command_X + 30
			&& Mouse_Y >= mWE_Command_Y + 30 && Mouse_Y <= mWE_Command_Y + 90)
		{
			if (Mouse_Y > 620)//�������ܳ���
			{
				return FALSE;
			}
			else
			{
				int temp = 0;
				return TRUE;
			}
		}
		return FALSE;
	}
	//��������
	BOOL Command_MoveLeftTarget(int mWE_Command_X, int mWE_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Command_X - 90 && Mouse_X <= mWE_Command_X - 30
			&& Mouse_Y >= mWE_Command_Y - 30 && Mouse_Y <= mWE_Command_Y + 30)
		{
			if (Mouse_X < 200)//�������ܳ���
			{
				return FALSE;
			}
			else
			{
				int temp = 0;
				return TRUE;
			}
		}
		return FALSE;
	}
	//��������
	BOOL Command_MoveRightTarget(int mWE_Command_X, int mWE_Command_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Command_X + 30 && Mouse_X <= mWE_Command_X + 90
			&& Mouse_Y >= mWE_Command_Y - 30 && Mouse_Y <= mWE_Command_Y + 30)
		{
			if (Mouse_X > 380)//�������ܳ���
			{
				return FALSE;
			}
			else
			{
				int temp = 0;
				return TRUE;
			}
		}
		return FALSE;
	}

};
