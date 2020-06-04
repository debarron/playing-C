#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>


void get_dir_and_file(const char *path, char **dir, char **file){
  char *path_dir, *path_file;

  path_dir = dirname(path);
  path_file = basename(path);

  if(strcmp(path_dir, "/") == 0){
    *dir = strdup(path_file);
    *file = NULL; 
  } else{
    *dir = strdup(&path_dir[1]);
    *file = strdup(path_file);
  }
}

int main(int argc, char **argv){
  fprintf(stdout, "## LIBGEN-TEST\n");

  const char *my_string = "this is a string";
  char *my_string_copy = strdup(my_string);
  my_string_copy[3] = 'z';
  fprintf(stdout, "## SIMPLE TEST OF 'strdup' function\n");
  fprintf(stdout, "## -> |%s| vs. |%s|\n\n", my_string, my_string_copy);


  if (argc < 1){
    fprintf(stderr, ">> ERROR: Expecting an argument\n");
    return 1;
  }
  
  char *file, *dir;
  const char *my_path = argv[1];
  get_dir_and_file(my_path, &dir, &file);
  fprintf(stdout, "## path:|%s| dir:|%s| file:|%s|\n", my_path, dir, file);

  return 0;
}
