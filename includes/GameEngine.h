#include <GData.h>

#include <Godot.hpp>
#include <Node2D.hpp>

#include "Area2D.hpp"
#include "InputEvent.hpp"
#include "Node.hpp"
#include "Sprite.hpp"
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

   public:
};
}  // namespace godot
