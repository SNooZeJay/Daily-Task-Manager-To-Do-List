#include "taskmanager.h"
#include <iostream>
#include <windows.h> // for Windows functions

using namespace std;

int main() {
    loadTasks();
    int choice;
    do {
        system("cls"); // clear screen for each menu refresh
        cout << "--- Daily Task Manager ---\n";
        cout << "1. Show Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete Completed Tasks\n";
        cout << "5. Save Tasks\n";
        cout << "6. Delete ALL Tasks\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        system("cls"); // clear screen after input
        switch (choice) {
            case 1: showTasks(); break;
            case 2: addTask(); break;
            case 3: markTaskDone(); break;
            case 4: deleteCompletedTasks(); break;
            case 5: saveTasks(); break;
            case 6: deleteAllTasks(); break;
            case 0: saveTasks(); cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 0);
    return 0;
}
