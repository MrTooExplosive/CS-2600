//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
   PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
   PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
   PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone);

   extern Employee EmployeeTable[];
   extern const int EmployeeTableEntries;

   PtrToEmployee matchPtr;
   matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

   if (matchPtr != NULL)
      printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee ID is not found in the record\n");

   matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
   if (matchPtr != NULL)
      printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
   else
      printf("Employee Tony Bobcat is NOT found in the record\n");


   //No match with phone
   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2759");
   if (matchPtr != NULL)
      printf("Employee with phone number %s is in record %d\n", "714-555-2759", matchPtr - EmployeeTable);
   else
      printf("Employee phone number is NOT found in the record\n");

   //Match with phone number
   matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "714-555-2749");
   if (matchPtr != NULL)
      printf("Employee with phone number %s is in record %d\n", "714-555-2749", matchPtr - EmployeeTable);
   else
      printf("Employee phone number is NOT found in the record\n");

   return EXIT_SUCCESS;

}