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

// Intended modes:
#define XvX   0x1  // e.g. 1v1
#define XvXvX 0x2  // e.g. 1v1v1
#define FFA   0x4  // Free for all

// Node connection types:
#define _1_TO_2   1
#define _2_TO_1   2
#define BOTH_WAYS 3

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

// Placement of structures:
#define ORBIT       1
#define ON_PLANET_1 2
#define ON_PLANET_2 3
#define ON_PLANET_3 4
#define ON_PLANET_4 5
#define ON_PLANET_5 6
// Alternate placement:
#define TOP         2
#define BOTTOM      3
#define RIGHT       4
#define LEFT        5


#endif // DEFINES_H_INCLUDED
