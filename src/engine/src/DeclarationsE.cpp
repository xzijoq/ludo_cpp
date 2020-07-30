#include "DeclarationsE.h"


std::array<SquareE, G2::LudoBoard.size()>            Sq;
std::array<PieceE, G2::MAX_PLAYERS * G2::MAX_PIECES> Pp;//PlayerPiece




void InitAllPlayers()
{
    for ( int i = 0; i < G2::MAX_PLAYERS; i++ ) {
        for ( int j = 0; j < G2::MAX_PIECES; j++ ) {
            Pp[i * G2::MAX_PIECES + j].InitPieceE(
                G2::START_POSI, G2::SwitchSq[i], G2::EndSq[i],
                G2::SwitchIntoSq[i], i, j );
        }
    }
}
vector <MoveE>MoveStack;
void PushMove(MoveE mv){
  MoveStack.push_back(mv);
  
}

