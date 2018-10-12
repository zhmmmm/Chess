#pragma once
#include "WE_Command.h"
#include "WE_Left_Man.h"
#include "WE_Right_Man.h"
#include "WE_Left_Elephant.h"
#include "WE_Right_Elephant.h"
#include "WE_Left_Horse.h"
#include "WE_Right_Horse.h"
#include "WE_Left_Chariot.h"
#include "WE_Right_Chariot.h"
#include "WE_Left_Cannon.h"
#include "WE_Right_Cannon.h"
#include "WE_0_Soldier.h"
#include "WE_1_Soldier.h"
#include "WE_2_Soldier.h"
#include "WE_3_Soldier.h"
#include "WE_4_Soldier.h"
//=================================
#include "ENEMY_Command.h"
#include "ENEMY_Left_Man.h"
#include "ENEMY_Right_Man.h"
#include "ENEMY_Left_Elephant.h"
#include "ENEMY_Right_Elephant.h"
#include "ENEMY_Left_Horse.h"
#include "ENEMY_Right_Horse.h"
#include "ENEMY_Left_Chariot.h"
#include "ENEMY_Right_Chariot.h"
#include "ENEMY_Left_Cannon.h"
#include "ENEMY_Right_Cannon.h"
#include "ENEMY_0_Soldier.h"
#include "ENEMY_1_Soldier.h"
#include "ENEMY_2_Soldier.h"
#include "ENEMY_3_Soldier.h"
#include "ENEMY_4_Soldier.h"

#include "Piece_Logic.h"



#define WE_GOPIECECOMMAND Piece_Housekeeper::mWE_Command//我方主将
#define WE_GOLEFTPIECEMAN Piece_Housekeeper::mWE_Left_Man//我方左边的士
#define WE_GORIGHTPIECEMAN Piece_Housekeeper::mWE_Right_Man//我方右边的士
#define WE_GOLEFTELEPHANT Piece_Housekeeper::mWE_Left_Elephant //我方左边的象
#define WE_GORIGHTELEPHANT Piece_Housekeeper::mWE_Right_Elephant //我方右边的象
#define WE_GOLEFTHORSE Piece_Housekeeper::mWE_Left_Horse//左边的马
#define WE_GORIGHTHORSE Piece_Housekeeper::mWE_Right_Horse//右边的马
#define WE_GOLEFTCHARIOT Piece_Housekeeper::mWE_Left_Chariot //左边的車
#define WE_GORIGHTCHARIOT Piece_Housekeeper::mWE_Right_Chariot //右边的車
#define WE_GOLEFTCANNON Piece_Housekeeper::mWE_Left_Cannon//左边的炮
#define WE_GORIGHTCANNON Piece_Housekeeper::mWE_Right_Cannon//右边的炮
#define WE_GO_0_SOLDIER Piece_Housekeeper::mWE_0_Soldier//小兵0
#define WE_GO_1_SOLDIER Piece_Housekeeper::mWE_1_Soldier//小兵1
#define WE_GO_2_SOLDIER Piece_Housekeeper::mWE_2_Soldier//小兵2
#define WE_GO_3_SOLDIER Piece_Housekeeper::mWE_3_Soldier//小兵3
#define WE_GO_4_SOLDIER Piece_Housekeeper::mWE_4_Soldier//小兵4

