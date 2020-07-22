
#include <Player.h>
#include <array>


#include "Godot.hpp"

using namespace godot;

void Player::_register_methods()
{

        register_method( "_ready", &Player::_ready );
	

}

void Player::_ready(){
  
}

void Player::_init() {}
