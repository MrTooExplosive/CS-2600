#include <stdio.h>
#include <limits.h>
#include <time.h>

void playGame(int max);

int main()
{
   short choice;
   unsigned int maximum ;
   time_t t;
   srand((unsigned) (time)&t);


   //Read in saved maximum
   FILE *maxFile = fopen("maximum.txt", "r");
   if (maxFile != NULL)
      fscanf(maxFile, "%u", &maximum);
   else
      maximum = 10;
   fclose(maxFile);
   
   do 
   {
      //Create menu
      printf("\n\nPress 1 to play a game.");
      printf("\nPress 2 to change the max number.");
      printf("\nPres 3 to quit.");

      //Choose option
      printf("\nEnter your choice: ");
      scanf("%d", &choice);
      if (choice == 1)
         playGame(maximum);
      else if (choice == 2)
      {
         printf("Enter the maximum value to for the game (must be under %u and greater than 0): ", UINT_MAX - 1);
         scanf("%u", &maximum);
      }
   } while (choice != 3);

   //Save current maximum
   maxFile = fopen("maximum.txt", "w");
   fprintf(maxFile, "%u", maximum);
   fclose(maxFile);

   printf("\nThank you for playing!");
   return 0;
}

void playGame(int max)
{
   //Choose goal number
   const unsigned int ans = rand() % max + 1;
   unsigned int guess;

   printf("\nEnter your first guess: ");
   scanf("%u", &guess);

   do
   {
      if (guess > ans)
      {
         printf("\nYour guess is too high!");
         printf("\nEnter another guess: ");
         scanf("%u", &guess);
      }
      else if (guess < ans)
      {
         printf("\nYour guess it too low!");
         printf("\nEnter another guess: ");
         scanf("%u", &guess);
      }
   } while (guess != ans);

   printf("\nCongratulations! You won!");

}