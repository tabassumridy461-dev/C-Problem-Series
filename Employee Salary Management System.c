#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float medical;
    float tax;
    float grossSalary;
    float netSalary;
};

int main() {
    struct Employee employee;

    printf("Employee Salary Management System\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employee.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employee.name);

    printf("Enter Basic Salary: ");
    scanf("%f", &employee.basicSalary);

    employee.hra = employee.basicSalary * 0.20;
    employee.medical = employee.basicSalary * 0.10;
    employee.grossSalary = employee.basicSalary + employee.hra + employee.medical;
    employee.tax = employee.grossSalary * 0.05;
    employee.netSalary = employee.grossSalary - employee.tax;

    printf("\nEmployee Salary Details\n");
    printf("Employee ID: %d\n", employee.id);
    printf("Employee Name: %s\n", employee.name);
    printf("Basic Salary: %.2f Taka\n", employee.basicSalary);
    printf("House Rent Allowance: %.2f Taka\n", employee.hra);
    printf("Medical Allowance: %.2f Taka\n", employee.medical);
    printf("Gross Salary: %.2f Taka\n", employee.grossSalary);
    printf("Tax Deduction: %.2f Taka\n", employee.tax);
    printf("Net Salary: %.2f Taka\n", employee.netSalary);

    return 0;
}
