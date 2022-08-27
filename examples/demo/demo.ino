#include "../../src/tasks.h"

TASKS loopTasks;

void task();

void setup() {
    loopTasks.add([]() {
        task();
    });
}

void loop() {
    loopTasks.run();
}

void task() {
    //do something
    return;
}