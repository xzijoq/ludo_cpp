
#include <Common.h>

#include <Node2D.hpp>
#include <array>

#include "Area2D.hpp"
#include "GData.h"
#include "Ref.hpp"

namespace godot
{
class Player : public Node2D
{
    GODOT_CLASS( Player, Node2D );

   public:
    static void _register_methods();
    void        _init();
    void        _ready();

   public:
    int IsActivePl = 1;  // active by default

    std::array<Area2D*, G2::MAX_PIECES> Pieces;
};
}  // namespace godot
