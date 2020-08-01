#pragma once

//#include "DebugE.h"
#include "GData.h"

class BitsE
{
   public:
    u32                  PInt;
    static constexpr u32 pow[]{
        0b0,     0b1,      0b11,      0b111,     0b1111,  // wow
        0b11111, 0b111111, 0b1111111, 0b11111111

    };

    BitsE() : PInt{ 0 } {}

   public:
    void        DisplayBits( int sp = 8 );
    inline u32  GetBit( u32 bit ) { return ( ( PInt >> bit ) & (u32)1 ); }
    inline void SetBit( u32 bit ) { PInt |= (u32)1 << bit; }
    inline void UnSetBit( u32 bit ) { PInt &= ~( (u32)1 << bit ); }

    inline void SetBits( u32 count, u32 bits, u32 posi )
    {
        // clear those bits to zero and set new
        PInt &= ~( pow[count] << posi );
        PInt |= bits << posi;
    }
    inline u32 GetBits( u32 count, u32 posi )
    {
        return ( PInt >> posi ) & pow[count];
    }
};

//  PPnum(4 (0-16)) //Switch Into 7// EndSq 7// InSq 7// Square 7
//  32-30       28            21        14         7       0
class PieceE : public BitsE
{
   public:
    static inline u32 GetPPnum( u32 pl, u32 pi )
    {
        return (pl * G2::MAX_PIECES + pi);
    }
    inline u32 Sq() { return GetBits( 7, 0 ); }
    inline u32 InSq() { return GetBits( 7, 7 ); }
    inline u32 EndSq() { return GetBits( 7, 14 ); }
    inline u32 SwiSq() { return GetBits( 7, 21 ); }
    inline u32 PieNum() { return GetBits( 2, 28 ); }
    inline u32 Pnum() { return GetBits( 2, 30 ); }
    inline u32 PPnum() { return GetBits( 4, 28 ); }
    void       InitPieceE( u32 Sq, u32 InSq, u32 EndSq, u32 SwiSq, u32 PlNum,
                           u32 PieNum );

    inline void Sq( u32 sq ) { SetBits( 7, sq, 0 ); }
    

   private:
    inline void InSq( u32 sq ) { SetBits( 7, sq, 7 ); }
    inline void EndSq( u32 sq ) { SetBits( 7, sq, 14 ); }
    inline void SwiSq( u32 sq ) { SetBits( 7, sq, 21 ); }
    inline void PieNum( u32 pieNum ) { SetBits( 2, pieNum, 28 ); }
    inline void Pnum( u32 pNum ) { SetBits( 2, pNum, 30 ); }
    inline void PPnum( u32 ppNum ) { SetBits( 4, ppNum, 28 ); }

   public:
    friend class DebugE;
};

// pp0-4 pp1-4 pp2-4 pp3-4 isSw1 Swpp2 to7 isSafe1 isEnd1
// 0      4     8    12     16    17    19   26      27     28
class SquareE : public BitsE
{
    const int M_Pi = G2::MAX_PIECES;

   public:
    inline u32 Pl( u32 pl ) { return ( GetBits( M_Pi, pl * M_Pi ) ); }
    inline u32 PP( u32 pl, u32 pi ) { return GetBit( ( pl * M_Pi + pi ) ); }
    inline u32 PP( u32 PPnum ) { return GetBit( PPnum ); }

    inline void PushPP( u32 pl, u32 pi ) { SetBit( pl * M_Pi + pi ); }
    inline void PushPP( u32 PPnum ) { SetBit( PPnum ); }
    inline void PopPP( u32 pl, u32 pi ) { UnSetBit( pl * M_Pi + pi ); }
    inline void PopPP( u32 PPnum ) { UnSetBit( PPnum ); }
};

// from7  to7  PP4 isCap1  Cpl2 pieBits4  lsb->msb
//   0     7    14  18     19    21 ---    25
class MoveE : public BitsE
{
   public:
    inline void From( u32 frm ) { SetBits( 7, frm, 0 ); }
    inline void To( u32 to ) { SetBits( 7, to, 7 ); }
    inline void PP( u32 pp ) { SetBits( 4, pp, 14 ); }
    inline void Pl( u32 pl ) { SetBits( 2, pl, 16 ); }
    inline void Pi( u32 pi ) { SetBits( 2, pi, 14 ); }
    inline void IsCap( u32 val ) { SetBits( 1, val, 18 ); }
    inline void CPl( u32 pl ) { SetBits( 2, pl, 19 ); }
    inline void PBits( u32 bits ) { SetBits( 4, bits, 21 ); }
    inline void CPiece( u32 piece ) { SetBit( 21 + piece ); }

    inline u32 From() { return GetBits( 7, 0 ); }
    inline u32 To() { return GetBits( 7, 7 ); }
    inline u32 PP() { return GetBits( 4, 14 ); }
    inline u32 Pl() { return GetBits( 2, 16 ); }
    inline u32 Pi() { return GetBits( 2, 14 ); }
    inline u32 IsCap() { return GetBits( 1, 18 ); }
    inline u32 CPl() { return GetBits( 2, 19 ); }
    inline u32 PBits() { return GetBits( 4, 21 ); }
    friend class DebugE;
};
