#include "priorityScheduler.h"
#include <stdlib.h>
#include <string.h>


Process* newProcess(String name,int time,int priority){
    Process *process = malloc(sizeof(Process));
    memcpy(process->name,name,sizeof(String));
    process->time = time;
    process->priority = priority;
    process->nextProcess = NULL;
    return process;
}

Scheduler* createScheduler(int timeSlice){
    Scheduler *scheduler = malloc(sizeof(Scheduler));
    scheduler->head = NULL;
    scheduler->total = 0;
    scheduler->timeSlice = timeSlice;
    return scheduler;
}

int insertProcess(Scheduler* scheduler,Process* process){
    Process *first = scheduler->head;
    scheduler->head = process;
    scheduler->total++;
    return 1;
}