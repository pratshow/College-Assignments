#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <time.h>
#include <inttypes.h>
#include <math.h>

#define LEN 64
int ppipe[2];           // pipe descriptors
int pid;                // child pid
char line[LEN];
int sends;              // time message was sent
int sendms;
int recs;               // time recived
int recms;
long    ms;
long    ns;
time_t  s;
struct timespec spec;   // struct for time

int getsec() { // Timestamps, seconds since January 1, 1970
    clock_gettime(CLOCK_REALTIME, &spec);
    s = spec.tv_sec;                        //seconds
    ms = round(spec.tv_nsec / 1.0e6);       //milliseconds
    if (ms > 999) {
        s++;
        ms = 0;
    }
    return s;
}

int getms() {
    clock_gettime(CLOCK_REALTIME, &spec);
    ms = round(spec.tv_nsec / 1.0e6);       // Rounds the nanosec division for a number < 1000
    return ms;
}

int getns() { // use nanoseconds to do math without needing to worry about rounding done in getsec() or getms()
    clock_gettime(CLOCK_REALTIME, &spec);
    ns = spec.tv_nsec;
    return ns;
}

int printtime(int s, int ms) {
    return printf("[%"PRIdMAX".%01d]", (intmax_t)s, ms);
}

int totaltime(int sends, int sendms, int recs, int recms) { // timestamps recorded in seconds since 01/01/1970
    int totalsec = (recs - sends);
    int totalms = (recms - sendms);
    if (totalms < 0) {
        totalsec - 1;
        totalms *= -1;  //Negates negative
    }
    printf("\nTotal time round trip: ");
    printtime(totalsec, totalms);
}

