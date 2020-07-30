#pragma once

#include <array>

#define ARRAY_SIZE( a ) ( sizeof( a ) / sizeof( a[0] ) )

using u32 = std::uint_fast32_t;
namespace G2
{
struct IntV2 {
    int x;
    int y;
};

int constexpr MAX_ROW     = 15;
int constexpr MAX_COL     = 15;
int constexpr MAX_PLAYERS = 4;
int constexpr MAX_PIECES  = 4;
int constexpr START_POSI  = 72;
int constexpr END_POSI    = 73;

u32 constexpr MAX_PP = G2::MAX_PIECES * G2::MAX_PLAYERS;

constexpr std::array SpawnPoint{ 0, 12, 192, 180 };

constexpr std::array LudoBoard{
    6, 7, 8, 23, 38, 53, 68, 83,                                     // 0-7
    99, 100, 101, 102, 103, 104, 119, 134, 133, 132, 131, 130, 129,  // 8-20
    143, 158, 173, 188, 203, 218, 217, 216, 201, 186, 171, 156,
    141,                                                        // 21-33
    125, 124, 123, 122, 121, 120, 105, 90, 91, 92, 93, 94, 95,  // 34-46
    81, 66, 51, 36, 21,                                         // 47-51
    // inSideSafe
    22, 37, 52, 67, 82,       // 52-56
    118, 117, 116, 115, 114,  // 57-61
    202, 187, 172, 157, 142,  // 62-66
    106, 107, 108, 109, 110,  // 67-71
    START_POSI, END_POSI };

constexpr std::array SafeSq       = { 3,  11, 16, 24,         29,
                                37, 42, 50, START_POSI, END_POSI };
constexpr std::array StartSq      = { 3, 6, 29, 42 };
constexpr std::array SwitchSq     = { 1, 14, 27, 40 };
constexpr std::array SwitchIntoSq = { 52, 57, 62, 67 };
constexpr std::array EndSq        = { 56, 61, 66, 71 };

}  // namespace G2
