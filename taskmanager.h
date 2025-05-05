#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <string>

// Structure to hold a task
struct Task {
    std::string description;
    bool completed;
};

// Function declarations
void loadTasks();
void saveTasks();
void showTasks();
void addTask();
void markTaskDone();
void deleteCompletedTasks();
void deleteAllTasks();

#endif // TASKMANAGER_H
