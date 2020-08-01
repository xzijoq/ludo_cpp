#pragma once
#include <vector>

#include "CoreE.h"

using std::array;
using std::vector;

extern array<SquareE, G2::LudoBoard.size()>            Sq;
extern array<PieceE, G2::MAX_PLAYERS * G2::MAX_PIECES> Pp;

extern vector<MoveE> MoveStack;
extern void          PushMove( MoveE mv );
extern MoveE         PopMove();
extern void          InitBoardE();

