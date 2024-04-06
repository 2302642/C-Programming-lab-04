// @todo: Add a file documentation header as explained in the specs ...

// @todo: Add necessary C standard library headers here ...

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function tile to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition of function go that
// matches the declaration in q.h ...


// Add documentation [for yourself and not for grading] for function dispense_change ...

// @todo: Provide the definition of function dispense_change that
// matches the declaration in q.h ...

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "q.h"

void print_line(int index, double denomination,int rest ){
    //@todo later: do implementation and remove the next lines -
    printf("| %-3.d|       %6.2f | %5.1d |\n", index, denomination, rest); 

}

void break_down(int cents){
    //@todo later: do implementation and remove the next lines -

    double Denomination[11] = {100.00, 50.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.20, 0.10, 0.05, 0.01};
    int rest = 0;
    printf("\n+----+--------------+-------+\n");
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");
    
    for(int i=0; i <11; i++){

        //printf("\n\n\tcents = %d\n", cents);
        rest = cents/(int) (Denomination[i]*100);
        //printf("\trest = %d\n", rest);
        print_line(i+1, Denomination[i], rest);
        cents -= (int)(Denomination[i]*100*rest);
        //printf("\tcents = %d\n\n", cents);
    }
    
    printf("+----+--------------+-------+\n");

    } 

void go(void){
    // @todo later: do implementation and remove the next lines -
    int dollars, cents, total_cents=0;
    bool val = true;
    printf("Please enter total value:\n");
        scanf("%d.%d", &dollars, &cents);

    while (val == true){

        if (cents >=0 && cents<=99 && dollars !=-1){                                     //When the user inputs a negative dollar part, the program must shows error message
            
            double x = floor(log10(cents))+1;

            if (x==2|| cents == 0 ){                                                //if the user does not enter the input as required, for example if the user inputs only the 
                total_cents = dollars*100 + cents;                                   //dollar part and the period without two digits for the cents part right after the decimal point,
                break_down(total_cents);                                            //the program shows an error message
            }
            else{val = false; break;}
        }
        else{val = false; break;}

        printf("Please enter total value: ");
        scanf("%d.%d", &dollars, &cents);
    }
}
 printf("You did not type in the correct format in terms of dollars and cents.\n");

/*
work when 1.10 
not when 1.09

when 1.9 not work good
when -1 not work good
when 0.-10 not work good

*/
