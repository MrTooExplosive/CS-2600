#include <string.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber)
{
   const PtrToConstEmployee endPtr = ptr + tableSize;

   for (; ptr < endPtr; ptr++)
   {
      if(ptr->number == targetNumber)
         return (PtrToEmployee) ptr;
   }
   return NULL;
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName)
{
   const PtrToConstEmployee endPtr = ptr + tableSize;

   for (; ptr < endPtr; ptr++)
   {
      if(strcmp(ptr->name, targetName) == 0)
         return (PtrToEmployee) ptr;
   }
   return NULL;
}

//The exact same thing as searchEmployeeByName() but instead of comparing to name, compares to phone
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone)
{
   const PtrToConstEmployee endPtr = ptr + tableSize;

   for (; ptr < endPtr; ptr++)
   {
      if(strcmp(ptr->phone, targetPhone) == 0)
         return (PtrToEmployee) ptr;
   }
   return NULL;
}

//The exact same thing as searchEmployeeByNumber(), but instead of comparing to number, compares to salary
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary)
{
   const PtrToConstEmployee endPtr = ptr + tableSize;

   for (; ptr < endPtr; ptr++)
   {
      if(ptr->salary == targetSalary)
         return (PtrToEmployee) ptr;
   }
   return NULL;
}