#include "../taskmanager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h> // for Windows functions

using namespace std;

vector<Task> tasks;
const string filename = "tasks.txt";

// Load tasks from file
void loadTasks() {
    ifstream file(filename);
    if (file.is_open()) {
        tasks.clear();
        string desc;
        bool done;
        while (getline(file, desc)) {
            file >> done;
            file.ignore();
            tasks.push_back({desc, done});
        }
        file.close();
        cout << "Tasks loaded from file.\n";
    } else {
        cout << "No saved tasks found.\n";
    }
}

// Save all tasks to file
void saveTasks() {
    ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.description << endl;
        file << task.completed << endl;
    }
    file.close();
    cout << "Tasks saved to file.\n";
}

// Display all tasks
void showTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? 'X' : ' ') << "] " << tasks[i].description << endl;
    }
}

// Add a new task
void addTask() {
    cin.ignore();
    string desc;
    cout << "Enter new task: ";
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added.\n";
}

// Mark a task as completed
void markTaskDone() {
    showTasks();
    if (tasks.empty()) return;
    int num;
    cout << "Enter task number to mark as done: ";
    cin >> num;
    if (num >= 1 && num <= (int)tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as done.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Delete all completed tasks
void deleteCompletedTasks() {
    int before = tasks.size();
    tasks.erase(remove_if(tasks.begin(), tasks.end(), [](Task t) { return t.completed; }), tasks.end());
    int after = tasks.size();
    cout << (before - after) << " completed task(s) deleted.\n";
}

// Delete all tasks from memory and file
void deleteAllTasks() {
    tasks.clear();
    ofstream file(filename, ios::trunc); // clear file
    file.close();
    cout << "All tasks deleted from memory and file.\n";
}
