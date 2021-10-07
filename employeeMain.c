#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void) {
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long target);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *target);
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char *target);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double target);

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2138");
    if (matchPtr != NULL)
        printf("FOUND PHONE NUMBER: %d\n", matchPtr - EmployeeTable);
    else
        printf("PHONE # NOT FOUND\n");

    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134");
    if (matchPtr != NULL)
        printf("FOUND PHONE NUMBER: %d\n", matchPtr - EmployeeTable);
    else
        printf("PHONE # NOT FOUND\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);
    if (matchPtr != NULL)
        printf("FOUND SALARY: %d\n", matchPtr - EmployeeTable);
    else
        printf("SALARY NOT FOUND\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.79);
    if (matchPtr != NULL)
        printf("FOUND SALARY: %d\n", matchPtr - EmployeeTable);
    else
        printf("SALARY NOT FOUND\n");

    return 0;
}