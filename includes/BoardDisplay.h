#include <Common.h>
#include <GData.h>

#include <Node2D.hpp>
#include <Texture.hpp>
#include <array>

#include "PackedScene.hpp"
#include "Ref.hpp"
#include "Sprite.hpp"
#include "Vector2.hpp"
#include"Timer.hpp"
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
    void DrawBaseBoard();


   private:
    Vector2            SC_SZ   = Vector2( 0, 0 );
    Vector2            Scale64 = Vector2( 0, 0 );
    Vector2            Scale_L = Vector2( 0, 0 );
    const Vector2      HOME_SQ = Vector2( 72, 72 );
    std::array<int, 10> MoveD;
    Timer* InputDelay;

    std::array<Sprite *, G2::LudoBoard.size()>      Cell;
    std::array<Sprite *, G2::MAX_ROW * G2::MAX_COL> BCell;
    std::array<Vector2, G2::MAX_ROW * G2::MAX_COL>  Posi;
    std::array<Node2D *, G2::MAX_PLAYERS>           Player;
    Ref<PackedScene>                                Player_L;

   public:
    void        _init();
    static void _register_methods();
    void        _ready();
    void        _on_PPclicked( int player, int piece );
    Vector2     GetPosi( int square );
    void        MovePP_TO( int player, int piece, int square );
};

}  // namespace godot
