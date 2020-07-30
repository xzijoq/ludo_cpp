#pragma once


#include "DeclarationsE.h"

class DebugE
{
   public:
    static void PrintPieceArray();
    static void zDebugPieceFunctions();
    static void zDebugMoveFunctions();
    static void DisplayPMove( MoveE mv );
    static void DisplayBits( u32 num, int sp = 8,
                             bool displayDecimalVal = false );

    static inline bool IsInRange( int value, int min, int max )
    {
        return ( value >= min && value < max );
    }
};