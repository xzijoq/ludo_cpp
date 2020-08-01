#include <GData.h>
#include <PPiece.h>
#include <bits/stdint-intn.h>

#include <Godot.hpp>
#include <Sprite.hpp>
#include <cstdio>
#include <string>

#include "GodotGlobal.hpp"
#include "InputEvent.hpp"
#include "InputEventAction.hpp"
#include "InputEventMouseButton.hpp"
#include "Node.hpp"
#include "Object.hpp"
#include "PoolArrays.hpp"
#include "ResourceLoader.hpp"
#include "Texture.hpp"
#include "Timer.hpp"
#include "Vector2.hpp"
#include "gdnative/variant.h"
#include "SceneTree.hpp"
using namespace godot;

void PPiece::_ready()
{
    Initialize();
    connect( "input_event", this, "_on_PPiece_Input_event" );
}

void PPiece::Initialize()
{
    ClickCD = Timer::_new();
    ClickCD->set_wait_time( .2 );
    ClickCD->set_one_shot( true );

    add_child( ClickCD );

    Vector2 Scale_L;
    float   CellSize = 0.0f;
    int     SPixel   = 64;

    // update later

    SC_SZ = Vector2( 600, 1024 );

    float ShortLen = SC_SZ.x < SC_SZ.y ? SC_SZ.x : SC_SZ.y;

    // ShortLen=600;
    CellSize = ShortLen / G2::MAX_ROW;
    Scale_L  = Vector2( CellSize / SPixel, CellSize / SPixel );
    set_scale( Scale_L );
    // MoveTo( Vector2( 72, 72 ) );
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
    if ( posi != Vector2( 72, 72 ) ) {
        set_global_position( posi );
    } else {
        if ( PieceID == 0 ) { set_position( Vector2( 0, 0 ) ); }
        if ( PieceID == 1 ) { set_position( Vector2( 64, 0 ) ); }
        if ( PieceID == 2 ) { set_position( Vector2( 0, 64 ) ); }
        if ( PieceID == 3 ) { set_position( Vector2( 64, 64 ) ); }
    }
}

int  PPiece::GetPiID() { return PieceID; }
void PPiece::SetPiID( int piID ) { PieceID = piID; }

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
                             GODOT_VARIANT_TYPE_INT );
}

void PPiece::_on_PPiece_Input_event( const Object* vp, Ref<InputEvent> event,
                                     int64_t idx )
{
    //  Godot::print( "HAmn abbhi zinda hain nigger" );
    if ( event->get_class() == "InputEventMouseButton" ) //d
    {

        if ( ( (Ref<InputEventMouseButton>)event )->get_button_index() == 1 ) //d
        {
            if ( event->is_pressed() ) //d
            {
                if (  ClickCD->is_stopped() ) //crazy

                {
                    get_tree()->set_input_as_handled();
                   // Godot::print("PieceCLicked");
                   // Godot::print(PieceID+48);
                    emit_signal( "Up_PPclicked_s", PieceID );
                    
                    // Godot::print("omg");}
                    ClickCD->start();
                }
            }
        }
    }
}
void PPiece::_init() {}

void PPiece::test( String a ) { Godot::print( "Wahh Kya Bakchodihai" ); }
