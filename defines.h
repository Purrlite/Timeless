#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

// General:
#define NONE       0
#define NEUTRAL    0

// Errors:
#define SUCCESS                 0
#define MISC_ERROR             -1
#define INITIALIZATION_ERROR   -2
#define OUT_OF_MEMORY_ERROR    -3
#define FILE_ERROR             -4
#define BAD_FUNCTION_ARGUMENT  -5
#define POINTER_ALREADY_IN_USE -6

// Intended amount of players:
#define V1v1  0x1
#define V2v2  0x2
#define V3v3  0x4
#define V4v4  0x8
// Free For All
#define FFA_3 0xF
#define FFA_4 0x10
#define FFA_5 0x20
#define FFA_6 0x40
#define FFA_7 0x80
#define FFA_8 0xF0

// Node types:
#define BIG_PLANET    1
#define MEDIUM_PLANET 2
#define SMALL_PLANET  3
#define ASTEROIDS     4
#define EMPTY_SPACE   5

// Node connection types:
#define BOTH_WAYS   1
#define ONLY_1_TO_2 2
#define ONLY_2_TO_1 3

// Owner:
#define PLAYER_1 1
#define PLAYER_2 2
#define PLAYER_3 3
#define PLAYER_4 4
#define PLAYER_5 5
#define PLAYER_6 6
#define PLAYER_7 7
#define PLAYER_8 8
#define AI_1     -1
#define AI_2     -2
#define AI_3     -3
#define AI_4     -4
#define AI_5     -5
#define AI_6     -6
#define AI_7     -7
#define AI_8     -8

// Factions:
#define HUMANS     1

// Structure types:
#define COMMON_RESOURCE_GATHERER 1
#define FACTORY                  2

// Placement of structures:
#define ORBIT  1
#define TOP    2
#define RIGHT  3
#define BOTTOM 4
#define LEFT   5

// Unit types:
#define BUILDER    1
#define COLONIZER  2
#define SCOUT      3
#define SWARM      4
#define ANTI_SWARM 5
#define ANTI_HEAVY 6


#endif // DEFINES_H_INCLUDED
