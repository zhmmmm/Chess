#pragma once
#include "Bitbmp.h"
#include "Matrix3.h"
#include "Vector.h"
#include "Piece.h"
#include "Piece_Logic.h"
#include "ENEMY_Command_Logic.h"

struct RedCur
{
	int x;
	int y;
};
struct RedCurCoor
{
	int x;
	int y;
};

////�̳������Ӻ������߼�
class ENEMY_Command :public Piece, public Piece_Logic, public ENEMY_Command_Logic //�з���˧
{
public:
	static RedCur mReturnRedCurStandardCoor;//܇�����õĺ�ɫ���ı�׼����õ��ƶ�����
private:
	int mCommand_Bmpid = 0;
	int mRedCursor_Bmpid = 0;
	int mENEMY_CommandState = 0;
	int mENEMY_Command_X = 0;
	int mENEMY_Command_Y = 0;


	RedCur mRedCur;//��ɫ����ǰ�г�ʼ�������
	RedCurCoor mRedStandardCoor[10][9];//��ɫ�����ı�׼����

	Matrix3 m;
	Vector2D mCoor;
public:
	ENEMY_Command();
	~ENEMY_Command();
	void InitPiece();
	void RenderPiece();
	void RenderCursor();
	void PieceLogicUpdata(int Which, int State, int x, int y);
	int __ENEMY_Command_Logic__(BOOL BoolForward, BOOL BoolBack, BOOL BoolLeft, BOOL BoolRight);
	void RedCursorStandardCoor(int Which, int State, int Mouse_X, int Mouse_Y);//�õ���ɫ���ı�׼λ��
	RedCur __mReturnRedCurStandardCoor__();//���صõ���ɫ���ı�׼λ��
};