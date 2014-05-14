#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

// General:
#define NONE 0
#define _Out

// Errors:
#define SUCCESS                 0
#define MISC_ERROR             -1
#define INITIALIZATION_ERROR   -2
#define OUT_OF_MEMORY_ERROR    -3
#define FILE_ERROR             -4
#define BAD_FUNCTION_ARGUMENT  -5
#define ABORTED_BY_USER        -6 // Not necessarily an error, but good to know when it happens
#define IO_ERROR               -7 // Non-file I/O error

// Intended modes:
#define XvX   0x1  // e.g. 1v1
#define XvXvX 0x2  // e.g. 1v1v1
#define FFA   0x4  // Free for all

// Node connection types:
#define _1_TO_2   0x1
#define _2_TO_1   0x2
#define BOTH_WAYS 0x3

// Owner:
#define NEUTRAL    0
#define PLAYER(n)  n
#define AI(n)     -n

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
