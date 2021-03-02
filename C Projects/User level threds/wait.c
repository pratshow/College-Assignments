extern int tswitch();

void tsleep(int event) {
    running->event = event;
    running->status = SLEEP;
    enqueue(&sleepList, running);
    tswitch();
}

int twakeup(int event) {
    int i = 0;
    PROC *p;
    p = &sleepList[i];
    while(p) {
        if (p->event == event) {
            p->status = READY;
            enqueue(&readyQueue, p);
        }
        *p = sleepList[i+1];
    }
}

int join(int targetPid, int *status) {
    while(1) {
        while((int)readyQueue->pid != targetPid && running->pid != targetPid) { //If the readyQueue doesn't match
            if (readyQueue->pid == 0) { // 0 is the end of the readyQueue
                printf("No PID of %d\n", targetPid);
                return -1;
            }
            readyQueue = readyQueue->next;
        }
        if(targetPid == (int)running->pid) {
            printf("DEADLOCK ERROR\n");
            return -1;
        }
        //running->joinPtr->next;
        running->joinPid = targetPid;
        running->joinPtr = (PROC *)targetPid;
        if((int)running->joinPtr == ZOMBIE) {
            PROC *p = (PROC *)targetPid;
            *status = p->exitStatus;    // extract ZOMBIE exit status
            p->status = FREE;
            p->priority = 0;
            enqueue(&freeList, p);      // release p to freeList
            return p->pid;
        }
        tsleep(targetPid);      // sleep on targetPID until woken up by target task
    }
}

int texit(int status) {
    if (status) {
        running->exitStatus = status;
        running->status = ZOMBIE;
        twakeup(running->pid);
    }
    else {
        printf("task %d in texit value=%d\n", running->pid, running->pid);
        running->status = FREE;
        running->priority = 0;
        enqueue(&freeList, running);
        //printList("freeList", freeList);
    }
    tswitch();
}
