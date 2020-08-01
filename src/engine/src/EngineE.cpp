#include "EngineE.h"

#include "CoreE.h"
#include "DebugE.h"
#include "GData.h"
#include "iostream"
#include "ran.h"
using std::cout;

int main3()
{
    InitBoardE();
    cout << "fuck\n";
    Sq[2].PushPP( 1, 1 );
    Sq[2].PushPP( 1, 0 );
    Sq[2].PushPP( 1, 3 );
    DebugE::DisplaySquares();
    Sq[2].Pl( 1 );
    MoveE test;
    test.PBits( Sq[2].Pl( 1 ) );
    cout << "\n";
    test.DisplayBits( 7 );

    return 0;
}

int man()
{
    InitBoardE();
    // DebugE::zDebugMoveFunctions();

    // ranPrint();
    return 0;
}
int   turn = 0;
MoveE OnPieceClicked( u32 pl, u32 pi )
{
    //turn = ( turn + 1 ) % 3;

    // TODO :validate move
    int   Roll = 1;
    MoveE Mv;
    if ( turn != pl ) { return Mv; }

    u32 i = PieceE::GetPPnum( pl, pi );

    u32 From = Pp[i].Sq();
    //  cout<<"\n"<<Pp[12].Sq()<<"\n";
    u32 To = ( From + Roll ) % 72;
    Mv.IsCap( 0 );

    for ( int q = 0; q < G2::MAX_PLAYERS; q++ ) {
        if ( Sq[To].Pl( q ) != 0 && q != pl ) {
            Mv.IsCap( 1 );
            Mv.CPl( q );
            Mv.PBits( Sq[To].Pl( q ) );

            for ( int k = 0; k < G2::MAX_PIECES; k++ ) {
                if ( Sq[To].PP( q, k ) != 0 ) {
                    u32 j = PieceE::GetPPnum( q, k );
                    Pp[j].Sq( G2::START_POSI );
                    Sq[To].PopPP( q, k );
                    Sq[G2::START_POSI].PushPP( q, k );
                }
            }
        }
    }

    // no cap case
    // adjust player
    Pp[i].Sq( To );

    // adjust square
    Sq[From].PopPP( i );
    Sq[To].PushPP( i );

    Mv.From( From );
    Mv.To( To );
    Mv.PP( i );

    //   DebugE::DisplaySquares();
    //   DebugE::DisplayPMove( Mv );

    // no cap as

    return Mv;
}
