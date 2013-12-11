#include "testUtils.h"
#include "priorityScheduler.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1_creates_new_process(){
    Process *process = newProcess("Process1",8,3);
    ASSERT(process->priority == 3);
    ASSERT(process->time == 8);
    ASSERT(strcmp(process->name,"Process1") == 0);
    ASSERT(process->nextProcess == NULL);
    free(process);
};

void test_2_creates_another_process_with_highest_priority_more_time_span(){
    Process *process = newProcess("Process2",10,1);
    ASSERT(process->priority == 1);
    ASSERT(process->time == 10);
    ASSERT(strcmp(process->name,"Process2") == 0);
    ASSERT(process->nextProcess == NULL);
    free(process);
};

void test_3_creates_scheduler_with_timeslice_10_sec(){
    Scheduler *scheduler = createScheduler(10);
    ASSERT(scheduler->head == NULL);
    ASSERT(scheduler->timeSlice == 10);
    ASSERT(scheduler->total == 0);
    free(scheduler);
};

void test_4_inserts_process_in_scheduler(){
    Process process1 = {"Process1",10,1,NULL};
    Scheduler *scheduler = createScheduler(10);
    int result;
    result = insertProcess(scheduler,&process1);
    ASSERT(scheduler->head == &process1);
    ASSERT(scheduler->total == 1);
    ASSERT(result == 1);
};
 
void test_fail(){
	ASSERT(0);
}