typedef struct mutex{
    int lock;       //mutex lock at: 0 for unlocked, 1 for locked
    PROC *owner;    //pointer to owner of mutex; may also use PID
    PROC *queue;    //FIFO queue of BLOCKED wating PROCs
}MUTEX;

MUTEX *mutex_create() { // create a mutex and initialize it
    MUTEX *mp = (MUTEX *)malloc(sizeof(MUTEX));
    mp->lock = 0;
    mp->owner = 0;
    mp->queue = 0;
    return mp;
}

void mutex_destroy(MUTEX *mp){
    free(mp);
}

int mutex_lock(MUTEX *mp){
    if (mp->lock == 0) { //If it's unlocked, lock it and record the owner
        printf("task %d mutex_lock()  ", running->pid);
        mp->lock = 1;
        mp->owner = running;
    }
    else {              //If it's locked enter it into the queue.
        mp->queue[mp->owner->pid].status = BLOCK;
        tswitch();
    }
}

int mutex_unlock(MUTEX *mp) {
    if(mp->lock = 0 || (mp->lock = 1 && mp->owner != running)) { //Mutex is locked and caller is not owner
        printf("ERROR: mutex is already locked or running is the owner of the lock.\n");
        return -1;
    }
    else if(mp->lock = 1 && mp->owner == running) { //Mutex is locked and caller is owner
        if (!mp->queue) {
            printf("task %d mutex_unlock()\n", mp->owner->pid);
            mp->lock = 0;
            mp->owner = 0;
            return 0;
        }
    }
    else {  //Mutex has waiter in queue
        PROC *p = dequeue(&mp->queue);
        mp->owner = p;
        enqueue(&mp->queue, p);
    }
}
