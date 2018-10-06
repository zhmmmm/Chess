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
	WE_GOLEFTPIECEMAN->RenderPiece();
	WE_GORIGHTPIECEMAN->RenderPiece();
	WE_GOLEFTELEPHANT->RenderPiece();
	WE_GORIGHTELEPHANT->RenderPiece();
	WE_GOLEFTHORSE->RenderPiece();
	WE_GORIGHTHORSE->RenderPiece();
	WE_GOLEFTCHARIOT->RenderPiece();
	WE_GORIGHTCHARIOT->RenderPiece();
	WE_GOLEFTCANNON->RenderPiece();
	WE_GORIGHTCANNON->RenderPiece();
	WE_GO_0_SOLDIER->RenderPiece();
	WE_GO_1_SOLDIER->RenderPiece();
	WE_GO_2_SOLDIER->RenderPiece();
	WE_GO_3_SOLDIER->RenderPiece();
	WE_GO_4_SOLDIER->RenderPiece();
	//===========================
	ENEMY__GOPIECECOMMAND->RenderPiece();
	ENEMY_GOLEFTMAN->RenderPiece();
	ENEMY_GORIGHTMAN->RenderPiece();
	ENEMY_GOLEFTELEPHANT->RenderPiece();
	ENEMY_GORIGHTELEPHANT->RenderPiece();
	ENEMY_GOLEFTHORSE->RenderPiece();
	ENEMY_GORIGHTHORSE->RenderPiece();
	ENEMY_GOLEFTCHARIOT->RenderPiece();
	ENEMY_GORIGHTCHARIOT->RenderPiece();
	ENEMY_GOLEFTCANNON->RenderPiece();
	ENEMY_GORIGHTCANNON->RenderPiece();
	ENEMY_GO_0_SOLDIER->RenderPiece();
	ENEMY_GO_1_SOLDIER->RenderPiece();
	ENEMY_GO_2_SOLDIER->RenderPiece();
	ENEMY_GO_3_SOLDIER->RenderPiece();
	ENEMY_GO_4_SOLDIER->RenderPiece();
}
void Piece_Housekeeper::PieceLogicUpdata(int Which, int State, int Mouse_x, int Mouse_y)
{
	WE_GOPIECECOMMAND->PieceLogicUpdata(Which,State, Mouse_x, Mouse_y);
	WE_GOLEFTPIECEMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GORIGHTPIECEMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GOLEFTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GORIGHTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GOLEFTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GORIGHTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GOLEFTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GORIGHTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GOLEFTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GORIGHTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GO_0_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GO_1_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GO_2_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GO_3_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	WE_GO_4_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	//================================================
	ENEMY__GOPIECECOMMAND->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GOLEFTMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GORIGHTMAN->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GOLEFTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GORIGHTELEPHANT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GOLEFTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GORIGHTHORSE->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GOLEFTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GORIGHTCHARIOT->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GOLEFTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GORIGHTCANNON->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GO_0_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GO_1_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GO_2_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GO_3_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
	ENEMY_GO_4_SOLDIER->PieceLogicUpdata(Which, State, Mouse_x, Mouse_y);
}