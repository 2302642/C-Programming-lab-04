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
    bool val = true, in = true;
    int dollars = 0, cents = 0,cents10 = 0, cents1 = 0, total_cents=0, dot = 0, i = 0;

    while (val == true){
        

        if( dollars >= 0 && in == false){                                                         // works when dollars is not negative and if dollars entered is not ".00" 

            printf("\n\n\td) %d, dot)%d, cents10)%d, cents1)%d, cents)%d\n",dollars,dot,(cents10-'0'),(cents1-'0'),cents);

            if (cents >=0 && cents<=99 && dot == 46 && (cents10-'0') != -38 && (cents1-'0') != -38)         //works when cents range of 0 to 99 and doesnt work when cents inputed is 0.0
            {   
                total_cents = dollars*100 + cents;
                break_down(total_cents);
                
            }
            else{val = false; break;}
        }
        else if(in == true){in = false;}
        else{val = false;break;}


        printf("Please enter total value: ");
        if(i==0){printf("\n");i++;}
        scanf("%d", &dollars);
        dot = getchar();
        cents10 = getchar();
        cents1 = getchar();
        cents = (cents10-'0')*10 +(cents1-'0');
        //printf("\n\n\td) %d, dot)%c, cents10)%d, cents1)%d, cents)%d\n",dollars,dot,(cents10-'0'),(cents1-'0'),cents);
    }

    printf("You did not type in the correct format in terms of dollars and cents.\n");
}

/*workking test cases:

0.0         //program ends
.00         //program ends[issue]
0.          //program ends[issue]
-1          //program ends
-1.         //program ends
-1.0        //program ends
-1.00       //program ends


0.00        //program works
1.23        //program works
12.23       //program works
123.45      //program works
999.99      //program works


*/

