#pragma once
#include<iostream>

//�ҷ����ʿ���߼�
class WE_Left_Man_Logic
{

public:
	//��ʿ��ǰ
	BOOL Man_MoveForwardTarget(int mWE_Man_X, int mWE_Man_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Man_X - 90 && Mouse_X <= mWE_Man_X - 30
			&& Mouse_Y >= mWE_Man_Y - 90 && Mouse_Y <= mWE_Man_Y - 30)
		{
			if (Mouse_X < 200)
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		return FALSE;
	}
	//��ʿ����ǰ
	BOOL Man_MoveBackTarget(int mWE_Man_X, int mWE_Man_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Man_X + 30 && Mouse_X <= mWE_Man_X + 90
			&& Mouse_Y >= mWE_Man_Y - 90 && Mouse_Y <= mWE_Man_Y - 30)
		{
			if (Mouse_X > 380)//ʿ��Խ�����⣬����ṹ�ж���������
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		return FALSE;
	}
	//��ʿ�����
	BOOL Man_MoveLeftTarget(int mWE_Man_X, int mWE_Man_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Man_X - 90 && Mouse_X <= mWE_Man_X - 30
			&& Mouse_Y >= mWE_Man_Y + 30 && Mouse_Y <= mWE_Man_Y + 90)
		{
			if (Mouse_X < 200)
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		return FALSE;
	}
	//��ʿ���Һ�
	BOOL Man_MoveRightTarget(int mWE_Man_X, int mWE_Man_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Man_X + 30 && Mouse_X <= mWE_Man_X + 90
			&& Mouse_Y >= mWE_Man_Y + 30 && Mouse_Y <= mWE_Man_Y + 90)
		{
			if (Mouse_X > 380)//ʿ��Խ�����⣬����ṹ�ж���������
			{
				return FALSE;
			}
			else
			{
				return TRUE;
			}
		}
		return FALSE;
	}
};