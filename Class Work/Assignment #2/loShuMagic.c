#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to find if a given array is a Lo Shu Magic sqaure
int isLoShuMagic(const int square[3][3]);

int main()
{
   int testSquare[3][3] = {{4,9,2}, 
                           {3,5,7}, 
                           {8,1,6}};
   printf(isLoShuMagic(testSquare) ? "True" : "False");
   return EXIT_SUCCESS;
}

int isLoShuMagic(const int square[3][3])
{
   //Check digits are unique and between 1 and 9 inclusive
   char digits[10] = "";
   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
      {
         int digit = square[row][col];
         if (digit < 1 || digit > 9)   //Check if the number is bounded correctly
            return 0;
         if (strchr(digits,(char)digit) != NULL) //Check if the number was already in the square
            return 0;
         char characterVersion = digit + 48;
         strncat(digits,&characterVersion,1);
      }
   }

   //Find sum of first row to compare to
   unsigned int sum = 0;
   for (int col = 0; col < 3; col++)
      sum += square[0][col];

   //Check sums of second and third row
   for (int row = 1; row < 3; row++)
   {
      unsigned int currSum = 0;
      for (int col = 0; col < 3; col++)
         currSum += square[row][col];
      if (currSum != sum)
         return 0;
   } 

   //Check sums of columns
   for (int col = 0; col < 3; col++)
   {
      unsigned int currSum = 0;
      for (int row = 0; row < 3; row++)
         currSum += square[row][col];
      if (currSum != sum)
         return 0;
   }

   //Check diagonals
   unsigned int currSum1 = 0, currSum2 = 0;
   for (int index = 0; index < 3; index++)
   {
      currSum1 += square[index][index];
      currSum2 += square[index][2 - index];
   }
   if (currSum1 != sum || currSum2 != sum)
      return 0;
   
   return 1;
}