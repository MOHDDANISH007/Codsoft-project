#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class TaskList {
private:
    vector<Task> tasks;

public:
    void addTask(string description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "Task list is empty." << endl;
        } else {
            cout << "Task List:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description;
                if (tasks[i].isCompleted) {
                    cout << " (Completed)";
                }
                cout << endl;
            }
        }
    }

    void markAsCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].isCompleted = true;
            cout << "Task marked as completed: " << tasks[taskIndex - 1].description << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex - 1].description << endl;
            tasks.erase(tasks.begin() + taskIndex - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TaskList taskList;
    int choice;

    do {
        cout << "\nTask Management System\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, taskDescription);
                taskList.addTask(taskDescription);
                break;
            }
            case 2:
                taskList.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                taskList.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                taskList.removeTask(taskIndex);
                break;
            }
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
