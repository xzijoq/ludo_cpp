#include <Area2D.hpp>
#include <Godot.hpp>

namespace godot
{
class PPiece : public godot::Area2D
{
    GODOT_CLASS( PPiece, Area2D );

   public:
    int PlayerID;
    int PieceID;
    
    

   public:
    static void _register_methods();
    void        _ready();
    void        _init();

   private:
   void _on_PPiece_Input_event();
   void test();
};

}  // namespace godot
