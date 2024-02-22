#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#define PERM 0644

char set_perms(int st_mode,  char perms_array[10]);
char get_file_type(int st_mode );

int  my_ls(char *argv[]);
int  my_cp(char *argv[]);
int  my_chmod(char *argv[]);

