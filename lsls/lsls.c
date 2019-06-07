#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name;
  struct dirent *enter;
  struct stat fileStat;

  if (argc <= 1) // checks to see if there is no input
  {
    dir_name = "."; //prints current directory
  } else if (argc == 2) { // if the directory in input is (argv[1]), make a reference to it
    dir_name = argv[1];
  }
  // else { //catches incorrect directories or errors
  //   printf("Cannot open dir '%s'!", argv[2]);
  // }

  // Open directory
  DIR *od = opendir(dir_name);
  if (od == NULL) {
    printf("Directory '%s' cannot be opened!\n", argv[1]);
    exit(1);
  }

  // Repeatedly read and print entries
  while ((enter = readdir(od)) != NULL)
  {
    stat(enter->d_name, &fileStat);
    if (fileStat.st_mode & __S_IFDIR)
    {
      printf("%s\n", enter->d_name);
    }
    else {
      printf("size: %ldkb\t file: %s\n", fileStat.st_size, enter->d_name);
    }
  }

  // Close directory
  closedir(od);

  return 0;
}