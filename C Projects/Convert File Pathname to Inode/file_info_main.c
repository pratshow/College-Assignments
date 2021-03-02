#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAXLEN 128

char *dirname[MAXLEN];
struct stat file_stat;  // stat buffer

void file_info(char *pathname) {
    int inode = stat(pathname, &file_stat);
    if (inode == -1) {
        printf("file inode not found exit: -1\n");
        exit(-1);
    }
    printf("file type: ");
    switch (file_stat.st_mode & S_IFMT) {    //gets file type. idea off "man fstatat" example
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("normal file\n");            break;
        default:       printf("unknown\n");                 break;
    }
    // Various file information
    printf("Mode: %lo\n", (unsigned long) file_stat.st_mode); 
    printf("inode number: %d\n", file_stat.st_ino);
    printf("owner ID: %d\n", file_stat.st_uid);                    
    printf("size: %dB\n", file_stat.st_size);
    printf("date created: %s", ctime(&file_stat.st_ctime));
}

//Unused but it just prints the directory path and file name.
void tokenpath(int dircount, char *dirname[]) {
    int j = 0;
    for (j = 0; j < dircount-1; j++) {
        chdir(dirname[j]);
        printf("dir path -> %s | ", dirname[j]);
    }
    printf("file name -> %s\n", dirname[j]);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Usage - arg:[pathname]\n");
        exit(1);
}
    file_info(argv[1]);
    //  Tokenizes the pathname into an array. Didn't end up needing this or tokenpath function.
    /*int i = 0;
    char *pthname = strtok(argv[1], "/")
    while (pthname) {
        dirname[i] = pthname;        // dirname[i] array of dirs
        chdir(pthname);
        pthname = strtok(NULL, "/"); // reads the next string from what it was tokenizing previously
        i++;                         // i is the total count of the pathname
    }
    tokenpath(i, dirname);*/
}

