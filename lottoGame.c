/*
Program description:
    This program allows the user to play a Lotto game. They can enter their selected 6 numbers, sort them in an increasing order, 
	display them on the screen, compare with the winning numbers. Pionter notation is used in the program, so are the functions.

Author:
    Wiktoria Uramowska

Date: 
    07/03/2018
*/

#include <stdio.h>
#define SIZE 6
#define RANGE 42

//Prototype
int enter_numbers();
int your_numbers();
int sort_numbers();
int check_numbers();
void exit_option(char*);

int main()
{
    int my_numbers[SIZE];
    int option;
    int winning_numbers[SIZE] = {1,3,5,7,9,11};
    int bonus = 42;
    int i;
    char answer;
    int counter;
    counter = 0;
    
    
    //do while loop to control the menu display
    do
    {
        printf("Welcome to the Lotto game!\n\n");
        printf("   $$$$$$$$$$$$$$\n");
        printf("    $          $\n");
        printf("     $        $\n");
        printf("      $$$$$$$$\n");
        printf("     $   $ $  $\n");
        printf("    $   $$$$$  $\n");
        printf("   $   $ $ $    $\n");
        printf("  $     $$$$$    $\n");
        printf(" $       $ $ $    $\n");
        printf("$       $$$$$      $\n");
        printf("$        $ $       $\n");
        printf("$                  $\n");
        printf(" $$$$$$$$$$$$$$$$$$\n\n");
        printf("Please choose one of the options available:\n");
        printf("1. Enter your selected numbers\n");
        printf("2. Display your numbers\n");
        printf("3. Sort your numbers in increasing order\n");
        printf("4. Compare your numbers with winning numbers\n");
        printf("5. Exit the program\n");
        scanf("%d", &option);
        
        //switch statement controls all of the menu options
        //options 2, 3, 4, 5 not available before option 1
        switch(option)
        {
            case 1:
            {
                //calling the function responsible for entering the numbers
                enter_numbers(my_numbers);
                //increas the counter so options 2, 3, 4, 5 become available
                counter++;
                
                break;
            }//end case 1
            case 2:
            {
                //before choosing this option the user has to enter his/her 6 numbers
                //the if statement checks if the counter is greater than 0
                //it is increased after each time, when the user enters new set of numbers
                if (counter == 0)
                {
                    printf("Option not avialable yet, enter your numbers first!\n");
                }//end if
                else
                {
                    //calling the function responsible for displaying users numbers
                    your_numbers(my_numbers);
                }//end else
                
                break;
                
            }//end case 2
                
            case 3:
            {
                //before choosing this option the user has to enter his/her 6 numbers
                //the if statement checks if the counter is greater than 0
                //it is increased after each time, when the user enters new set of numbers
                if (counter == 0)
                {
                    printf("Option not avialable yet, enter your numbers first!\n");
                }//end if
                else
                {
                    //calling function that sorts the numbers in increasing order
                    sort_numbers(my_numbers);
                }//end else
                
                break;
                
            }//end case 3
                
            case 4:
            {
                //before choosing this option the user has to enter his/her 6 numbers
                //the if statement checks if the counter is greater than 0
                //it is increased after each time, when the user enters new set of numbers
                if (counter == 0)
                {
                    printf("Option not avialable yet, enter your numbers first!\n");
                }//end if
                else
                {
                    
                    printf("The winning numbers for today are:\n");
                    for(i = 0; i < SIZE; i++)
                    {
                        if(i != (SIZE - 1))
                        {
                            printf("%d,", *(winning_numbers + i));
                        }//end if
                        else
                        {
                            printf("%d\n", *(winning_numbers + i));
                        }//end else
                        
                    }//end for
                
                check_numbers(my_numbers, winning_numbers, bonus);
                    
                }//end outter else
                
                break;
            }//end case 4
            
            case 5:
            {
                //calling the exit function
                exit_option(&answer);
                
                break;
    
            }//end case 5
            default:
            {
                printf("Wrong input, try again!\n");
                
            }//end default
        }//end switch
        
    }//end do
    while(option != 5);
    printf("Thank you for playing the Lotto game!\n");
    
    getchar();
    
    return 0;
}//end main()

//implementing the function responsible for user entering the six numbers
//which allow to take part in the Lotto game
int enter_numbers(int my_numbers[])
{
    int i, j;
    
    i = 0;
    j = 0;
    
    printf ("Please enter your 6 numbers:\n");
    while (i < SIZE)
    {
        
        //check if the entered numbers is in the range from 1 to 42 inclusive
        do
        {
            scanf ("%d", &*(my_numbers + i));
            
            if ((*(my_numbers + i) < 1) || (*(my_numbers + i) > RANGE))
            {
                
                printf("Incorrect input. Please enter a number between 1 and 42.\n");
                
                
            }//end if
            
        }
        while ((*(my_numbers + i) < 1) || (*(my_numbers + i) > (RANGE + 1)) );
        
        //the index has to be increased to avoid an infinite loop
        //without it, the program would not stop after entering 6 numbers
        i++;
        
        //for loop that checks if the number is repeated in the array
        //starting from the second element as the first one can't be compared with anything
        for ( j = 0; j < (i-1); j++)
        {
            if (*(my_numbers + (i-1)) == *(my_numbers + j))
            {
                //if the number is already inside the index should not increase
                i--;
                
                printf("You choose this number already, please enter a different one!\n");
                
                break;
            }//end if
            
        }//end for
        
    }//end while
    
    return my_numbers[SIZE];
    
}//end enter_numbers()

