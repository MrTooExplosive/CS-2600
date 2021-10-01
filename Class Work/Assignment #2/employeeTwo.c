#include <string.h>
#include "employee.h"

static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr, int (*functionPtr)(const void *, PtrToConstEmployee))
{
   PtrToConstEmployee endPtr = ptr + tableSize;

   for (; ptr < endPtr; ptr++)
   {
      if ((*functionPtr)(targetPtr, ptr) == 0)
         return (PtrToEmployee) ptr;
   }
   return NULL;
}

static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
   return * (long *) targetPtr != tableValuePtr->number;
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
   return strcmp((char *) targetPtr, tableValuePtr->name);
}

//The exact same as compareEmployeeName() except compares to phone instead of name
static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
   return strcmp((char *) targetPtr, tableValuePtr->phone);
}

//The exact same as compareEmployeeNumber() except compares to salary instead of number
static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
   return * (double *) targetPtr != tableValuePtr->salary;
}

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number)
{
   return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name)
{
   return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

//Wrapper for searching by salary
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary)
{
   return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}

//Wrapper for searching by phone
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char* number)
{
   return searchEmployeeTable(ptr, size, number, compareEmployeePhone);
}