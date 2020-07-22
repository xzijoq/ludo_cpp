#include <bits/stdint-intn.h>

#include <Area2D.hpp>
#include <Godot.hpp>

#include "InputEvent.hpp"

namespace godot
{
class PPiece : public godot::Area2D
{
    GODOT_CLASS( PPiece, Area2D );

   public:
    int PlayerID=0;
    int PieceID=0;
    int IsActivePi=1;

   public:
    static void _register_methods();
    void        _ready();
    void        _init();

   private:
    void _on_PPiece_Input_event( const Object*, Ref<InputEvent>, int64_t );
    void test();
};

}  // namespace godot
