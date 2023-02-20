/****************************************************************/
/*             HoMeWoRk 2            */
/*       */
/****************************************************************/

/* in this program we decide if the number is Kaprekar, Special or both and we calculate the sum of all the members of the invoice series that made by the three digit of the three digit number*/

#include <stdio.h>
#define MAX_NUM 999 /*the maximum triple digit number the user can enter it  */
#define MIN_NUM 100 /*the minimum triple digit number the user can enter it  */

int main()
{
    /*we define variables that are appropriate for the program*/
    int number, test; /*this is the variables for number the user will enter, and test that check if the number is correct*/
    int a, d, n, an, i; /*this is the variables for calculate the sum according to the equation an=a+d*(n-1) the "a" refer to the first element, "d" is the value of the difference between two sequential elements and "n" is the numbers of elements in the series, "an" is the number in a particulr place, i is the place*/
    int sum; /*is for count the successive number in series*/
    int multiple, part1, part2;/*multiple is to multiply the number by itself to facilitate the program, part1 and part2 are to divide a number into two parts */
    
    do{
        /*we asks the user to enter a particular three digit number */
        printf("Enter a triple digit number\n");
        /*we check if the user enter a number and not a something else like charecter*/
        if (scanf("%d", &number)!=1) {
            printf("Wrong input\n");
            return 1;
        }
        /* then we check if the input is correct, if it is greater than the maximum number=999 or less than the minimum number=100 we will print a message to the user that the number should be a three digit and the program will allow the user to type the number again */
        if (number<MIN_NUM || number>MAX_NUM) {
            printf("The number must be a triple digit number\n");
            test=0;
        }
        /*and if the input is correct the progrom will continue*/
        else
        {
            test=1;
        }
    } while(!test); /*if the test is incorrect the while will show again the message to input a three digit number*/
    
    a=number%10; /*the remainder of the nubmer by 10 will give us the unity digit and will save in "a" the first member in the series*/
    d=(number/10)%10; /*first we divide the number by 10 and it will give us the first two digit of the number and then we want the remainder of the number by 10 to give us the second digit and will save in "d"*/
    n=number/100;/*this will give us the hundred's digit and will save in "n" that refers to the number of element in series*/
    
    sum=0;
    for (i=1; i<=n; i++) {
        an=a+d*(i-1); /*we use the equation an=a+d*(n-1), in order to count the numbers in series and every time using for we add the number that we got to sum, from i=1 to i=n we count all the numbers-and another way is to change the number "a" (the first number in the series) using the eguation
            a=a+d;
            sum+=a;
            both methods lead to the same result :) */
        sum+=an;
    }
    printf("The sum of the series is: %d\n", sum);
    
    multiple=number*number; /*the multiple is multiplying the number by itself*/
    part1 = multiple%1000;/*in this progrom the minimum number is 100 and 100*100=10,000- and the maximum number is 999 and 999*999=998,001 therfore, dividing the number in two part will be by operator % by 10,000- he will give us the last three number and the divide will give us the second part */
    part2 = multiple/1000;
    
    if((part1+part2)==number) /*if the sum of the part1 and part2 equals to number the user entered the number is kaprekar else is not*/
    {
        printf("%d is a Kaprekar number\n", number);
    }
    else{
        printf("%d is not a Kaprekar number\n", number);
    }
    
    if(number%(a+d+n)==0) /*if the remainder of the number by sum all of there three digit is 0 as the number is special else is not*/
    {
        printf("%d is a Special number\n", number);
    }
    
    else{
        printf("%d is not a Special number\n", number);
    }
    return 0;
}
/* we recived to the end of the program */
