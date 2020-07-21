
#include <Common.h>

#include <Node2D.hpp>
namespace godot
{
class GameManager : public Node2D
{
    GODOT_CLASS( GameManager, Node2D );

   public:
    static void _register_methods();
    void        _init();
};
}  // namespace godot