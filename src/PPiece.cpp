#include <GData.h>
#include <PPiece.h>
#include <bits/stdint-intn.h>

#include <Godot.hpp>
#include <Sprite.hpp>
#include <cstdio>
#include<string>


#include "GodotGlobal.hpp"
#include "InputEvent.hpp"
#include "InputEventMouseButton.hpp"
#include "Object.hpp"
#include "PoolArrays.hpp"
#include "ResourceLoader.hpp"
#include "Texture.hpp"
#include "gdnative/variant.h"
using namespace godot;

void PPiece::_ready()
{

    connect( "input_event", this, "_on_PPiece_Input_event" );
    //  SetTexturePi("res://assets/PlayerIcons/p2.png");

    // PlayerID=false;
}
void PPiece::SetTexturePi( String PathT )
{

    
    //  Godot::print( "Picaslled" );
    auto Loader = ResourceLoader::get_singleton();
    ( (Sprite*)get_node( "Sprite" ) )
        ->set_texture( (Ref<Texture>)Loader->load( PathT ) );
}

void PPiece::MoveTo( Vector2 posi )
{
    // Animation and all here
    set_position( posi );
}

void PPiece::_on_PPiece_Input_event( const Object* vp, Ref<InputEvent> event,
                                     int64_t idx )
{
    //  Godot::print( "HAmn abbhi zinda hain nigger" );
    if ( event->get_class() == "InputEventMouseButton" ) {
        if ( ( (Ref<InputEventMouseButton>)event )->get_button_index() == 1 ) {
            if ( IsActivePi != 0 ) {
                emit_signal( "Up_PPclicked_s", PlayerID, 3 );
            }
        }
    }
}

int  PPiece::GetPiID(){

 return PieceID;

}
void PPiece::SetPiID( int piID ){

    PieceID=piID;
}

void PPiece::_register_methods()
{
    register_method( "_ready", &PPiece::_ready );
    register_method( "_on_PPiece_Input_event",
                     &PPiece::_on_PPiece_Input_event );
    register_method( "MoveTo", &PPiece::MoveTo );
    register_method( "test", &PPiece::test );
    register_method( "SetTexturePi", &PPiece::SetTexturePi );
    register_method( "GetPiID", &PPiece::GetPiID );
    register_method( "SetPiID", &PPiece::SetPiID );

    // register_method( "SetTexturePi", &PPiece::SetTexturePi);
    // Signals
    // Down
    // Up
    register_signal<PPiece>( (char*)"Up_PPclicked_s", "pyID",
                             GODOT_VARIANT_TYPE_INT, "piID",
                             GODOT_VARIANT_TYPE_INT );
}
void PPiece::_init() {}

void PPiece::test( String a ) { Godot::print( "Wahh Kya Bakchodihai" ); }
