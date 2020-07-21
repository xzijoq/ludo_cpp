
#include <Common.h>

#include <Node2D.hpp>

namespace godot
{
class Player : public Node2D
{
    GODOT_CLASS( Player, Node2D );

   public:
    static void _register_methods();
    void        _init();
};
}  // namespace godot