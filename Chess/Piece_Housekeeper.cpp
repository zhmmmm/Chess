#include "Piece_Housekeeper.h"

void Piece_Housekeeper::InitPiece()
{
	WE_GOPIECECOMMAND->InitPiece();
	WE_GOLEFTPIECEMAN->InitPiece();
	WE_GORIGHTPIECEMAN->InitPiece();
	WE_GOLEFTELEPHANT->InitPiece();
	WE_GORIGHTELEPHANT->InitPiece();
	WE_GOLEFTHORSE->InitPiece();
	WE_GORIGHTHORSE->InitPiece();
	WE_GOLEFTCHARIOT->InitPiece();
	WE_GORIGHTCHARIOT->InitPiece();
	WE_GOLEFTCANNON->InitPiece();
	WE_GORIGHTCANNON->InitPiece();
	WE_GO_0_SOLDIER->InitPiece();
	WE_GO_1_SOLDIER->InitPiece();
	WE_GO_2_SOLDIER->InitPiece();
	WE_GO_3_SOLDIER->InitPiece();
	WE_GO_4_SOLDIER->InitPiece();
	//=================================
	ENEMY__GOPIECECOMMAND->InitPiece();
	ENEMY_GOLEFTMAN->InitPiece();
	ENEMY_GORIGHTMAN->InitPiece();
	ENEMY_GOLEFTELEPHANT->InitPiece();
	ENEMY_GORIGHTELEPHANT->InitPiece();
	ENEMY_GOLEFTHORSE->InitPiece();
	ENEMY_GORIGHTHORSE->InitPiece();
	ENEMY_GOLEFTCHARIOT->InitPiece();
	ENEMY_GORIGHTCHARIOT->InitPiece();
	ENEMY_GOLEFTCANNON->InitPiece();
	ENEMY_GORIGHTCANNON->InitPiece();
	ENEMY_GO_0_SOLDIER->InitPiece();
	ENEMY_GO_1_SOLDIER->InitPiece();
	ENEMY_GO_2_SOLDIER->InitPiece();
	ENEMY_GO_3_SOLDIER->InitPiece();
	ENEMY_GO_4_SOLDIER->InitPiece();

}
void Piece_Housekeeper::LoadPiece()
{
	WE_GOPIECECOMMAND->RenderPiece();

	if (true)
	{
		//士
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 6)
				{
					WE_GOLEFTPIECEMAN->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 4)
				{
					WE_GORIGHTPIECEMAN->RenderPiece();
				}
			}
		}
		//象
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 7)
				{
					WE_GOLEFTELEPHANT->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 3)
				{
					WE_GORIGHTELEPHANT->RenderPiece();
				}
			}
		}
		//马
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 8)
				{
					WE_GOLEFTHORSE->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 2)
				{
					WE_GORIGHTHORSE->RenderPiece();
				}
			}
		}
		//車
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 9)
				{
					WE_GOLEFTCHARIOT->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 1)
				{
					WE_GORIGHTCHARIOT->RenderPiece();
				}
			}
		}
		//炮
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 12)
				{
					WE_GOLEFTCANNON->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 11)
				{
					WE_GORIGHTCANNON->RenderPiece();
				}
			}
		}
		//兵
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 17)
				{
					WE_GO_0_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 16)
				{
					WE_GO_1_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 15)
				{
					WE_GO_2_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 14)
				{
					WE_GO_3_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 13)
				{
					WE_GO_4_SOLDIER->RenderPiece();
				}
			}
		}
	}
	//===========================
	ENEMY__GOPIECECOMMAND->RenderPiece();

	if (true)
	{
		//士
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 60)
				{
					ENEMY_GOLEFTMAN->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 40)
				{
					ENEMY_GORIGHTMAN->RenderPiece();
				}
			}
		}
		//象
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 70)
				{
					ENEMY_GOLEFTELEPHANT->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 30)
				{
					ENEMY_GORIGHTELEPHANT->RenderPiece();
				}
			}
		}
		//马
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 80)
				{
					ENEMY_GOLEFTHORSE->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 20)
				{
					ENEMY_GORIGHTHORSE->RenderPiece();
				}
			}
		}
		//車
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 90)
				{
					ENEMY_GOLEFTCHARIOT->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 10)
				{
					ENEMY_GORIGHTCHARIOT->RenderPiece();
				}
			}
		}
		//炮
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 120)
				{
					ENEMY_GOLEFTCANNON->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 110)
				{
					ENEMY_GORIGHTCANNON->RenderPiece();
				}
			}
		}
		//兵
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 130)
				{
					ENEMY_GO_0_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 140)
				{
					ENEMY_GO_1_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 150)
				{
					ENEMY_GO_2_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 160)
				{
					ENEMY_GO_3_SOLDIER->RenderPiece();
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 170)
				{
					ENEMY_GO_4_SOLDIER->RenderPiece();
				}
			}
		}
	}
}
void Piece_Housekeeper::PieceLogicUpdata(int Which, int State, int Mouse_x, int Mouse_y)
{
	WE_GOPIECECOMMAND->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);

	if (true)
	{
		//士
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 6)
				{
					WE_GOLEFTPIECEMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 4)
				{
					WE_GORIGHTPIECEMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//象
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 7)
				{
					WE_GOLEFTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 3)
				{
					WE_GORIGHTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//马
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 8)
				{
					WE_GOLEFTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 2)
				{
					WE_GORIGHTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//車
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 9)
				{
					WE_GOLEFTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 1)
				{
					WE_GORIGHTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//炮
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 12)
				{
					WE_GOLEFTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 11)
				{
					WE_GORIGHTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//兵
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 17)
				{
					WE_GO_0_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 16)
				{
					WE_GO_1_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 15)
				{
					WE_GO_2_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 14)
				{
					WE_GO_3_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 13)
				{
					WE_GO_4_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
	}
	//================================================
	ENEMY__GOPIECECOMMAND->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);

	if (true)
	{
		//士的逻辑更新
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 60)
				{
					ENEMY_GOLEFTMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 40)
				{
					ENEMY_GORIGHTMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//象的逻辑更新
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 70)
				{
					ENEMY_GOLEFTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 30)
				{
					ENEMY_GORIGHTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//马的逻辑更新
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 80)
				{
					ENEMY_GOLEFTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 20)
				{
					ENEMY_GORIGHTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//車的逻辑更新
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 90)
				{
					ENEMY_GOLEFTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 10)
				{
					ENEMY_GORIGHTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//炮的逻辑更新
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 120)
				{
					ENEMY_GOLEFTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 110)
				{
					ENEMY_GORIGHTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		//兵
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 130)
				{
					ENEMY_GO_0_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 140)
				{
					ENEMY_GO_1_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 150)
				{
					ENEMY_GO_2_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 160)
				{
					ENEMY_GO_3_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (Piece_Logic::mMouseDownRange[i][j] == 170)
				{
					ENEMY_GO_4_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
				}
			}
		}
	}
}