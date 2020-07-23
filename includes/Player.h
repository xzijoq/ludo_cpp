
#include <Node2D.hpp>
#include <array>

#include "Area2D.hpp"
#include "Common.h"
#include "GData.h"
#include "PackedScene.hpp"
#include "Ref.hpp"
#include "String.hpp"
#include "Texture.hpp"
#include "Vector2.hpp"

namespace godot
{
class Player : public Node2D
{
    GODOT_CLASS( Player, Node2D );

   private:
    void InitPieces();

   private:
    Ref<PackedScene> PPiecL;
    Ref<Texture>     PieceTexture;

    std::array<Area2D*, G2::MAX_PIECES> Piece;

   public:
    static void _register_methods();
    void        _init();
    void        _ready();
    void        Dw_MovePiece( int piece, Vector2 posi );
    void        SetActivePl( int what );
    void        SetTexturePl( String path );
    int         GetPlID();
    void        SetPlID( int id );
    void        _on_Piece_Clicked(int pieceID);

   public:
    int PlayerID   = 0;
    int IsActivePl = 1;  // active by default
};
}  // namespace godot
