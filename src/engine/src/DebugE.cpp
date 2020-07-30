#include "DebugE.h"

#include <bitset>
#include <iostream>
using std::cout;

void DebugE::PrintPieceArray()
{
    cout << "\n";
    for ( int i = 0; i < G2::MAX_PP; i++ ) {
        Pp[i].DisplayBits( 7 );
        cout << "\n";
    }

    for ( int i = 0; i < G2::MAX_PP; i++ ) {
        cout << "\nPlN: " << Pp[i].GetPnum() << " PieN: " << Pp[i].GetPieNum()
             << " SwiSq: " << Pp[i].GetSwiSq() << " EndSq: " << Pp[i].GetEndSq()
             << " InSq: " << Pp[i].GetInSq() << " Sq: " << Pp[i].GetSq();
    }
    cout << "\n";
}
void DebugE::zDebugPieceFunctions()
{
    PieceE test;
    cout << "\n-----------SetTestStart-------";
    test.SetSq( 0b1000011 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetInSq( 0b1000101 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetEndSq( 0b1001001 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetSwiSq( 0b1010001 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetPnum( 0b11 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetPieNum( 0b01 );
    test.DisplayBits( 7 );
    cout << "\n";

    cout << "\n----------GetTestStart -----------\n";

    DebugE::DisplayBits( test.GetSq(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetInSq(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetEndSq(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetSwiSq(), 7 );
    cout << "\n";

    DebugE::DisplayBits( test.GetPnum(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetPieNum(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetPPnum(), 7 );
    cout << "\n";
}
void DebugE::DisplayBits( u32 num, int sp, bool val )
{
    cout << "\n";
    for ( auto i = 31; i >= 0; i-- ) {
        if ( val ) {
            std::cout << ( num & 1ULL << i ) << " ";
        } else {
            ( num & 1ULL << i ) ? cout << 1 : cout << 0;
        }
        if ( ( i ) % sp == 0 ) { cout << " "; }
        if ( ( i ) % 4 == 0 && sp == 8 ) { cout << " "; }
    }
    cout << "\n";
}

void DebugE::zDebugMoveFunctions()
{
    MoveE test;

    cout << "\n-----------SetTestStart-------\n";
    test.SetmFrom( 0b1000011 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetmTo( 0b1000101 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetmPP( 0b1001 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetmIsCap( 0b1 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetmCPl( 0b10 );
    test.DisplayBits( 7 );
    cout << "\n";

    test.SetmPBits( 0b1001 );
    test.DisplayBits( 7 );
    cout << "\n";
    test.SetmCPiece( 1 );
    test.DisplayBits( 7 );
    cout << "\n";
    cout << "\n----------GetTestStart -----------\n";

    DebugE::DisplayBits( test.GetmFrom(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetmTo(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetmPP(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetmIsCap(), 7 );
    cout << "\n";

    DebugE::DisplayBits( test.GetmCPl(), 7 );
    cout << "\n";
    DebugE::DisplayBits( test.GetmPBits(), 7 );
    cout << "\n";
}

void DebugE::DisplayPMove( MoveE mv )
{
    cout << "\nfrm:" << mv.GetmFrom() << " to:" << mv.GetmTo()
         << " pl:" << mv.GetmPl() << " pi:" << mv.GetmPi()
         << " C?:" << mv.GetmIsCap() << " plC:" << mv.GetmCPl();
    cout << " CaPie:";
    for ( int i = 3; i >= 0; i-- ) {
        ( mv.GetmPBits() & 1ULL << i ) ? cout << 1 : cout << 0;
    }
    cout << "\n";
}
