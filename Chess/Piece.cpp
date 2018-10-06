#include "Piece.h"


int Piece::mEnemy = 0;
int Piece::mWe = 0;

void Piece::InitPiece(){}
void Piece::PieceLogicUpdata(){}
void Piece::RenderPiece(){}
int Piece::Return_mEnemy(){return mEnemy;}
int Piece::Reutrn_mWe(){return mWe;}
void Piece::Change_mEnemy(int num){mEnemy = num;}
void Piece::Change_mWe(int num){mWe = num;}
