#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct for Employee
struct Employee {
    int id;
    string name;
    double salary;
};

// Function to add a new employee
void addEmployee(vector<Employee>& employees) {
    Employee newEmployee;
    
    cout << "---------------------\nEnter employee ID: ";
    cin >> newEmployee.id;
    
    // Check if an employee with the same ID already exists
    for (const Employee& emp : employees) {
        if (emp.id == newEmployee.id) {
            cout << "Employee with ID " << newEmployee.id << " already exists. Please enter a different ID.\n---------------------" << endl;
            return; // Exit the function without adding the employee
        }
    }
    
    cout << "Enter employee name: ";
    cin.ignore(); // Clearing input buffer 
    getline(cin, newEmployee.name);
    
    cout << "Enter employee salary: $";
    cin >> newEmployee.salary;
    
    employees.push_back(newEmployee);
    
    cout << "Employee added successfully!\n---------------------" << endl;
}

// Function to print all employee information
void printAllEmployees(const vector<Employee>& employees) {
    cout << "---------------------\nList of Employees:" << endl;
    for (const Employee& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary << endl;
    }
    cout << "---------------------\n";
}

// Function to print salary by employee ID
void printEmployeeSalary(const vector<Employee>& employees, int id) {
    bool found = false;
    for (const Employee& emp : employees) {
        if (emp.id == id) {
            cout << "---------------------\nEmployee ID: " << emp.id << ", Salary: $" << emp.salary << endl;
            cout << "---------------------\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << id << " not found." << endl << "---------------------\n";
    }
}

// Function for employee payout
void employeePayout(vector<Employee>& employees) {
    int empId;
    double bonus;

    cout << "---------------------\nEnter employee ID: ";
    cin >> empId;

    bool found = false;
    for (Employee& emp : employees) {
        if (emp.id == empId) {
            cout <<"Employee name: " << emp.name;
            cout <<"\nEmployee salary: $" << emp.salary;
            cout << "\nEnter bonus for employee: $";
            cin >> bonus;
            double totalPay = emp.salary + bonus;
            cout << "\nTotal pay for " << emp.name << " is: $" << totalPay << "\n---------------------" << endl ;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << empId << " not found."<< "\n---------------------" << endl ;
    }
}

// Function to print sack letter for employee
void printSackLetter(const Employee& emp) {
    cout << "---------------------\nDear " << emp.name << ",\n";
    cout << "We regret to inform you that your employment with our company has been terminated.\n";
    cout << "Please collect your personal belongings and return any company property.\n";
    cout << "We wish you the best in your future endeavors.\n\n";
    cout << "Sincerely,\nManagement\n---------------------" << endl;
}

// Function to delete an employee
void deleteEmployee(vector<Employee>& employees) {
    int empId;
    char choice;

    cout << "---------------------\nEnter employee ID to delete: ";
    cin >> empId;

    bool found = false;
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->id == empId) {
            found = true;
            cout << "Do you want to generate a sack letter for employee " << it->name << "? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                printSackLetter(*it);
            }
            employees.erase(it);
            cout << "Employee with ID " << empId << " deleted successfully.\n---------------------" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << empId << " not found." << "\n---------------------" << endl;
    }
}

int main() {
    vector<Employee> employees;
    char choice;

    do {
        cout << "\nOptions:\n1. Add new employee\n2. Print all employees' info\n3. Print employee salary by ID\n4. Employee payout\n5. Delete employee\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addEmployee(employees);
                break;
            case '2':
                printAllEmployees(employees);
                break;
            case '3':
                int empId;
                cout << "Enter employee ID to print salary: ";
                cin >> empId;
                printEmployeeSalary(employees, empId);
                break;
            case '4':
                employeePayout(employees);
                break;
            case '5':
                deleteEmployee(employees);
                break;
            case '6':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != '6');

    return 0;
}