//implementing the function that alllows the user to display chosen numbers on the screen, in one line
int your_numbers(int my_numbers[])
{
    int i;
    
    printf("Your numbers are:\n");
    for(i = 0; i <SIZE; i++)
    {
        //that if condition allows to control the output, meaning the coma will not display after the last number
        if( i != (SIZE - 1))
        {
            printf("%d,", *(my_numbers +i));
        }//end if
        else
        {
            printf("%d\n", *(my_numbers + i));
        }//end else
    }//end for
    
    return 0;
    
}//end your_numbers()

//function that uses bubble sort algorithm to sort the inputed numbers
int sort_numbers(int my_numbers[])
{
    int i, j, temp;
    
    //using bubble sort to put the numbers in increasing order
    for(i = 0; i < (SIZE - 1); i++)
    {
        for(j = 0; j < (SIZE - 1); j++)
        {
            if(my_numbers[j] > my_numbers[j +1])
            {
                temp = my_numbers[j];
                my_numbers[j] = my_numbers[j + 1];
                my_numbers[j + 1] = temp;
            }//end if
            
        }//end inner for
        
    }//end outter for
    
    return 0;
    
}//end sort_numbers()

//implementing the functions that compares the entered numbers with winning set
//it also displays the message if the user won, and if, what
int check_numbers(int my_numbers[], int winning_numbers[], int bonus)
{
    int i, j, counter, my_bonus;
    counter = 0;
    
    //two for loops checking element by element if the numbers are the same in both sets
    for( i = 0; i <SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
        {
            
            if(*(my_numbers + i) != *(winning_numbers + j))
            {
                
                continue;
                
            }//end if
            
            else
            {
            
                counter++;
                
            }//end else
            
        }//end inner for
        
    }//end outter for
    
    //switch statement controls the display of the results, if won or not and what
    switch (counter)
    {
        case 0:
        case 1:
        case 2:
        {
            if( my_bonus == bonus)
            {
                my_bonus = 1;
            }//end if
            
            printf("You matched %d numbers\n", counter);
            if( my_bonus == 1)
            {
                printf("and a bonus number.\n");
            }//end if
            
            printf("Sorry, no prize won. Try again.\n");
            
            break;
            
        }//end cases 0,1,2
            
        case 3:
        {
            if( my_bonus == bonus)
            {
                my_bonus = 1;
            }//end if
            
            printf("You matched %d numbers\n", counter);
            if( my_bonus == 1)
            {
                printf("and a bonus number.\n");
                printf("Congratulations! You won a Cinema ticket!\n");
            }//end if
            
            printf("Sorry, no prize won. Try again.\n");
            
            break;
            
        }//end case 3
            
        case 4:
        {
            if( my_bonus == bonus)
            {
                my_bonus = 1;
            }//end if
            
            printf("You matched %d numbers\n", counter);
            if( my_bonus == 1)
            {
                printf("and a bonus number.\n");
                printf("Congratulations! You won a Weekend away!\n");
            }//end if
            
            printf("Congratulations! You won a Night out!\n");
            
            break;
            
        }//end case 4
            
        case 5:
        {
            if( my_bonus == bonus)
            {
                my_bonus = 1;
            }//end if
            
            printf("You matched %d numbers\n", counter);
            if( my_bonus == 1)
            {
                printf("and a bonus number.\n");
                printf("Congratulations! You won a New car!\n");
            }//end if
            
            printf("Congratulations! You won a Holiday!\n");
            
            break;
            
        }//end case 5
            
        case 6:
        {
            printf("You matched %d numbers\n", counter);
            printf("Congratulations! You won a Jackpot!\n");
            
            break;
            
        }//end case 6
            
        default:
        {
            break;
        }
    }
    
    return 0;
    
}//end check_numbers()


//function that allows user to exit the game
void exit_option(char *answer)
{

    printf("Are you sure you want to exit program? y/n\n");
    
    do
    {
        
        scanf("%1s", &*answer);
        
        if ((*answer != 'y') && (*answer !='n') && (*answer != 'Y') && (*answer != 'N'))
        {
            printf("Please enter a good value\n");
        }//end if
        
    }
    while ((*answer != 'n') && ( *answer !='y') && (*answer != 'Y') && (*answer != 'N'));
    
    
    
}//end exit_option()
