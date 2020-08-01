#include <GData.h>
#include <bits/stdint-intn.h>

#include <Godot.hpp>
#include <Node2D.hpp>

#include "CoreE.h"
using u64 =unsigned long long int;
namespace godot
{
class GameEngine : public godot::Node2D
{
    GODOT_CLASS( GameEngine, Node2D );

   private:
    Node2D* DBoard;

   public:
    static void _register_methods();
    void        _init();
    
    void        _ready();
    void        _process();
    void        InputClicked( int player, int piece );
    void        ApplyMove(MoveE PackedMove);



   public:
};
}  // namespace godot
