#pragma once
#include <iostream>
#include <Windows.h>

//�������������ӵ��߼������۵з������ҷ������Լ̳������
//���󵽱����ƶ���Χ�߼�����������ߵĻ����ұߵģ����ǵз�����߻����ұ߶��̳����
//�з���ʿ��ʼ
class _____Elephant__TO__Soldier__Logic__
{

public:
	//�ҷ�����ǰ
	BOOL Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//��ǰ
	BOOL Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//���
	BOOL Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//�Һ�
	BOOL Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);

	//�з�����ǰ
	BOOL ENEMY_Elephant_MoveForwardTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//��ǰ
	BOOL ENEMY_Elephant_MoveBackTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//���
	BOOL ENEMY_Elephant_MoveLeftTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);
	//�Һ�
	BOOL ENEMY_Elephant_MoveRightTarget(int mPUBLIC_Elephant_X, int mPUBLIC_Elephant_Y, int Mouse_X, int Mouse_Y);

	//ʿ��ǰ
	BOOL Man_MoveForwardTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);
	//����ǰ
	BOOL Man_MoveBackTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);
	//�����
	BOOL Man_MoveLeftTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);
	//���Һ�
	BOOL Man_MoveRightTarget(int mPUBLIC_Man_X, int mPUBLIC_Man_Y, int Mouse_X, int Mouse_Y);



};