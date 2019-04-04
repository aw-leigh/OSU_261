/* CS261- Assignment 1 - Q. 0*/
/* Name: Andrew Wilson
 * Date: 4/4/2019
 * Solution description: Implemented as per detailed instructions
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
    printf("In fooA, the value of the integer pointed to by iptr is %d\n", *iptr);
    printf("In fooA, the address of the integer pointed to by iptr is %p\n", iptr);
          
     /*Increment the value of the integer pointed to by iptr by 5*/
     *iptr += 5;
          
     /*Print the address of iptr itself*/
     printf("The address of iptr is %p\n\n", &iptr);


    /*Dummy variable, ignore the warning*/
   int c=5;  
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
    printf("In fooB, the value of the integer pointed to by jptr is %d\n", *jptr);
    printf("In fooB, the address of the integer pointed to by jptr is %p\n", jptr);   

     /*Decrement the address by 1 pointed to by jptr using jptr */
     jptr -= 1;
      
     /*Print the address of jptr itself*/
     printf("The address of jptr is %p\n\n", &jptr);
}


int main(){
    srand(time(0));

    /*Declare an integer x and initialize it randomly to a value in [0,10] */
    int x = (rand() % 11);
        
    /*Print the value and address of x*/
    printf("The value of x is %d\n", x);
    printf("The address of x is %p\n\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*Print the value of x*/
    printf("After calling fooA, the value of x is %d\n\n", x);
    
    /*Call fooB() with the address of x*/
    fooB(&x);

    /*Print the value and address of x*/
    printf("The value of x is %d\n", x);
    printf("The address of x is %p\n\n", &x);
 
    
    return 0;
}


/* Are the value and address of x different than the value and address that were
printed before the call to fooB(..)? Why or why not?

No, because only a copy of x's address is passed to fooB. fooB changes its copy of x's address,
but the copy disappears when the function goes out of scope.

*/