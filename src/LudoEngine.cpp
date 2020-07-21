#include <LudoEngine.h>
#include <bits/stdint-intn.h>

#include <OS.hpp>
#include <Reference.hpp>
#include <cstdlib>
#include <iostream>

#include "Button.hpp"
#include "GodotGlobal.hpp"
#include "InputEventMouseButton.hpp"
#include "String.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "gdnative/gdnative.h"
#include "gdnative/string.h"

using namespace godot;

Sprite s2;
// Sprite *s1=nullptr;
// Area2D *t1=nullptr;

void LudoEngine::_ready()
{
    auto* l = OS::get_singleton();
    l->set_window_position( Vector2( 12, 12 ) );
    
    Godot::print( get_name() );
    //  s1 = (godot::Sprite *)(get_child( 0 ));
    s1 = Object::cast_to<Sprite>( get_child( 0 ) );

    p1=Object::cast_to<Area2D>(get_node("PPiece"));
    p1->call("test");

    Godot::print( s1->get_name() );

    s1->set_position( Vector2( 120, 120 ) );
    s1->rotate( 12 );
    t1 = Object::cast_to<Area2D>( get_node( "wow/cow" ) );
    t1->connect( "input_event", this, "Printer" );
}

void LudoEngine::_register_methods()
{
    register_method( "_process", &LudoEngine::_process );
    register_method( "_ready", &LudoEngine::_ready );
    register_method( "Printer", &LudoEngine::Printer );
}
void LudoEngine::Printer( const Object* vp, const Ref<InputEvent> event,
                          const int64_t shape_idx )
{
    if ( ( event->get_class() ) == "InputEventMouseButton" ) {
        if ( ( (const Ref<InputEventMouseButton>)event )->get_button_index() ==
             1 ) {
            std::cout << sizeof( *s1 );
            Godot::print( "ButtonSize: " );
            Godot::print( sizeof( Button ) );


        }
    }
}
void LudoEngine::_init()
{
    // quick_exit(12);
}

void LudoEngine::_process() {}
LudoEngine::LudoEngine() {}

LudoEngine::~LudoEngine() {}
