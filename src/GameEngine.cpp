#include <GameEngine.h>
#include <bits/stdint-intn.h>
#include <sys/types.h>

#include <iostream>

#include "CoreE.h"
#include "DebugE.h"
#include "EngineE.h"
#include "GData.h"

using namespace godot;

#define Mpp( pl, pi, sq ) DBoard->call( "MovePP_TO", pl, pi, sq )
MoveE test;

void GameEngine::_ready()
{
    DBoard = (Node2D*)get_node( "../BoardDisplay" );
    DBoard->connect( "Up_PieceClicked", this, "InputClicked" );

    test.SetmTo( 12 );
    test.SetmPl( 0 );
    test.SetmPi( 0 );
    test.SetmIsCap( 1 );
    test.SetmCPl( 1 );
    test.SetmPBits( 0b1101 );
}

void GameEngine::ApplyMove( MoveE mv )
{
    Mpp( mv.GetmPl(), mv.GetmPi(), mv.GetmTo() );

    if ( mv.GetmIsCap() == 1 ) {
        int player = mv.GetmCPl();

        for ( int i = 0; i < 4; i++ ) {
            if ( ( ( mv.GetmPBits() >> i ) & (u32)1 ) != 0 ) {
                Mpp( player, i, 43 );
            }
        }
    }
}

void GameEngine::_register_methods()
{
    register_method( "_process", &GameEngine::_process );
    register_method( "_ready", &GameEngine::_ready );
    register_method( "InputClicked", &GameEngine::InputClicked );
}

void GameEngine::InputClicked( int player, int piece )
{

    ApplyMove( test );
    DebugE::DisplayPMove(test);
}

void GameEngine::_init()
{
    // quick_exit(12);
}

void GameEngine::_process() {}
