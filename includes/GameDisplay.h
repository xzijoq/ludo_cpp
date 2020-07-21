
#include <Common.h>

#include <Node2D.hpp>
namespace godot
{
class GameDisplay : public Node2D
{
    GODOT_CLASS( GameDisplay, Node2D );

   public:
    static void _register_methods();
    void        _init();
};
}  // namespace godot