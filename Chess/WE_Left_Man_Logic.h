#pragma once
#include<iostream>

//我方左边士的逻辑
class WE_Left_Man_Logic
{

public:
	//左士向前
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
	//左士向右前
	BOOL Man_MoveBackTarget(int mWE_Man_X, int mWE_Man_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Man_X + 30 && Mouse_X <= mWE_Man_X + 90
			&& Mouse_Y >= mWE_Man_Y - 90 && Mouse_Y <= mWE_Man_Y - 30)
		{
			if (Mouse_X > 380)//士的越界问题，这个结构判断是完美的
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
	//左士向左后
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
	//左士向右后
	BOOL Man_MoveRightTarget(int mWE_Man_X, int mWE_Man_Y, int Mouse_X, int Mouse_Y)
	{
		if (Mouse_X >= mWE_Man_X + 30 && Mouse_X <= mWE_Man_X + 90
			&& Mouse_Y >= mWE_Man_Y + 30 && Mouse_Y <= mWE_Man_Y + 90)
		{
			if (Mouse_X > 380)//士的越界问题，这个结构判断是完美的
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