//========================================================
#define ENEMY__GOPIECECOMMAND Piece_Housekeeper::mENEMY_Command//敌方主帅
#define ENEMY_GOLEFTMAN Piece_Housekeeper::mENEMY_Left_Man //敌方左边士
#define ENEMY_GORIGHTMAN Piece_Housekeeper::mENEMY_Right_Man //敌方左边士
#define ENEMY_GOLEFTELEPHANT Piece_Housekeeper::mENEMY_Left_Elephant //敌方左边象
#define ENEMY_GORIGHTELEPHANT Piece_Housekeeper::mENEMY_Right_Elephant//敌方右边象
#define ENEMY_GOLEFTHORSE Piece_Housekeeper::mENEMY_Left_Horse //敌方左边的马
#define ENEMY_GORIGHTHORSE Piece_Housekeeper::mENEMY_Right_Horse//敌方右边的马
#define ENEMY_GOLEFTCHARIOT Piece_Housekeeper::mENEMY_Left_Chariot //敌方左边車
#define ENEMY_GORIGHTCHARIOT Piece_Housekeeper::mENEMY_Right_Chariot//敌方右边車
#define ENEMY_GOLEFTCANNON Piece_Housekeeper::mENEMY_Left_Cannon //敌方左边炮
#define ENEMY_GORIGHTCANNON Piece_Housekeeper::mENEMY_Right_Cannon//敌方右边炮
#define ENEMY_GO_0_SOLDIER Piece_Housekeeper::mENEMY_0_Soldier //小兵0
#define ENEMY_GO_1_SOLDIER Piece_Housekeeper::mENEMY_1_Soldier //小兵1
#define ENEMY_GO_2_SOLDIER Piece_Housekeeper::mENEMY_2_Soldier //小兵2
#define ENEMY_GO_3_SOLDIER Piece_Housekeeper::mENEMY_3_Soldier //小兵3
#define ENEMY_GO_4_SOLDIER Piece_Housekeeper::mENEMY_4_Soldier //小兵4



