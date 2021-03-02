#include <stdio.h>
#include <stdlib.h>
#include "type.h"
PROC proc[NPROC];       // NPROC proc structures
PROC *freeList;         // free PROC list
PROC *readyQueue;       // ready proc priority queue
PROC *sleepList;        // sleep PROC list
PROC *running;          // running proc pointer

#include "queue.c"      // enqueue(), dequeue(), printList()
#include "wait.c"       // tsleep/twakeup/texit/join functions
#include "mutex.c"      // mutex operations functions

#define N 4
int A[N] [N];           // A matrix
MUTEX *mp;              // mutex for task synchronization
int total;              // global total

extern int tswitch();
int scheduler();
int create();

int init() {
    int i, j;
    PROC *p;
    for (i=0; i<NPROC; i++){
        p = &proc[i];
        p->pid = i;
        p->ppid = 1;
        p->priority = 0;
        p->status = FREE;
        p->event = 0;
        p->next = p+1;
    }
    proc[NPROC-1].next = 0;
    freeList = &proc[0];   // all PROCs in freeList
    readyQueue = 0;
    sleepList = 0;
    // create P0 as initial running task
    p = running = dequeue(&freeList);
    p->status = READY;
    p->priority = 0;
    printList("freeList", freeList);

    printf("P0: initialize A matrix\n");
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            A[i][j] = i*N + j + 1;
        }
    }
    for (i=0; i<N; i++) {   // show the matrix
        for (j=0; j<N; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }
    mp = mutex_create();    // create a mutex
    total = 0;
    printf("init complete\n");
}

int myexit() {              // for task exit
    texit(0);
}

void func (void *arg) {
    int i, row, s;
    int me = running->pid;
    row = (int)arg;
    printf("task %d computes sum of row %d\n", me, row);
    s = 0;
    for (i=0; i < N; i++) {
        s += A[row][i];
    }
    printf("task %d update total with %d\n", me, s);
    mutex_lock(mp);
     total +=s;
     printf("[total = %d]  ", total);
    mutex_unlock(mp);
}

void task1(void *parm) {
    int pid[N];
    int i, status;
    int me = running->pid;
    printf("task %d: create working tasks : ", me);
    for(i=0; i < N; i++) {
        pid[i] = create(func, (void *)i);
        printf("%d ", pid[i]);
    }
    printf(" to compute matrix row sums\n");
    for (i=0; i<N; i++) {
        printf("task %d tries to join with task %d\n", running->pid, pid[i]);
        join(pid[i], &status);
    }
    printf("task %d : total = %d\n", me, total);
}

int create (void (*f)(), void *parm) {
    int i;
    PROC *p = dequeue(&freeList);
    if (!p){
        printf("fork failed\n");
        return -1;
    }
    p->ppid = running->pid;
    p->status = READY;
    p->priority = 1;
    p->joinPid = 0;
    p->joinPtr = 0;
    for (i=1; i<12; i++) {
        p->stack[SSIZE-i] = 0;
        p->stack[SSIZE-1] = (int)parm;     // function parameter
        p->stack[SSIZE-2] = (int)myexit;   // function return address
        p->stack[SSIZE-3] = (int)f;        // function entry
        p->ksp = (int)&p->stack[SSIZE-12]; // ksp -> stack top

    }
    enqueue(&readyQueue, p);
    return p->pid;
}

int main() {
    printf("Welcome to the MT User-Level Threads System\n");
    init();
    create((void *)task1, 0);
    tswitch();
    printf("Matrix total = %d\n", total);
    printf("all task ended: p0 loops\n");
    while(1);
}

int scheduler() {
    if (running->status == READY)
        enqueue(&readyQueue, running);
    running = dequeue(&readyQueue);
}
