#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   //Create needed variables
   double taxPercent, tipPercent;
   
   //Create menu
   const float mealPrices[] = {9.95, 4.55, 13.25, 22.35}; 
   const char* mealNames[] = {"salad", "soup", "sandwich", "pizza"};

   //Choose meal randomly
   time_t t;
   srand((unsigned) time(&t));
   const int meal = rand() % 4;

   //Ask for information
   printf("Enter the percent to tax: ");
   scanf("%lf", &taxPercent);
   printf("Enter the percent to tip: ");
   scanf("%lf", &tipPercent);

   //Calculate prices
   const float mealPrice = mealPrices[meal];
   const float tip = mealPrice * tipPercent / 100;
   const float tax = mealPrice * taxPercent / 100;
   const float total = mealPrice + tip + tax;

   //Output final information
   printf("\nFor a meal of %s, the bill is as follows.", mealNames[meal]);
   printf("\nMeal Cost:\t$%.2f", mealPrice);
   printf("\nTax Amount:\t$%.2f", tax);
   printf("\nTip Amount:\t$%.2f", tip);
   printf("\nTotal Cost:\t$%.2f", total);
   return 0;
}