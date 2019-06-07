#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *dir_name;
  DIR *od;
  struct dirent *enter;
  struct stat fileStat;

  if (argc <= 1) // checks to see if there is no input
  {
    dir_name = "."; //prints current directory
  } else if (argc == 2) { // if the directory in input is (argv[1]), make a reference to it
    dir_name = argv[1];
  }
  else { //catches incorrect directories or errors
    printf("Cannot open dir '%s'!", argv[1]);
  }

  // Open directory
  od = opendir(dir_name);

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