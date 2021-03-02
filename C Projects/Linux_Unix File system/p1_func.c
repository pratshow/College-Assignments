#include <p1_make.h>

//Adds an element to the beginning of the linked list
void push(NODE **cur_dir_head, NODE *first_el, char *element_name, char *type) {
    NODE *new_element = (NODE *) malloc(sizeof(NODE));
    strcpy(new_element->name, element_name);
    if (strcmp(type, "D") == 0)
        strcpy(new_element->type, "D");
    if (strcmp(type, "F") == 0)
        strcpy(new_element->type, "F");
    //Makes the new element the head and set prev_sibling and sibling pointers accordingly
    new_element->sibling = (*cur_dir_head);
    (*cur_dir_head) = new_element;
    first_el->prev_sibling = new_element;
    new_element->child = NULL;
    new_element->parent = cwd;
}

//Initializing my root dir and setting cwd to the root
NODE *initialize() {
    root = (NODE *)malloc(sizeof(NODE));
    strcpy(root->name, "/");
    root->parent = NULL;
    root->child = NULL;
    root->sibling = NULL;
    root->prev_sibling = NULL;
    strcpy(root->type, "D");
    cwd = root;
    return root;
    return cwd;
}

//Makes a new directory and sets it's parent to the cwd
NODE *new_node(char *name, char *type) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    strcpy(node->name, name);
    node->child = NULL;
    node->sibling = NULL;
    node->prev_sibling = NULL;
    if (strcmp(type, "D") == 0)
        strcpy(node->type, "D");
    if (strcmp(type, "F") == 0)
        strcpy(node->type, "F");
    node->parent = cwd;
    return node;
}

//Checks if a current node is present, if so make the new dir the child of the current node
NODE *insert(NODE *current_node, char *name, char *type) {
    if (current_node == NULL) {
        return new_node(name, type);
    }
    else if (current_node && current_node->child != NULL) {
        push(&cwd->child, cwd->child, name, type);
    }
    else {
        current_node->child = insert(current_node->child, name, type);
    }
}
//Updates the cwd pointer to where you would like to go
void *cd(char *location, NODE *list_head) {
    // Make a variable to reset everything back to original if the cd fails.
    NODE *list_el = cwd->child;
    if (strcmp(location, "..") == 0) {
        return cwd = list_head->parent;
    }
    else if (strcmp(location, "") == 0){
        printf("No arg found!\n");
        return cwd = root;
    }
    else {
        if (list_el == NULL) {                   //Makes sure the list_el isn't empty to avoid seg faults
            printf("%s doesn't exist\n", location);
            return list_head = cwd;
        }
        else {                                   //Loop cycles through linked list looking for a match
            while (strcmp(location, list_el->name) != 0 && list_el != NULL) {
                if (list_el->sibling == NULL) {
                goto FAIL;
                }
                else {
                    list_el = list_el->sibling;
                }
            }                                   //Checks if it's a file or directory
            if (strcmp("F", list_el->type) == 0) {
               printf("%s is a file, please specify a directory\n", location);
            }
            else {
                return cwd = list_el;
            }
        }
    }
    FAIL:
        printf("%s doesn't exist\n", location);
}

//Simply prints where you are in the tree from cwd to rootlo
char pwd(NODE *cwd) {
    if (cwd->parent == NULL);
        printf("/");
    while (cwd->parent != NULL) {
        printf("%s/", cwd->name);
        cwd = cwd->parent;
    }
    printf("\n");
}

//List all the elements of the linked list
void ls(NODE *element_ref) {
    while (element_ref != NULL) {
        printf("%s[%s]  ", element_ref->name, element_ref->type);
        if (element_ref->sibling == NULL) {
            break;
        }
        else {
            element_ref = element_ref->sibling;
        }
    }
    printf("\n");
}
/*Deletes a element of the linked list
A bit messey but needed to be very specific so I didn't evaluate a nonexistant pointer resulting in a seg fault
It doesn't get rid of the dependent files when removing a directory*/
void rm(char *location, char *cmd) {
    int file_index = 0;
    NODE *current_el = cwd->child;
    NODE *el_before_deletion = cwd->child;
    if (strcmp(location, "") == 0)                      //Checks if the location exits
        goto FAIL;
    if (current_el == NULL)
        goto FAIL;
    while (strcmp(location, current_el->name) != 0) {   //Progresses current_el until it matches a file or is NULL
        current_el = current_el->sibling;
        if (current_el == NULL)
            goto FAIL;
        else
            file_index++;
    }
    if (strcmp(location, current_el->name) == 0) {      //If the location and element name match
        if (strcmp(current_el->type, "D") == 0 && strcmp(cmd, "rm") == 0 ) {  //Check if it's a directory rather than a file
            printf("%s is a directory, please specify a file or use rmdir to remove a directory\n", location);
        }
        else if (strcmp(current_el->type, "F") == 0 && strcmp(cmd, "rmdir") == 0 ) {
            printf("%s is a file, please specify a directory or use rm to remove a file\n", location);
        }
        else {
            if (file_index != 0) {                      //If the dir is not the head
                for (int i=0; i < (file_index-1); i++) {//Get's it's previous node
                    el_before_deletion = el_before_deletion->sibling;
                }
                el_before_deletion->sibling = current_el->sibling; //Moving previous node pointer to node after deleted node
                current_el->prev_sibling = el_before_deletion;
                FREE:   //Frees the node
                free((void *)current_el);
            }
            else {                                      //If the file is the head
                el_before_deletion = NULL;              //The prior element is NULL
                if (current_el->sibling == NULL) {      //If it's the only file in the list
                    free((void *)current_el);
                    cwd->child = NULL;
                }
                else{                                   //If there are other files in the list
                    el_before_deletion = current_el;    //Moving the element to be deleted some variable to delete later
                    cwd->child = current_el->sibling;   //List head is now the next in the linked list
                    free((void *)el_before_deletion);
                }
            }
        }
    }
    else {
    FAIL:
        printf("%s is not a location\n", location);
    }
}

//Quick quit function that allow you to specify the exit number
int quit(char *user_input) {
    if (user_input == NULL) {
        printf("Goodbye 0\n");
        exit(0);
    }
    else {
        int exitnum = atoi(user_input);
        printf("Goodbye %d\n", exitnum);
        exit(exitnum);
    }
}

