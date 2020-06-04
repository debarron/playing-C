#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

int main(){
  fprintf(stdout, "## LIBGEN-TEST\n");

  const char *my_string = "this is a string";
  char *my_string_copy = strdup(my_string);
  my_string_copy[3] = 'z';
  fprintf(stdout, "## -> |%s| vs. |%s|\n", my_string, my_string_copy);

  const char *my_path = "/home////";
  char *dir = dirname(my_path);
  dir[2] = 'a';
  char *file = basename(my_path);
  fprintf(stdout, "## path:|%s| dir:|%s| file:|%s|\n", my_path, dir, file);

  return 0;
}
