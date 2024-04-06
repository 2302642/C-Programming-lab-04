/*! used to check
@file       the name of source file is q.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 4
@date       file created on 22/09/2023
@brief      provide a brief explanation about what this source file does:
            This file is the function contains the definition of a function called go to execute the lines of code in go function

            int the function go function break_down(int cents) is called break_down(int cents) function expects a input of int type value 
            this function is used to break_down the total_cents into denomination of (10000, 5000, 1000, 500, 200, 100, 50, 20, 10, 5, 1) where all values are in cents form

            the break_down(int cents) function calles function print_line(int index, double denomination,int rest) this function is used print the lines of 
            index, denominations and rest.  
_____________________________________________________________________________________________________________________________________________________________________________________________*/
/*
    You should document [not necessary for grading but an excellent habit
    to acquire] your implementation of function tile to aid
    in debugging and maintenance not only by yourself but by others in
    your software development team ...

    Remember, the function-level documentation header in q.h is primarily
    meant for your clients. The documentation header here is primarily for
    use by you [and other on your team] solely to aid maintenance and
    debugging tasks ...

    @todo: Provide the definition of function go that
    matches the declaration in q.h ...
    Add documentation [for yourself and not for grading] for function dispense_change ...

   @todo: Provide the definition of function dispense_change that
    matches the declaration in q.h ...
*/

#include <stdio.h>
#include <stdbool.h>
#include "q.h"

void print_line(int index, double denomination,int rest){                                      // function used to print the lines of index, denominations and rest.
    printf("| %-3.d|%13.2f |%6.1d |\n", index, denomination, rest);
}

void break_down(int cents){                                                                    // function used to break_down the total_cents into denomination and calculate how much of each break_down the total_cents into denominations there are

    double Denomination[11] = {100.00, 50.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.20, 0.10, 0.05, 0.01};
    int rest = 0;
    //printf("\n");                                                                                                                     // can use this 
    //for (int a=0; a<30; a++){if (a==0 ||a==5 || a==20 || a==28){printf("+");}else if(a == 29){printf("\n");}else{printf("-");}}       // and this lines together or
    printf("\n+----+--------------+-------+\n");                                                                                        // this line    -but-     both will show the same.
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");
    for(int i=0; i < 11; i++){                                                                  //function used to run though the array of value in array denomination
        rest = cents/(int) (Denomination[i]*100);                                               //calculating number denomination there are in cents
        print_line(i+1, Denomination[i], rest);
        cents -= (int)(Denomination[i]*100*rest);                                               //cents = cents - (denomination * number denomination)
    }
    printf("+----+--------------+-------+\n");

    } 

void go(void){
    bool val = true, in = true, i = false, max_limit=false;                                        // defining bool values
    int dollars = 0, cents = 0,cents_10 = 0, cents_01 = 0/*, e_cents = 0*/, total_cents=0, dot = 0; // defining int values

    printf("Please enter total value:\n");
    while (val == true){

        if(in == false){                                                                        // to enter in the if statement for then second time

            //works when cents range of 0 to 99 and doesnt work when cents inputed is 0.0 or 0. 0 or 0.-10 or 0.0-1
            if ((cents_10 >= 48  && cents_10 <= 57) && (cents_01 >= 48  && cents_01 <= 57))       //we also use this-> if(cents_10 != 10 && cents_01 != 10) insted the if statement currently being used
            {  
                total_cents = dollars*100 + cents;
                if(total_cents <= -1){max_limit = true; val = false; break;}                      //if entered amount is more then 21474835.99 the programe will end
                else{break_down(total_cents);}
            }
            else{val = false; break;}
        }
        else if(in == true){in = false;}
        else{val = false; break;}

        dollars = -1;                                                                           //setting dollars to default valur of -1 so that if .00 is entered the program will end

        //if(i !=false){printf("Please enter total value: ");}else{i = true;}                   // this is the original way of if statement below is Conditional Operator: Syntax version
        i !=false ? printf("Please enter total value: ") : (i = true);                          //prints all in printf when loop is running for the second time
        scanf("%d", &dollars);                                                                  //recives all values of int type before "."
        if (dollars < 0){break;}                                                                //stop if dollars is negative value
        dot = getchar();                                                                        //recives "." as char 
        if (dot != 46){break;}                                                                  //stop if there is no decimal (integer 46 represents "." based on ascii table)(so the program ends when it does not detects a ".")
        cents_10 = getchar();                                                                   //recives first value after "." as char
        if (cents_10 == 10){break;}                                                             //stop if there is no input for first value after "." (integer 10 represents "\n" based on ascii table)(so the program ends when it detects a newline which is ("\n"))
        cents_01 = getchar();
        
        //e_cents = getchar();                                                                    //recives third value after "." as char
        //if (cents_10 != 10 && cents_01 != 10 && e_cents != 10){val = false; break;}              //stop if there is no input for third value after "." (integer 10 represents "\n" based on ascii table)(so the program ends when it detects a newline which is ("\n"))
        // e_cents is causing issus when taking input values from loop-input.txt file the e_cents is only used to check there is no input for third value after ".

        cents = (cents_10-'0')*10 +(cents_01-'0');
        //printf("\n\n\td) %d, dot)%c, cents_10)%d, cents_01)%d, e_cents)%d cents)%d\n",dollars,dot,(cents_10-'0'),(cents_01-'0'),(e_cents-'0'),cents);            //line used to prirnt out the inputs accordingly
    }
    if (max_limit == true) {printf("amount entered is too large please try again later\n");}
    else{printf("You did not type in the correct format in terms of dollars and cents.\n");}          //default statement to print when leving loop due to input not being inputted in the correct form
}
/*workking test cases:
0.0         //program ends [works]
.00         //program ends [works]
0.          //program ends [works]
1           //program ends [works]
-1          //program ends [works]
-1.         //program ends [works]
-1.0        //program ends [works]
-1.00       //program ends [works]

0.00        //program continues with loops [works]
1.23        //program continues with loops [works]
12.23       //program continues with loops [works]
123.45      //program continues with loops [works]
999.99      //program continues with loops [works]
*/
