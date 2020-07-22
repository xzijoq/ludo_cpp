#include <Common.h>
#include <GData.h>

#include <Node2D.hpp>
#include <Texture.hpp>
#include <array>
#include "Ref.hpp"

#include "PackedScene.hpp"
#include "Sprite.hpp"
namespace godot
{
class BoardDisplay : public Node2D
{
    GODOT_CLASS( BoardDisplay, Node2D );

   private:
    void InitBoard();
    void DrawBoard();
    void DrawDebugBoard();
    void InitPlayers();

   private:
    Vector2 SC_SZ   = Vector2( 0, 0 );
    Vector2 Scale64 = Vector2( 0, 0 );
    Vector2 Scale_L = Vector2( 0, 0 );

    std::array<Sprite *, G2::LudoBoard.size()>     Cell;
    std::array<Vector2, G2::MAX_ROW * G2::MAX_COL> Posi;
    std::array<Node2D *, G2::MAX_PLAYERS>          Player;
    Ref<PackedScene>                               Player_L;

   public:
    void        _init();
    static void _register_methods();
    void        _ready();

    Vector2 GetPosi( int square );
};

}  // namespace godot
