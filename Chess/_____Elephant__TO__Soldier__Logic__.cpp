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

//�з���
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

//��İ˸�����
//������ǰ
BOOL _____Elephant__TO__Soldier__Logic__::_0__Horse_MoveForwardTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X - 90 && Mouse_X <= mPUBLIC_Horse_X - 30
		&& Mouse_Y >= mPUBLIC_Horse_Y - 150 && Mouse_Y <= mPUBLIC_Horse_Y - 90)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y < 20)
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
BOOL _____Elephant__TO__Soldier__Logic__::_1__Horse_MoveBackTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X + 30 && Mouse_X <= mPUBLIC_Horse_X + 90
		&& Mouse_Y >= mPUBLIC_Horse_Y - 150 && Mouse_Y <= mPUBLIC_Horse_Y - 90)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y < 20)
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

BOOL _____Elephant__TO__Soldier__Logic__::_2__Horse_MoveLeftTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X - 150 && Mouse_X <= mPUBLIC_Horse_X - 90
		&& Mouse_Y >= mPUBLIC_Horse_Y - 90 && Mouse_Y <= mPUBLIC_Horse_Y - 30)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y < 20)
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
BOOL _____Elephant__TO__Soldier__Logic__::_3__Horse_MoveRightTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X + 90 && Mouse_X <= mPUBLIC_Horse_X + 150
		&& Mouse_Y >= mPUBLIC_Horse_Y - 90 && Mouse_Y <= mPUBLIC_Horse_Y - 30)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y < 20)
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
//�����
BOOL _____Elephant__TO__Soldier__Logic__::_4__Horse_MoveForwardTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X - 150 && Mouse_X <= mPUBLIC_Horse_X - 90
		&& Mouse_Y >= mPUBLIC_Horse_Y + 30 && Mouse_Y <= mPUBLIC_Horse_Y + 90)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y > 620)
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
BOOL _____Elephant__TO__Soldier__Logic__::_5__Horse_MoveBackTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X + 90 && Mouse_X <= mPUBLIC_Horse_X + 150
		&& Mouse_Y >= mPUBLIC_Horse_Y + 30 && Mouse_Y <= mPUBLIC_Horse_Y + 90)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y > 620)
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

BOOL _____Elephant__TO__Soldier__Logic__::_6__Horse_MoveLeftTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X - 90 && Mouse_X <= mPUBLIC_Horse_X - 30
		&& Mouse_Y >= mPUBLIC_Horse_Y + 90 && Mouse_Y <= mPUBLIC_Horse_Y + 150)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y > 620)
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
BOOL _____Elephant__TO__Soldier__Logic__::_7__Horse_MoveRightTarget(int mPUBLIC_Horse_X, int mPUBLIC_Horse_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Horse_X + 30 && Mouse_X <= mPUBLIC_Horse_X + 90
		&& Mouse_Y >= mPUBLIC_Horse_Y + 30 && Mouse_Y <= mPUBLIC_Horse_Y + 150)
	{
		if (Mouse_X < 20 || Mouse_X > 560 || Mouse_Y > 620)
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


//܇
//ǰ
BOOL _____Elephant__TO__Soldier__Logic__::Chariot_MoveForwardTarget(int mPUBLIC_Chariot_X, int mPUBLIC_Chariot_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Chariot_X - 30 && Mouse_X <= mPUBLIC_Chariot_X + 30
		&& Mouse_Y > 20 && Mouse_Y < mPUBLIC_Chariot_Y - 30)
	{
		return TRUE;
	}
	return FALSE;
}
BOOL _____Elephant__TO__Soldier__Logic__::Chariot_MoveBackTarget(int mPUBLIC_Chariot_X, int mPUBLIC_Chariot_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Chariot_X - 30 && Mouse_X <= mPUBLIC_Chariot_X + 30
		&& Mouse_Y > mPUBLIC_Chariot_Y + 30 && Mouse_Y < 620)
	{
		return TRUE;
	}
	return FALSE;
}
BOOL _____Elephant__TO__Soldier__Logic__::Chariot_MoveLeftTarget(int mPUBLIC_Chariot_X, int mPUBLIC_Chariot_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X > 20 && Mouse_X <= mPUBLIC_Chariot_X - 30
		&& Mouse_Y >= mPUBLIC_Chariot_Y - 30 && Mouse_Y <= mPUBLIC_Chariot_Y + 30)
	{
		return TRUE;
	}
	return FALSE;
}
BOOL _____Elephant__TO__Soldier__Logic__::Chariot_MoveRightTarget(int mPUBLIC_Chariot_X, int mPUBLIC_Chariot_Y, int Mouse_X, int Mouse_Y)
{
	if (Mouse_X >= mPUBLIC_Chariot_X + 30 && Mouse_X < 560
		&& Mouse_Y >= mPUBLIC_Chariot_X - 30 && Mouse_Y <= mPUBLIC_Chariot_Y + 30)
	{
		return TRUE;
	}
	return FALSE;
}