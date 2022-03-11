#include <string.h> 
#include "Employee.h" 

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,int(*functionPtr)(const void*, PtrToConstEmployee)) 
{
    PtrToConstEmployee endPtr = ptr + tableSize; 
    for(; ptr <endPtr; ptr++) 
        if((*functionPtr)(targetPtr,ptr) == 0) 
            return (PtrToEmployee) ptr; 
        return NULL; 
} 

//The functionPtr will point to one of these comparison functions to perform a check 
static int compareEmployeeSalary(const void* targetPtr,PtrToConstEmployee tableValuePtr) 
{ 
    return *(double*) targetPtr != tableValuePtr->salary;//const void *targetPtr ==> typecast as int pointer then dereference 
} 

static int compareEmployeePhoneNumber(const void *targetPtr,PtrToConstEmployee tableValuePtr) 

{ 
    return strcmp((char*) targetPtr, tableValuePtr->phone);//const void *targetPtr ==> typecast as char pointer then pass into strcmp() 
} 

//These are called wrappers. These functions are what you will use in your main!!! 
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr,int size,double salary) 
{ 
    return searchEmployeeTable(ptr,size,&salary,compareEmployeeSalary); 
} 

PtrToEmployee searchEmployeeByPhoneNumber(PtrToConstEmployee ptr,int size,char* phone) 
{ 
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhoneNumber); 
} 