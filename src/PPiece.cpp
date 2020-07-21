#include <PPiece.h>

#include <Godot.hpp>

#include <GData.h>
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


    
}
void PPiece::_on_PPiece_Input_event()
{
    Godot::print( "HAmn abbhi zinda hain nigger" );
}

void PPiece::test() { Godot::print( "Wahh Kya Bakchodihai" ); 




}
