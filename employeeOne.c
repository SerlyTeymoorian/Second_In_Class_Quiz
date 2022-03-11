#include <string.h> 
#include "Employee.h" 

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetsalary)
{
    const PtrToConstEmployee endPtr = ptr+ tableSize; //endPtr points to the end of the table

    for(; ptr <endPtr; ++ptr)
    {
        if(ptr->salary == targetsalary)
            return (PtrToEmployee)ptr; //return the entire row 
    }
    return NULL; //targetSalary not founded 
} 

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr, int tableSize, char* targetPhoneNumber)
{
    const PtrToConstEmployee endPtr = ptr+ tableSize; 

    for(; ptr < endPtr; ++ptr)
    {
        if(strcmp(ptr->phone, targetPhoneNumber) ==0)
            return (PtrToEmployee)ptr; //phone number found and return the loc of it 
    }
    return NULL; //phone number not found 
}