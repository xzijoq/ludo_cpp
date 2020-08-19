
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
#include "engine/includes/CoreE.h"
#include "gdnative/variant.h"
#include "CoreE.h"

using namespace godot;

void Player::_ready()
{
    InitPieces();

    // SetPlID(3);
}

void Player::InitPieces()
{
    auto Loader = ResourceLoader::get_singleton();

    PPiecL = Loader->load( "res://scenes/PPiece.tscn" );

    for ( int i = 0; i < Piece.size(); i++ ) {
        Piece[i] = (Area2D *)PPiecL->instance();
        add_child( Piece[i] );
        // Piece[i]->set_position( Vector2( j += 64, 0) );
        Piece[i]->call( "SetPiID", i );
        Piece[i]->connect( "Up_PPclicked_s", this, "_on_Piece_Clicked" );
        Dw_MovePiece( i, Vector2( 72, 72 ) );
    }


    // Dw_MovePiece( 1, Vector2( 45, 222 ) );
    // Dw_MovePiece( 2, Vector2( 56, 256 ) );
}

void Player::Dw_MovePiece( int piece, Vector2 posi )
{
    assert( piece < G2::MAX_PIECES );
    //  emit_signal("Dw_move_piece_s",posi);
    // currently direct call implemented
    // if ( posi != Vector2( 72, 72 ) ) { Godot::print( "cargo" ); }
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

int  Player::GetPlID() { return PlayerID; }
void Player::SetPlID( int id ) { PlayerID = id; }

void Player::_register_methods()
{
    register_method( "_ready", &Player::_ready );
    register_method( "SetTexturePl", &Player::SetTexturePl );
    register_method( "GetPlID", &Player::GetPlID );
    register_method( "SetPlID", &Player::SetPlID );
    register_method( "_on_Piece_Clicked", &Player::_on_Piece_Clicked );
    register_method("Dw_MovePiece",&Player::Dw_MovePiece);

    // Signals
    // Down
    register_signal<Player>( (char *)"Dw_move_piece_s", "posi",
                             GODOT_VARIANT_TYPE_VECTOR2 );

    register_signal<Player>( (char *)"Up_PlClicked_s", "Player",
                             GODOT_VARIANT_TYPE_INT, "Piece",
                             GODOT_VARIANT_TYPE_INT );

    // Up
}

void Player::_on_Piece_Clicked( int pieceID )
{  // Godot::print( "fuck me man " );

    emit_signal( "Up_PlClicked_s", PlayerID, pieceID );
}
void Player::_init() {}


