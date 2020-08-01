#include "DeclarationsE.h"
#include <iostream>

using std::cout;


void PieceE::InitPieceE( u32 sq, u32 inSq, u32 endSq, u32 swiSq,
                            u32 plNum, u32 pieNum
                        )
{
    Sq(sq);
    InSq(inSq);
    EndSq(endSq);
    SwiSq(swiSq);
    Pnum(plNum);
    PieNum(pieNum);
    


}


void BitsE::DisplayBits(int sp)
{
    for ( auto i = 31; i >= 0; i-- ) {
        ( PInt & 1ULL << i ) ? cout << 1 : cout << 0;
        if ( ( i ) % sp == 0 ) { cout << " "; }
        if ( ( i ) % 4 == 0 && sp==8 ) { cout << " "; }
    }
}
