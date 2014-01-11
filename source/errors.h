#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED

#include <stdbool.h>

#include "defines.h"

// To make it easier to see if a function returns or gets error numbers
typedef int error_flag;

// Writes a message to stderr if an error has occurred, otherwise does nothing.
void write_error_message(error_flag flag, bool fatal);

#endif // ERRORS_H_INCLUDED
