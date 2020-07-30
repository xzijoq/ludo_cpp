#include "DebugE.h"
#include "DeclarationsE.h"
#include "iostream"
#include "ran.h"

#include "EngineE.h"
using std::cout;


int man()
{
    InitAllPlayers();
    DebugE::zDebugMoveFunctions();


    ranPrint();
    return 0;

}


