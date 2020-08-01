#include "EngineE.h"

#include <cassert>

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
MoveE OnPieceClicked( const u32 pl, const u32 pi )
{
    /// DebugE::PrintPieceArray();
    // init data-------------------------------------
    assert( pl < G2::MAX_PLAYERS && pi < G2::MAX_PIECES );
    const int Roll = 1;
    MoveE     Mv;
    const u32 i    = PieceE::GetPPnum( pl, pi );
    const u32 From = Pp[i].Sq();
    u32       To   = 0;
    // TODO :validate move

    // cout<<"\nthis : "<<Pp[i].Sq()<<"\n";
    // Start Sq-----------------------------
    if ( Pp[i].Sq() == G2::START_POSI ) { To = G2::StartSq[pl]; }
    // else
    else if ( From < Pp[i].InSq() )
    {
        To = ( From + Roll ) % G2::OUTER_SZ;
    }
    else
    {
        To = ( From + Roll );
    }

    // Switch into safe zone---------------------
    if ( From < 52 )
    {
        int tTo = To;

        for ( int z = From, y = 0; z != tTo; z = ( z + 1 ) % G2::OUTER_SZ )
        {
            if ( Pp[i].SwiSq() == z )
            {
                // calculate the moves left
                int movesLeft = Roll - y - 1;
                To            = Pp[i].InSq() + movesLeft;
            }
            y++;
        }
    }

    // END----------------------------------
    if ( To > Pp[i].EndSq() ) { To = G2::END_POSI; }

    // capture------------------------------------------
    if ( !Sq[To].IsSafe() )
    {
        for ( int q = 0; q < G2::MAX_PLAYERS; q++ )
        {
            if ( Sq[To].Pl( q ) != 0 && q != pl )
            {
                Mv.IsCap( 1 );
                Mv.CPl( q );
                Mv.PBits( Sq[To].Pl( q ) );

                for ( int k = 0; k < G2::MAX_PIECES; k++ )
                {
                    if ( Sq[To].PP( q, k ) != 0 )
                    {
                        u32 j = PieceE::GetPPnum( q, k );
                        Pp[j].Sq( G2::START_POSI );
                        Sq[To].PopPP( q, k );
                        Sq[G2::START_POSI].PushPP( q, k );
                    }
                }
            }
        }
    }

    // no cap case
    // adjust player
    // move base-------------------------------------
    Pp[i].Sq( To );
    Sq[From].PopPP( i );
    Sq[To].PushPP( i );
    // update move -------------------------------
    Mv.From( From );
    Mv.To( To );
    Mv.Pl( pl );
    Mv.Pi( pi );

    //  DebugE::DisplaySquares();
    // DebugE::DisplayPMove( Mv );

    // no cap as

    // Mv.CheckMove();
    // TODO: push move to stack

    return Mv;
}

void MoveTo() {}