//所有棋子的管家
class Piece_Housekeeper:public Piece_Logic
{
	WE_Command *mWE_Command;
	WE_Left_Man *mWE_Left_Man;
	WE_Right_Man *mWE_Right_Man;
	WE_Left_Elephant *mWE_Left_Elephant;
	WE_Right_Elephant *mWE_Right_Elephant;
	WE_Left_Horse *mWE_Left_Horse;
	WE_Right_Horse *mWE_Right_Horse;
	WE_Left_Chariot *mWE_Left_Chariot;
	WE_Right_Chariot *mWE_Right_Chariot;
	WE_Left_Cannon *mWE_Left_Cannon;
	WE_Right_Cannon *mWE_Right_Cannon;
	WE_0_Soldier *mWE_0_Soldier;
	WE_1_Soldier *mWE_1_Soldier;
	WE_2_Soldier *mWE_2_Soldier;
	WE_3_Soldier *mWE_3_Soldier;
	WE_4_Soldier *mWE_4_Soldier;
	//==================================
	ENEMY_Command *mENEMY_Command;
	ENEMY_Left_Man *mENEMY_Left_Man;
	ENEMY_Right_Man *mENEMY_Right_Man;
	ENEMY_Left_Elephant *mENEMY_Left_Elephant;
	ENEMY_Right_Elephant *mENEMY_Right_Elephant;
	ENEMY_Left_Horse *mENEMY_Left_Horse;
	ENEMY_Right_Horse *mENEMY_Right_Horse;
	ENEMY_Left_Chariot *mENEMY_Left_Chariot;
	ENEMY_Right_Chariot *mENEMY_Right_Chariot;
	ENEMY_Left_Cannon *mENEMY_Left_Cannon;
	ENEMY_Right_Cannon *mENEMY_Right_Cannon;
	ENEMY_0_Soldier *mENEMY_0_Soldier;
	ENEMY_1_Soldier *mENEMY_1_Soldier;
	ENEMY_2_Soldier *mENEMY_2_Soldier;
	ENEMY_3_Soldier *mENEMY_3_Soldier;
	ENEMY_4_Soldier *mENEMY_4_Soldier;


public:
	Piece_Housekeeper()
	{
		mENEMY_Command = new ENEMY_Command();
		mENEMY_Left_Man = new ENEMY_Left_Man();
		mENEMY_Right_Man = new ENEMY_Right_Man();
		mENEMY_Left_Elephant = new ENEMY_Left_Elephant();
		mENEMY_Right_Elephant = new ENEMY_Right_Elephant();
		mENEMY_Left_Horse = new ENEMY_Left_Horse();
		mENEMY_Right_Horse = new ENEMY_Right_Horse();
		mENEMY_Left_Chariot = new ENEMY_Left_Chariot();
		mENEMY_Right_Chariot = new ENEMY_Right_Chariot();
		mENEMY_Left_Cannon = new ENEMY_Left_Cannon();
		mENEMY_Right_Cannon = new ENEMY_Right_Cannon();
		mENEMY_0_Soldier = new ENEMY_0_Soldier();
		mENEMY_1_Soldier = new ENEMY_1_Soldier();
		mENEMY_2_Soldier = new ENEMY_2_Soldier();
		mENEMY_3_Soldier = new ENEMY_3_Soldier();
		mENEMY_4_Soldier = new ENEMY_4_Soldier();

		//====================================
		mWE_Command = new WE_Command();
		mWE_Left_Man = new WE_Left_Man();
		mWE_Right_Man = new WE_Right_Man();
		mWE_Left_Elephant = new WE_Left_Elephant();
		mWE_Right_Elephant = new WE_Right_Elephant();
		mWE_Left_Horse = new WE_Left_Horse();
		mWE_Right_Horse = new WE_Right_Horse();
		mWE_Left_Chariot = new WE_Left_Chariot();
		mWE_Right_Chariot = new WE_Right_Chariot();
		mWE_Left_Cannon = new WE_Left_Cannon();
		mWE_Right_Cannon = new WE_Right_Cannon();
		mWE_0_Soldier = new WE_0_Soldier();
		mWE_1_Soldier = new WE_1_Soldier();
		mWE_2_Soldier = new WE_2_Soldier();
		mWE_3_Soldier = new WE_3_Soldier();
		mWE_4_Soldier = new WE_4_Soldier();
	}
	~Piece_Housekeeper()
	{
		delete mENEMY_Command;
		mENEMY_Command = NULL;
		delete mENEMY_Left_Man;
		mENEMY_Left_Man = NULL;
		delete mENEMY_Right_Man;
		mENEMY_Right_Man = NULL;
		delete mENEMY_Left_Elephant;
		mENEMY_Left_Elephant = NULL;
		delete mENEMY_Right_Elephant;
		mENEMY_Right_Elephant = NULL;
		delete mENEMY_Left_Horse;
		mENEMY_Left_Horse = NULL;
		delete mENEMY_Right_Horse;
		mENEMY_Right_Horse = NULL;
		delete mENEMY_Left_Chariot;
		mENEMY_Left_Chariot = NULL;
		delete mENEMY_Right_Chariot;
		mENEMY_Right_Chariot = NULL;
		delete mENEMY_Left_Cannon;
		mENEMY_Left_Cannon = NULL;
		delete mENEMY_Right_Cannon;
		mENEMY_Right_Cannon = NULL;
		delete mENEMY_0_Soldier;
		mENEMY_0_Soldier = NULL;
		delete mENEMY_1_Soldier;
		mENEMY_1_Soldier = NULL;
		delete mENEMY_2_Soldier;
		mENEMY_2_Soldier = NULL;
		delete mENEMY_3_Soldier;
		mENEMY_3_Soldier = NULL;
		delete mENEMY_4_Soldier;
		mENEMY_4_Soldier = NULL;

		//==============================================
		delete mWE_Command;
		mWE_Command = NULL;
		delete mWE_Left_Man;
		mWE_Left_Man = NULL;
		delete mWE_Right_Man;
		mWE_Right_Man = NULL;
		delete mWE_Left_Elephant;
		mWE_Left_Elephant = NULL;
		delete mWE_Right_Elephant;
		mWE_Right_Elephant = NULL;
		delete mWE_Left_Horse;
		mWE_Left_Horse = NULL;
		delete mWE_Right_Horse;
		mWE_Right_Horse = NULL;
		delete mWE_Left_Chariot;
		mWE_Left_Chariot = NULL;
		delete mWE_Right_Chariot;
		mWE_Right_Chariot = NULL;
		delete mWE_Left_Cannon;
		mWE_Left_Cannon = NULL;
		delete mWE_Right_Cannon;
		mWE_Right_Cannon = NULL;
		delete mWE_0_Soldier;
		mWE_0_Soldier = NULL;
		delete mWE_1_Soldier;
		mWE_1_Soldier = NULL;
		delete mWE_2_Soldier;
		mWE_2_Soldier = NULL;
		delete mWE_3_Soldier;
		mWE_3_Soldier = NULL;
		delete mWE_4_Soldier;
		mWE_4_Soldier = NULL;
	}
	void InitPiece();//初始化棋子
	void LoadPiece();//加载棋子
	void PieceLogicUpdata(int Which,int State,int Mouse_x,int Mouse_y);//棋子逻辑更新
};