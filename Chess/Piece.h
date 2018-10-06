#pragma once

class Piece//棋子
{
	static int mEnemy;//敌方棋子
	static int mWe;//我方棋子

public:
	Piece() {}
	~Piece() {}
	virtual void InitPiece();                    //加载棋子
	virtual void RenderPiece();            //渲染棋子
	virtual void PieceLogicUpdata();  //棋子逻辑更新
	int Return_mEnemy();                     //返回敌方
	int Reutrn_mWe();                           //返回我方
	void Change_mEnemy(int num);  //更改敌方
	void Change_mWe(int num);        //更改我方
};

