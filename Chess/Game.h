#pragma once
#include <iostream>
#include <Windows.h>
#include "Bitbmp.h"
#include "Map.h"
#include "Vector.h"
#include "Matrix3.h"
#include "Piece_Housekeeper.h"


struct KeyMessage//������Ϣ
{
	int Which;//��һ����
	int State;//���»���̧��
};
struct MouseMessage//�����Ϣ
{
	int Which;//�����һ����
	int State;//���»���̧��
	int x;//�������
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
	unsigned int mFPSRate = 0;//��Ϸ֡��

	Piece_Housekeeper *mPiece_Housekeeper;//�ҵ�������ܼ�
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

		Map::InitMap(hdc);//��ͼ��ʼ��

		mPiece_Housekeeper->InitPiece();//��ʼ������
	}
	void RenderGame(HDC hdc, HWND hWnd, HINSTANCE hInst)
	{
		Map::RenderMap();//��Ⱦ��ͼ

		mPiece_Housekeeper->LoadPiece();//��Ⱦ����
	}
	void GameLogic_Updata(HDC hdc, HWND hWnd, HINSTANCE hInst)
	{
		mPiece_Housekeeper->PieceLogicUpdata(mMouseMsge.Which,mMouseMsge.State, mMouseMsge.x, mMouseMsge.y);//�����߼�����
	}
	void RunGame(HDC hdc, HWND hWnd, HINSTANCE hInst)
	{
		static DWORD lasttime = 0;//��̬�ľֲ�����
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

		//������ֱ�ӻ��Ƶ�hdc�ϵ�

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