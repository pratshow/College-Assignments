#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define TRUE 1
#define MAXNAMELENTH 128

//Structure for user inputs
typedef struct user_input {
    int num_inputs;
    char **input;
}INPUT;

//Structure for the nodes of the tree
typedef struct node {
    char name[MAXNAMELENTH];                //Name of node made by the user
    char type[32];                          //Node is a file or directroy
    struct node *child, *sibling, *prev_sibling, *parent;  //It's referece to other nodes
}NODE;

NODE *root; //Making the current and root node global
NODE *cwd;

NODE *initialize();
void execute(INPUT input);
