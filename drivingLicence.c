/*
 Program Description:
    This program handles a structure in which we have information needed for a driving licence, eg. first name, surname, etc.
    It allows to input data from standard output, what is handeled by a seperate function, and to display the information 
    entered, what is possible thanks to another function.

 Author:
    Wiktoria Uramowska

 Date:
    10/04/2018

 Compiled with Xcode
*/
#include <stdio.h>


//Structure templates
struct date
{
    int day;
    int month;
    int year;
};

struct dr_licence
{
    char firstname[15];
    char surname[21];
    struct date DOB;
    int height;
    char eye_colour[8];
    int weight;
};

//Function Prototype
void input_data(struct dr_licence*);
void display_data(struct dr_licence);

int main()
{
    struct dr_licence driver1;
    struct dr_licence driver2;
    
    //calling the first function which allows to enter driving licence data
    //has to be called seperated for each driver
    printf("Please enter data for first driver:\n");
    input_data(&driver1);
    printf("Please enter data for second driver:\n");
    input_data(&driver2);
    
    //calling the second function that allows to display entered driving licence information
    //called seperately for each driver
    printf("Driving licence information for first driver are as follow:\n");
    display_data(driver1);
    printf("Driving licence information for second driver are as follow:\n");
    display_data(driver2);
    
    return 0;
    
}//end main()

//implementing a function input_data()
//this function is responsible for inputing the data into the licence
//eg. first name, surname, etc. of the driver
void input_data(struct dr_licence *ptr)
{
    
    printf("Please enter first name:\n");
    scanf("%s", ptr->firstname);
    
    printf("Please enter surname:\n");
    scanf("%s", ptr->surname);
    
    printf("Please enter day of birth:\n");
    scanf("%d", &(ptr->DOB.day));
    
    printf("Please enter month of birth:\n");
    scanf("%d", &(ptr->DOB.month));
    
    printf("Please enter year birth:\n");
    scanf("%d", &(ptr->DOB.year));
    
    printf("Please enter height:\n");
    scanf("%d", &(ptr->height));
    
    printf("Please enter eye colour:\n");
    scanf("%s", ptr->eye_colour);
    
    printf("Please enter weight (in kg):\n");
    scanf("%d\n", &(ptr->weight));
    
}//end input_data()

//implementing function void display_data()
//it is responsible for displaying driving licence information, entered before
//like first name, surname, etc.
void display_data(struct dr_licence driver)
{
    printf("First name is: %s\n", driver.firstname);
    printf("Surname is: %s\n", driver.surname);
    printf("Date of birth is: %d/%d/%d\n", driver.DOB.day, driver.DOB.month, driver.DOB.year);
    printf("Height is: %d\n", driver.height);
    printf("Eye colour is: %s\n", driver.eye_colour);
    printf("Weight (in kg) is: %d\n\n", driver.weight);
}//end disply_data()