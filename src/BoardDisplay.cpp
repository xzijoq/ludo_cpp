#include <BoardDisplay.h>
#include <GData.h>

#include <string>

#include "Area2D.hpp"
#include "Godot.hpp"
#include "GodotGlobal.hpp"
#include "Node2D.hpp"
#include "PackedScene.hpp"
#include "ResourceLoader.hpp"
#include "Vector2.hpp"
#include "array"
using namespace godot;

Area2D *PPtest;

void BoardDisplay::_ready()
{
    InitBoard();

    DrawBoard();
    InitPlayers();
  //    DrawBaseBoard();
}

void BoardDisplay::InitPlayers()
{
    String DefaultPiece[] = {
        "res://assets/PlayerIcons/p0.png",
        "res://assets/PlayerIcons/p1.png",
        "res://assets/PlayerIcons/p2.png",
        "res://assets/PlayerIcons/p3.png",

    };

    auto Loader = ResourceLoader::get_singleton();
    Player_L    = Loader->load( "res://scenes/Player.tscn" );
    for ( int i = 0; i < Player.size(); i++ ) {
        Player[i] = (Node2D *)Player_L->instance();

        add_child( Player[i] );
        // Godot::print(Posi [G2::SpawnPoint[i]]);
        Player[i]->set_position( Posi[G2::SpawnPoint[i]] );
        Player[i]->call( "SetTexturePl", DefaultPiece[i] );
        Player[i]->call( "SetPlID", i );

        Player[i]->connect( "Up_PlClicked_s", this, "_on_PPclicked" );
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

    float Xost = ( CellSize / 2 );
    float Yost = ( CellSize / 2 ) + ( SC_SZ.y / 4 );

    constexpr int ROW = G2::MAX_ROW;
    constexpr int COL = G2::MAX_COL;

    for ( int i = 0, k = 0; i < ROW; i++ ) {
        for ( int j = 0; j < COL; j++, k++ ) {
            Posi[k] = Vector2( CellSize * j + Xost, CellSize * i + Yost );
        }
    }

    for ( int i = ROW - 1, k = 0; i >= 0; i-- ) {
        for ( int j = 0; j < COL; j++, k++ ) {
            // 90 degree
            // Posi[k] = Vector2( CellSize * i + Xost, CellSize * j + Yost );
        }
    }
    for ( int i = ROW - 1, k = 0; i >= 0; i-- ) {
        for ( int j = COL - 1; j >= 0; j--, k++ ) {
            // 180degree
           // Posi[k] = Vector2( CellSize * j + Xost, CellSize * i + Yost );
        }
    }
    for ( int i = 0, k = 0; i < ROW; i++ ) {
        for ( int j = COL - 1; j >= 0; j--, k++ ) {
            // 270degree
         //   Posi[k] = Vector2( CellSize * i + Xost, CellSize * j + Yost );
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
void BoardDisplay::DrawBaseBoard()
{
    auto             Loader   = ResourceLoader::get_singleton();
    Ref<PackedScene> Cell_I   = nullptr;
    Ref<Texture>     SafeCell = nullptr;

    Cell_I   = Loader->load( "res://scenes/Square.tscn" );
    SafeCell = Loader->load( "res://assets/PlayerIcons/safecell.png" );
    int r    = 0;
    for ( auto l = 0; l < Posi.size(); l++ ) {
        BCell[l] = (Sprite *)Cell_I->instance();

        add_child( (const Node *)BCell[l] );
        BCell[l]->set_position( Posi[l] );
        BCell[l]->set_scale( Scale_L );
        BCell[l]->call( "SetId", r );
        BCell[l]->set_texture( SafeCell );
        r++;
        if ( r == 100 ) { r = 0; }
    }
    //  for ( int i : G2::SafeSq ) { Cell[i]->set_texture( SafeCell ); }
}
Vector2 BoardDisplay::GetPosi( int square ) { return Posi[square]; }
void    BoardDisplay::_register_methods()
{
    register_method( "_ready", &BoardDisplay::_ready );

    register_method( "InitBoard", &BoardDisplay::InitBoard );
    register_method( "DrawBoard", &BoardDisplay::DrawBoard );
    register_method( "GetPosi", &BoardDisplay::GetPosi );
    register_method( "_on_PPclicked", &BoardDisplay::_on_PPclicked );

    register_signal<BoardDisplay>( (char *)"Up_PieceClicked", "PlID",
                                   GODOT_VARIANT_TYPE_INT, "PiID",
                                   GODOT_VARIANT_TYPE_INT );
}

void BoardDisplay::_on_PPclicked( int player, int piece )
{
    std::string s1 = "Player: " + std::to_string( player ) +
                     " Piece: " + std::to_string( piece );

    const char *wow = s1.c_str();
    Godot::print( wow );
}
void BoardDisplay::_init() {}
