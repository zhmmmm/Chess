#pragma once
#include <iostream>
#include <Windows.h>

//�������������ӵ��߼������۵з������ҷ������Լ̳������
//���󵽱����ƶ���Χ�߼�����������ߵĻ����ұߵģ����ǵз�����߻����ұ߶��̳����
class _____Elephant__TO__Soldier__Logic__
{

public:
	//����ǰ
	BOOL Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//��ǰ
	BOOL Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//���
	BOOL Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//�Һ�
	BOOL Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);

};