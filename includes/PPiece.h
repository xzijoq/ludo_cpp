#include <bits/stdint-intn.h>

#include <Area2D.hpp>
#include <Godot.hpp>

#include "GodotGlobal.hpp"
#include "InputEvent.hpp"
#include "String.hpp"
#include "Vector2.hpp"
#include "gdnative/variant.h"

namespace godot
{
class PPiece : public godot::Area2D
{
    GODOT_CLASS( PPiece, Area2D );

   public:
    int  PlayerID;
    int  PieceID;
    bool IsActivePi;

   public:
    static void _register_methods();
    void        _ready();
    void        _init();
    void        test( String a );
    void        MoveTo( Vector2 posi );
    void        SetTexturePi( String path );
    int         GetPiID();
    void        SetPiID( int piID );

   private:
    void _on_PPiece_Input_event( const Object*, Ref<InputEvent>, int64_t );
};

}  // namespace godot
