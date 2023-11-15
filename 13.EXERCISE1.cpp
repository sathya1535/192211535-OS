#include <stdio.h>
#include <stdlib.h>

// Define the structure for an employee
struct Employee {
    int empId;
    char empName[50];
    float empSalary;
};

// Function to add a new employee record
void addEmployee(FILE *file) {
    struct Employee emp;

    printf("Enter employee ID: ");
    scanf("%d", &emp.empId);
    printf("Enter employee name: ");
    scanf("%s", emp.empName);
    printf("Enter employee salary: ");
    scanf("%f", &emp.empSalary);

    fseek(file, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee added successfully!\n");
}

// Function to display details of a specific employee
void displayEmployee(FILE *file) {
    struct Employee emp;
    int empId;

    printf("Enter employee ID: ");
    scanf("%d", &empId);

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    if (emp.empId != 0) {
        printf("Employee ID: %d\n", emp.empId);
        printf("Employee Name: %s\n", emp.empName);
        printf("Employee Salary: %.2f\n", emp.empSalary);
    } else {
        printf("Employee not found!\n");
    }
}

// Function to modify details of a specific employee
void modifyEmployee(FILE *file) {
    struct Employee emp;
    int empId;

    printf("Enter employee ID: ");
    scanf("%d", &empId);

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    if (emp.empId != 0) {
        printf("Enter new employee name: ");
        scanf("%s", emp.empName);
        printf("Enter new employee salary: ");
        scanf("%f", &emp.empSalary);

        fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
        fwrite(&emp, sizeof(struct Employee), 1, file);

        printf("Employee details modified successfully!\n");
    } else {
        printf("Employee not found!\n");
    }
}

// Function to delete a specific employee record
void deleteEmployee(FILE *file) {
    struct Employee emp;
    int empId;

    printf("Enter employee ID: ");
    scanf("%d", &empId);

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    if (emp.empId != 0) {
        emp.empId = 0;
        fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
        fwrite(&emp, sizeof(struct Employee), 1, file);

        printf("Employee record deleted successfully!\n");
    } else {
        printf("Employee not found!\n");
    }
}

int main() {
    FILE *file;
    file = fopen("employee.dat", "r+");

    if (file == NULL) {
        // If the file does not exist, create a new one
        file = fopen("employee.dat", "w+");
        if (file == NULL) {
            printf("Error creating file!\n");
            return 1;
        }
    }

    int choice;

    do {
        printf("\nEmployee Record System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Modify Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                displayEmployee(file);
                break;
            case 3:
                modifyEmployee(file);
                break;
            case 4:
                deleteEmployee(file);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    fclose(file);

    return 0;
}
