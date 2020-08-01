#include <GameEngine.h>
#include <bits/stdint-intn.h>
#include <sys/types.h>

#include <iostream>

#include "CoreE.h"
#include "DebugE.h"
#include "EngineE.h"
#include "GData.h"
#include "OS.hpp"
using namespace godot;

#define Mpp( pl, pi, sq ) DBoard->call( "MovePP_TO", pl, pi, sq )


void GameEngine::_ready()
{
    DBoard = (Node2D*)get_node( "../BoardDisplay" );
    DBoard->connect( "Up_PieceClicked", this, "InputClicked" );
    man();
    auto os=OS::get_singleton();
    os->set_window_position(Vector2(1250,0));


}

void GameEngine::ApplyMove( MoveE mv )
{   // DebugE::DisplaySquares();
    Mpp( mv.Pl(), mv.Pi(), mv.To() );

    if ( mv.IsCap() == 1 ) {
        int player = mv.CPl();

        for ( int i = 0; i < 4; i++ ) {
            if ( ( ( mv.PBits() >> i ) & (u32)1 ) != 0 ) {
                Mpp( player, i, 72 );
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
  //  Godot::print("fff");
    MoveE tt;
    tt=OnPieceClicked(player, piece);

    ApplyMove( tt );
   // DebugE::DisplayPMove(test);
}

void GameEngine::_init()
{
    // quick_exit(12);
}

void GameEngine::_process() {}
