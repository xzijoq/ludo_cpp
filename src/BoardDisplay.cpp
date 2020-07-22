#include <BoardDisplay.h>
#include <GData.h>

#include "Area2D.hpp"
#include "PackedScene.hpp"
#include "ResourceLoader.hpp"

using namespace godot;

Area2D *PPtest;

void BoardDisplay::_ready()
{
    InitBoard();

     DrawBoard();

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
    Ref<PackedScene> Cell_I   = nullptr;
    Ref<Texture>     SafeCell = nullptr;

    auto             Loader   = ResourceLoader::get_singleton();
    Cell_I                    = Loader->load( "res://scenes/Square.tscn" );
    SafeCell = Loader->load( "res://assets/PlayerIcons/safecell.png" );
    for ( auto l = 0; l < G2::LudoBoard.size(); l++ ) {
        int k = G2::LudoBoard[l];

        Cell[l] = (Sprite *)Cell_I->instance();
        Cell[l]->set_position( Posi[k] );
        // Cell[l]->position = G2::Posi[k];
        Cell[l]->set_scale( Scale_L );

        Cell[l]->call( "SetId", l );

        add_child( (const Node *)Cell[l] );
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
