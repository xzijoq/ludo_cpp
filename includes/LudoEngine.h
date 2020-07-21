#include <Godot.hpp>
#include <Node2D.hpp>
#include "Node.hpp"
#include "InputEvent.hpp"
#include "Sprite.hpp"
#include "Area2D.hpp"

namespace godot
{
class LudoEngine : public godot::Node2D
{
    GODOT_CLASS( LudoEngine, Node2D );
private:
  Sprite* s1;
  Area2D* t1;
  Area2D* p1;

   public:
    void        Test();
    int         Yada;
    int         Nada;

 
    static void _register_methods();
    void        _init();
    void        _ready();
    void        _process();
  void Printer(const Object *vp,const Ref<InputEvent> evenT,const int64_t idx);
    LudoEngine();
    ~LudoEngine();
};
}  // namespace godot


