#include <BoardDisplay.h>
#include <GameDisplay.h>
#include <GameManager.h>
#include <LudoEngine.h>
#include <PPiece.h>
#include <Player.h>

using namespace godot;
extern "C" void GDN_EXPORT godot_gdnative_init( godot_gdnative_init_options *o )
{
    godot::Godot::gdnative_init( o );
}

extern "C" void GDN_EXPORT
    godot_gdnative_terminate( godot_gdnative_terminate_options *o )
{
    godot::Godot::gdnative_terminate( o );
}

extern "C" void GDN_EXPORT godot_nativescript_init( void *handle )
{
    godot::Godot::nativescript_init( handle );

    godot::register_class<godot::LudoEngine>();
    godot::register_class<godot::PPiece>();
    register_class<BoardDisplay>();
    register_class<GameManager>();
    register_class<GameDisplay>();
    register_class<Player>();
}