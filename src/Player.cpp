
#include "Player.h"

#include <array>
#include <cassert>
#include <iostream>

#include "Area2D.hpp"
#include "GData.h"
#include "Godot.hpp"
#include "GodotGlobal.hpp"
#include "ResourceLoader.hpp"
#include "String.hpp"
#include "Vector2.hpp"
#include "gdnative/variant.h"

using namespace godot;

void Player::_ready() { InitPieces(); 
//SetPlID(3);


}

void Player::InitPieces()
{
    auto Loader = ResourceLoader::get_singleton();

    PPiecL = Loader->load( "res://scenes/PPiece.tscn" );
    int j  = 0;
    for ( int i = 0; i < Piece.size(); i++ ) {
        Piece[i] = (Area2D *)PPiecL->instance();
        add_child( Piece[i] );
        Piece[i]->set_position( Vector2( j += 64, 64 ) );
        Piece[i]->call("SetPiID",i);
    }

    Dw_MovePiece( 3, Vector2( 0, 0 ) );
    // Dw_MovePiece( 2, Vector2( 56, 256 ) );
}

void Player::Dw_MovePiece( int piece, Vector2 posi )
{
    assert( piece < G2::MAX_PIECES );
    //  emit_signal("Dw_move_piece_s",posi);
    Piece[piece]->call( "MoveTo", posi );
}
void Player::SetTexturePl( String path )
{
    String test = "res:";  // improve on it
    if ( path.begins_with( test ) ) {
        for ( int i = 0; i < Piece.size(); i++ ) {
            Piece[i]->call( "SetTexturePi", path );
        }
    }


}

int  Player::GetPlID() { return PlayerId; }
void Player::SetPlID( int id ) { 
    
 
    PlayerId = id; }

void Player::_register_methods()
{
    register_method( "_ready", &Player::_ready );
    register_method( "SetTexturePl", &Player::SetTexturePl );
    register_method( "GetPlID", &Player::GetPlID );
    register_method( "SetPlID", &Player::SetPlID );

    // Signals
    // Down
    register_signal<Player>( (char *)"Dw_move_piece_s", "posi",
                             GODOT_VARIANT_TYPE_VECTOR2 );

    // Up
}
void Player::_init() {}
