#include "_____Elephant__TO__Soldier__Logic__.h"

//��
BOOL _____Elephant__TO__Soldier__Logic__::Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Elephant_X - 150 && Mouse_X <= mPUBLIC_Elephant_X - 90
		&& Mouse_Y >= mPUBLIC_Elephant_Y - 150 && Mouse_Y <= mPUBLIC_Elephant_Y - 90)
	{
		if (Mouse_Y < 270)
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
		if (Mouse_Y < 270)//���Խ�����⣬����ṹ�ж���������
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

