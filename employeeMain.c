#include <string.h> 
#include <stdlib.h> 
#include "Employee.h" 

int main(void)
{ 
    //each return a pointer 
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable,double salaryToFind); 
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable,char* phoneToFind); 

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr;//Declaration 

    //Example found for salary
    matchPtr = searchEmployeeBySalary(EmployeeTable,EmployeeTableEntries,6.34); 
    if(matchPtr!= NULL) 
        printf("Employee with salary 6.34 is in record %ld\n",matchPtr - EmployeeTable); 
    else 
        printf("Employee salary is NOT found in the record\n"); 
    //Example not found for salary
    matchPtr = searchEmployeeBySalary(EmployeeTable,EmployeeTableEntries,7.3); 
    if(matchPtr!= NULL) 
        printf("Employee with salary 7.3 is in record %ld\n",matchPtr - EmployeeTable); 
    else 
        printf("Employee salary is NOT found in the record\n"); 


    //Example found for phone number 
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-2134"); 
    if(matchPtr != NULL) 
        printf("Employee with phone number 909-555-2134 is in record %ld\n",matchPtr - EmployeeTable); 
    else 
        printf("Employee with phone number 909-555-2134 is NOT found in the record\n"); 
    //Example not found for phone number 
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "809-225-2138"); 
    if(matchPtr != NULL) 
        printf("Employee with phone number 809-225-2138is in record %ld\n",matchPtr - EmployeeTable); 
    else 
        printf("Employee with phone number 809-225-2138is NOT found in the record\n"); 

    return EXIT_SUCCESS; 
}