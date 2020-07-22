#include <GData.h>
#include <PPiece.h>
#include <bits/stdint-intn.h>

#include <Godot.hpp>

#include "InputEvent.hpp"
#include "InputEventMouseButton.hpp"
#include "Object.hpp"
#include "PoolArrays.hpp"
#include "gdnative/variant.h"
using namespace godot;

void PPiece::_init() {}

void PPiece::_ready()
{
    connect( "input_event", this, "_on_PPiece_Input_event" );
}

void PPiece::_register_methods()
{
    register_method( "_ready", &PPiece::_ready );
    register_method( "_on_PPiece_Input_event",
                     &PPiece::_on_PPiece_Input_event );
    register_method( "test", &PPiece::test );
    register_signal<PPiece>( (char*)"PPclicked", "pyID", GODOT_VARIANT_TYPE_INT,
                             "piID", GODOT_VARIANT_TYPE_INT );
}
void PPiece::_on_PPiece_Input_event( const Object* vp, Ref<InputEvent> event,
                                     int64_t idx )
{
    //  Godot::print( "HAmn abbhi zinda hain nigger" );
    if ( event->get_class() == "InputEventMouseButton" ) {
        if ( ( (Ref<InputEventMouseButton>)event )->get_button_index() == 1 ) {
            if ( IsActivePi != 0 ) { emit_signal( "PPclicked", PlayerID, 3 ); }
        }
    }
}

void PPiece::test() { Godot::print( "Wahh Kya Bakchodihai" ); }
