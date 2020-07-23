#include <GameEngine.h>
#include <bits/stdint-intn.h>

#include <OS.hpp>
#include <Reference.hpp>
#include <cstdlib>
#include <iostream>

#include "Button.hpp"
#include "GodotGlobal.hpp"
#include "InputEvent.hpp"
#include "InputEventMouseButton.hpp"
#include "String.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "gdnative/gdnative.h"
#include "gdnative/string.h"



using namespace godot;

Sprite s2;
// Sprite *s1=nullptr;
// Area2D *t1=nullptr;

void GameEngine::_ready()
{
    DBoard=(Node2D*)get_node("BoardDisplay");
}

void GameEngine::_register_methods()
{
    register_method( "_process", &GameEngine::_process );
    register_method( "_ready", &GameEngine::_ready );
    register_method("InputClicked",&GameEngine::InputClicked);

}

void GameEngine::InputClicked(int player, int piece){

}

void GameEngine::_init()
{
    // quick_exit(12);
}

void GameEngine::_process() {


}



