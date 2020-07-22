#include <BoardDisplay.h>
#include <GData.h>

#include "Area2D.hpp"
#include "Node2D.hpp"
#include "PackedScene.hpp"
#include "ResourceLoader.hpp"
#include "Vector2.hpp"

using namespace godot;

Area2D *PPtest;

void BoardDisplay::_ready()
{
    InitBoard();

    DrawBoard();
    InitPlayers();
}

void BoardDisplay::InitPlayers()
{
    String DefaultPiece[] = {
        "res://assets/PlayerIcons/p0.png",
        "res://assets/PlayerIcons/p1.png",
        "res://assets/PlayerIcons/p2.png",
        "res://assets/PlayerIcons/p3.png",

    };
    int  j      = 0;
    auto Loader = ResourceLoader::get_singleton();
    Player_L    = Loader->load( "res://scenes/Player.tscn" );
    for ( int i = 0; i < Player.size(); i++ ) {
        Player[i] = (Node2D *)Player_L->instance();

        add_child( Player[i] );
        Player[i]->set_position( Vector2( 0, j += 64 ) );
        Player[i]->call( "SetTexturePl", DefaultPiece[i] );
        Player[i]->call( "SetPlID", i );
    }
}

void BoardDisplay::InitBoard()
{
    float CellSize = 0.0f;
    int   SPixel   = 64;

    // update later

    SC_SZ = Vector2( 600, 1024 );

    float ShortLen = SC_SZ.x < SC_SZ.y ? SC_SZ.x : SC_SZ.y;

    // ShortLen=600;
    CellSize = ShortLen / G2::MAX_ROW;
    Scale_L  = Vector2( CellSize / SPixel, CellSize / SPixel );

    float XOffset = ( CellSize / 2 );
    float YOffset = ( CellSize / 2 ) + ( SC_SZ.y / 4 );

    for ( int i = 0, k = 0; i < G2::MAX_ROW; i++ ) {
        for ( int j = 0; j < G2::MAX_COL; j++, k++ ) {
            Posi[k] = Vector2( CellSize * j + XOffset, CellSize * i + YOffset );
        }
    }
}
void BoardDisplay::DrawBoard()
{
    auto             Loader   = ResourceLoader::get_singleton();
    Ref<PackedScene> Cell_I   = nullptr;
    Ref<Texture>     SafeCell = nullptr;

    Cell_I   = Loader->load( "res://scenes/Square.tscn" );
    SafeCell = Loader->load( "res://assets/PlayerIcons/safecell.png" );
    for ( auto l = 0; l < G2::LudoBoard.size(); l++ ) {
        int k = G2::LudoBoard[l];

        Cell[l] = (Sprite *)Cell_I->instance();

        add_child( (const Node *)Cell[l] );
        Cell[l]->set_position( Posi[k] );
        Cell[l]->set_scale( Scale_L );
        Cell[l]->call( "SetId", l );
    }
    for ( int i : G2::SafeSq ) { Cell[i]->set_texture( SafeCell ); }
}

Vector2 BoardDisplay::GetPosi( int square ) { return Posi[square]; }
void    BoardDisplay::_register_methods()
{
    register_method( "_ready", &BoardDisplay::_ready );

    register_method( "InitBoard", &BoardDisplay::InitBoard );
    register_method( "DrawBoard", &BoardDisplay::DrawBoard );
    register_method( "GetPosi", &BoardDisplay::GetPosi );
}
void BoardDisplay::_init() {}
