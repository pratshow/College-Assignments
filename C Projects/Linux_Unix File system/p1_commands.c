#include <p1_make.h>

//If/else checking for user commands
void execute (INPUT input) {
    //User's input in input.input[0,1] and makes node types poitners to strings.
    char *cmd = input.input[0];
    char *arg = input.input[1];
    char *D = "D";
    char *F = "F";
    //All the diffrent commands
    if (strcmp(cmd, "mkdir") == 0) {
        if (arg == NULL)
            printf("Please specify a name for the directory\n");
        else
        insert(cwd, arg, D);
  } else if (strcmp(cmd, "rmdir") == 0) {
        if (arg == NULL)
            printf("Please specify a directory\n");
        else
            rm(arg, cmd);
  } else if (strcmp(cmd, "cd") == 0) {
    //Check if there is no arg so cd doesn't seg fault with a pointer to a nonexistant location.
        if (arg == NULL) {
            char *none = "";
            cd(none, cwd);  }
        else
           cd(arg, cwd);
  } else if (strcmp(cmd, "ls") == 0) {
        ls(cwd->child);
  } else if (strcmp(cmd, "pwd") == 0) {
        pwd(cwd);
  } else if (strcmp(cmd, "creat") == 0) {
        if (arg == NULL)
            printf("Please specify a name for the file\n");
        else
            insert(cwd, arg, F);
  } else if (strcmp(cmd, "rm") == 0) {
        if (arg == NULL) {
            char *none = "";
            rm(none, cmd);    }
        else
            rm(arg, cmd);
  } else if (strcmp(cmd, "save") == 0) {
        printf("Save/reload is not currently implemented, sorry :(\n");
  } else if (strcmp(cmd, "reload") == 0) {
        printf("Save/reload is not currently implemented, sorry :(\n");
  } else if (strcmp(cmd, "menu") == 0) {
        printf("Implemented commands are:\n"
               "rmdir [directory] - remove a dir\n"
               "cd [directory] - change dir\n"
               "ls - list items in current dir\n"
               "pwd - print working dir\n"
               "creat [directory/file] - create a dir or file\n"
               "rm [directory/file] - remove dir or file\n"
               "save - save current file system\n"
               "reload - refresh the file system\n"
               "menu - lists commands\n");
  } else if (strcmp(cmd, "quit") == 0) {
        quit(arg);
  } else if (cmd == "none") {
        printf("No command, use 'menu' for a list of commands\n");
  } else {
        printf("unknown command\n");
  }
}

