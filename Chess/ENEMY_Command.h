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

////继承了棋子和棋子逻辑
class ENEMY_Command :public Piece, public Piece_Logic, public ENEMY_Command_Logic //敌方主帅
{
public:
	static RedCur mReturnRedCurStandardCoor;//車和炮用的红色光标的标准坐标得到移动次数
private:
	int mCommand_Bmpid = 0;
	int mRedCursor_Bmpid = 0;
	int mENEMY_CommandState = 0;
	int mENEMY_Command_X = 0;
	int mENEMY_Command_Y = 0;


	RedCur mRedCur;//红色方当前有初始光标坐标
	RedCurCoor mRedStandardCoor[10][9];//红色方光标的标准坐标

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
	void RedCursorStandardCoor(int Which, int State, int Mouse_X, int Mouse_Y);//得到红色光标的标准位置
	RedCur __mReturnRedCurStandardCoor__();//返回得到红色光标的标准位置
};