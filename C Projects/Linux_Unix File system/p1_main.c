#include <p1_make.h>

//Loop for the shell to get command and go to execute.
void main() {
    //Sets up root node and cwd pointers
    initialize();
    // Shell loop
    while (TRUE) {
        printf("> ");
        INPUT input;
        // Gets user input
        char* line = NULL;
        size_t n = 0;
        getline(&line, &n, stdin);

        int input_count = 1;
        char *strptr = line;
        while (*strptr != '\0') {
            if (*strptr == ' ')
                input_count++;
            if (*strptr == '\n')
                *strptr = '\0';
            strptr++;
        }
        input.num_inputs = input_count;
        input.input = malloc(input_count *sizeof(char*));
        input.input[0] = strtok(line, " ");
        for (int i = 1; i < input_count; i++) {
            input.input[i] = strtok(NULL, " ");
        }
        execute(input);
    }
}
