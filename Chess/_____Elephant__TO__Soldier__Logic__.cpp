#include "_____Elephant__TO__Soldier__Logic__.h"

//�ҷ���
BOOL _____Elephant__TO__Soldier__Logic__::Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X - 150 && Mouse_X <= mPUBLIC_Elephant_X - 90
		&& Mouse_Y >= mPUBLIC_Elephant_Y - 150 && Mouse_Y <= mPUBLIC_Elephant_Y - 90)
	{
		if (Mouse_Y < 350)
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
BOOL _____Elephant__TO__Soldier__Logic__::Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X + 90 && Mouse_X <= mPUBLIC_Elephant_X + 150
		&& Mouse_Y >= mPUBLIC_Elephant_Y - 150 && Mouse_Y <= mPUBLIC_Elephant_Y - 90)
	{
		if (Mouse_Y < 350)//���Խ�����⣬����ṹ�ж���������
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
BOOL _____Elephant__TO__Soldier__Logic__::Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X - 150 && Mouse_X <= mPUBLIC_Elephant_X - 90
		&& Mouse_Y >= mPUBLIC_Elephant_Y + 90 && Mouse_Y <= mPUBLIC_Elephant_Y + 150)
	{
		if (Mouse_Y > 620)
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
BOOL _____Elephant__TO__Soldier__Logic__::Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X + 90 && Mouse_X <= mPUBLIC_Elephant_X + 150
		&& Mouse_Y >= mPUBLIC_Elephant_Y + 90 && Mouse_Y <= mPUBLIC_Elephant_Y + 150)
	{
		if (Mouse_Y > 620)//���Խ�����⣬����ṹ�ж���������
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

//�з�
BOOL _____Elephant__TO__Soldier__Logic__::ENEMY_Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X - 150 && Mouse_X <= mPUBLIC_Elephant_X - 90
		&& Mouse_Y >= mPUBLIC_Elephant_Y - 150 && Mouse_Y <= mPUBLIC_Elephant_Y - 90)
	{
		if (Mouse_Y > 350)
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
BOOL _____Elephant__TO__Soldier__Logic__::ENEMY_Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X + 90 && Mouse_X <= mPUBLIC_Elephant_X + 150
		&& Mouse_Y >= mPUBLIC_Elephant_Y - 150 && Mouse_Y <= mPUBLIC_Elephant_Y - 90)
	{
		if (Mouse_Y > 350)//���Խ�����⣬����ṹ�ж���������
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
BOOL _____Elephant__TO__Soldier__Logic__::ENEMY_Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X - 150 && Mouse_X <= mPUBLIC_Elephant_X - 90
		&& Mouse_Y >= mPUBLIC_Elephant_Y + 90 && Mouse_Y <= mPUBLIC_Elephant_Y + 150)
	{
		if (Mouse_Y < 20)
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
BOOL _____Elephant__TO__Soldier__Logic__::ENEMY_Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X + 90 && Mouse_X <= mPUBLIC_Elephant_X + 150
		&& Mouse_Y >= mPUBLIC_Elephant_Y + 90 && Mouse_Y <= mPUBLIC_Elephant_Y + 150)
	{
		if (Mouse_Y < 20)//���Խ�����⣬����ṹ�ж���������
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

//ʿ
BOOL _____Elephant__TO__Soldier__Logic__::Man_MoveForwardTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Man_X - 90 && Mouse_X <= mPUBLIC_Man_X - 30
		&& Mouse_Y >= mPUBLIC_Man_Y - 90 && Mouse_Y <= mPUBLIC_Man_Y - 30)
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
BOOL _____Elephant__TO__Soldier__Logic__::Man_MoveBackTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Man_X + 30 && Mouse_X <= mPUBLIC_Man_X + 90
		&& Mouse_Y >= mPUBLIC_Man_Y - 90 && Mouse_Y <= mPUBLIC_Man_Y - 30)
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
BOOL _____Elephant__TO__Soldier__Logic__::Man_MoveLeftTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Man_X - 90 && Mouse_X <= mPUBLIC_Man_X - 30
		&& Mouse_Y >= mPUBLIC_Man_Y + 30 && Mouse_Y <= mPUBLIC_Man_Y + 90)
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
BOOL _____Elephant__TO__Soldier__Logic__::Man_MoveRightTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Man_X + 30 && Mouse_X <= mPUBLIC_Man_X + 90
		&& Mouse_Y >= mPUBLIC_Man_Y + 30 && Mouse_Y <= mPUBLIC_Man_Y + 90)
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

