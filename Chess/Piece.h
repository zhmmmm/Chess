#pragma once

class Piece//����
{
	static int mEnemy;//�з�����
	static int mWe;//�ҷ�����

public:
	Piece() {}
	~Piece() {}
	virtual void InitPiece();                    //��������
	virtual void RenderPiece();            //��Ⱦ����
	virtual void PieceLogicUpdata();  //�����߼�����
	int Return_mEnemy();                     //���صз�
	int Reutrn_mWe();                           //�����ҷ�
	void Change_mEnemy(int num);  //���ĵз�
	void Change_mWe(int num);        //�����ҷ�
};

