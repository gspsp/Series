#include <Series.h>

Series loopTasks;

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
