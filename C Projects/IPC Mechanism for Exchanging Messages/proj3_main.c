#include "proj3_header.h"

int parent() {
    int start, end;
    int i = 0;
    printf("parent %d running \n", getpid());
    close(ppipe[0]);    // parent = pipe writer
    while(1) {
        i++;            // srand uses seed, increment i every use for new seed. To seem a bit more random
        srand(i);
        int r = rand() % 10;    // random # between 0 - 9
        printf("parent %d: input a line :\n", getpid());
        fgets(line, LEN, stdin);
        printf("Sent at: ");
        printtime(getsec(), getms());
        printf("\n");
        line[strlen(line)-1] = 0; // kill \n at end
        if (r < 4) {    // %50 chance of failing
            do {
                printf("parent %d write to pipe\n", getpid());
                start = getns();      // record current timer
                if (r < 4) {
                    printf("Failed to send message; retrying...\n");
                    sleep(1);         // Sleep for 1 sec, making total time > 10ms
                }
                r = rand() % 10;    // New random # for a chance to fail again
                end = getns();
            } while(end - start > 10000);   // 10000ns = 10 ms
        }
        write(ppipe [1], line, LEN); // write to pipe
        printtime(getsec(), getms());
        printf("parent %d successfully wrote to pipe\n", getpid());
        printf("parent %d send signal 10 to %d\n", getpid(), pid);
        kill(pid, SIGUSR1);           // send signal to child process
    }
}

void reply_handler(int sig) {
    sends = getsec();
    sendms = getms();
    for (int j = 0; j < 9999; j++) {    //simulates computation time
        for(int k = 0; k < 999; k++){}}
    int i = 0;
    printf("child %d got an interrupt sig=%d\n", getpid(), sig);
    read(ppipe[0], line, LEN);      // read pipe
    while (i<strlen(line)) {        // loop to read the message 1 charater at a time and convert to capital
        line[i] = toupper(line[i]);
        i++;
    }
    recs = getsec();
    recms = getms();
    printtime(recs, recms);
    printf("Child replay: %s", line);
    totaltime(sends, sendms, recs, recms);
    printf("\n");
}

int child() {
    char msg[LEN];
    int parent = getppid();
    printf("child %d running\n", getpid());
    close(ppipe[1]);                 // child is a pipe reader
    signal(SIGUSR1, reply_handler);  // install signal catcher
    while(1);
}

int main() {
    pipe(ppipe);                // create a pipe
    pid = fork();               // install signal catcher
    if (pid)    //parent
        parent();
    else
        child();
}
