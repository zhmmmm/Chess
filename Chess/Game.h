#pragma once
#include <iostream>
#include <Windows.h>
#include "Bitbmp.h"
#include "Map.h"
#include "Vector.h"
#include "Matrix3.h"
#include "Piece_Housekeeper.h"


struct KeyMessage//按键消息
{
	int Which;//哪一个键
	int State;//按下还是抬起
};
struct MouseMessage//鼠标消息
{
	int Which;//鼠标哪一个键
	int State;//按下还是抬起
	int x;//鼠标坐标
	int y;
};
struct COOR
{
	int x;
	int y;
};

class Game :public Map
{
	KeyMessage mKey;
	MouseMessage mMouseMsge;
	unsigned int mFPSRate = 0;//游戏帧率

	Piece_Housekeeper *mPiece_Housekeeper;//我的棋子类管家
public:
	Game() :mFPSRate(45)
	{
		srand(GetTickCount());
		mKey.State = 0;
		mKey.Which = 0;

		mMouseMsge.State = 0;
		mMouseMsge.Which = 0;
		mMouseMsge.x = 0;
		mMouseMsge.y = 0;
		InitPiece();
	}
	void InitPiece()
	{
		mPiece_Housekeeper = new Piece_Housekeeper();
	}
	void InitGame(HDC hdc, HWND hWnd, HINSTANCE hInst)
	{
		GoBitmap->Init(hWnd, hInst);

		Map::InitMap(hdc);//地图初始化

		mPiece_Housekeeper->InitPiece();//初始化棋子
	}
	void RenderGame(HDC hdc, HWND hWnd, HINSTANCE hInst)
	{
		Map::RenderMap();//渲染地图

		mPiece_Housekeeper->LoadPiece();//渲染棋子
	}
	void GameLogic_Updata(HDC hdc, HWND hWnd, HINSTANCE hInst)
	{
		mPiece_Housekeeper->PieceLogicUpdata(mMouseMsge.Which,mMouseMsge.State, mMouseMsge.x, mMouseMsge.y);//棋子逻辑更新
	}
	void RunGame(HDC hdc, HWND hWnd, HINSTANCE hInst)
	{
		static DWORD lasttime = 0;//静态的局部变量
		DWORD curtime = GetTickCount();
		if (curtime - lasttime >= mFPSRate)
		{
			GoBitmap->Begin();

			RenderGame(hdc, hWnd, hInst);
			GameLogic_Updata(hdc, hWnd, hInst);
			GameMouseMessage(mMouseMsge);

			GoBitmap->End();
			lasttime = curtime;
		}

		//这里是直接绘制到hdc上的

	}
	void GameOver(){}
	void GameKeyMessage(KeyMessage Key)
	{
		this->mKey.State = Key.State;
		this->mKey.Which = Key.Which;
	}
	void GameMouseMessage(MouseMessage MouseMsge)
	{
		this->mMouseMsge.x = MouseMsge.x;
		this->mMouseMsge.y = MouseMsge.y;
		this->mMouseMsge.State = MouseMsge.State;
		this->mMouseMsge.Which = MouseMsge.Which;
	}

	~Game()
	{
		delete mPiece_Housekeeper;
		mPiece_Housekeeper = NULL;
	}
};