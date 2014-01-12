#include <stdbool.h>
#include <stdio.h>

#include "warnings.h"
#include "errors.h"

error_flag overwrite_file_message(char *file_name) {
  char answer;

  printf("Do you want to overwrite file %s ? [Y/N] ", file_name);

scan_for_answer:
  scanf("%c", &answer);

  if(answer == 'Y' || answer == 'y') {
    return true;
  } else if(answer == 'N' || answer == 'n') {
    return false;
  } else {
    printf("You can only answer with Y or N. Try again: ");
    goto scan_for_answer;
  }
}
