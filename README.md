# IOS_file_Copier

 A simple file copier and editor

Learning Goal: I'm working on a operating systems project and need a sample draft to help me learn.

the program should have the option to copy directories.
I will be using MacOS terminal for this assignment
Hints:

Include fcntl.h

system calls to consider: creat, open, read, write, exit

For directories dirent.h is useful to include, system calls to consider: opendir, readdir

Do not use standard library (i.e. do not include stdlib.h nor use fopen,....etc. This defies the objective of the assignment.

What to turn in:

1. Your source code
2. A shell script to compile your source file and execute it using at least 4 test cases. (attached is an example)
3. Screenshots of the execution of your shell script.
   Note: please put all files in a directory, zip the directory and send it as one file.

LIBRARIES USEDNAME

dirent.h - format of directory entries

#### SYNOPSIS

#include <dirent.h>

#### DESCRIPTION

The internal format of directories is unspecified.The *<dirent.h>* header defines the following data type through  **typedef** :

DIRA type representing a directory stream.It also defines the structure **dirent** which includes the following members:
ino_t  d_ino       file serial number
char   d_name[]    name of entry

The type **ino_t** is defined as described in  *[&lt;sys/types.h&gt;](https://pubs.opengroup.org/onlinepubs/7908799/xsh/systypes.h.html)* .The character array **d_name** is of unspecified size, but the number of bytes preceding the terminating null byte will not exceed {NAME_MAX}.

The following are declared as functions and may also be defined as macros. Function prototypes must be provided for use with an ISO C compile.

int            closedir(DIR *);
DIR           *opendir(const char *);
struct dirent *readdir(DIR *);
int            readdir_r(DIR *, struct dirent *, struct dirent **);
void           rewinddir(DIR *);
void           seekdir(DIR *, long int);
long int       telldir(DIR *);


#### APPLICATION USAGE

None.

#### FUTURE DIRECTIONS

None.
