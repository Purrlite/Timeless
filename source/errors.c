#include <stdlib.h>
#include <stdio.h>

#include "errors.h"

void write_error_message(error_flag flag, bool fatal) {
  switch(flag) {
    case SUCCESS:
      return;

    case MISC_ERROR:
      fputs("A misc error has occurred!\n", stderr);
      break;

    case INITIALIZATION_ERROR:
      fputs("An error while initializing has occurred!\n", stderr);
      break;

    case OUT_OF_MEMORY_ERROR:
      fputs("An out of memory error has occurred!\n", stderr);
      break;

    case FILE_ERROR:
      fputs("A file error has occurred!\n", stderr);
      break;

    case BAD_FUNCTION_ARGUMENT:
      fputs("Bad argument to function was supplied!\n", stderr);
      break;

    case POINTER_ALREADY_IN_USE:
      fputs("Pointer is in use when it shouldn't be!\n", stderr);
      break;

    default:
      fputs("Some unknown error has occurred!\n", stderr);
  }

  if(true == fatal)
    fputs("Fatal error occurred, shutting down. :<\n", stderr);

  return;
}
