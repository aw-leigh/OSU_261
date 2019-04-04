/* CS261- Assignment 1 - Q.2*/
/* Name: Andrew Wilson
 * Date: 4/4/2019
 * Solution description: Implemented as per detailed instructions
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int * temp;
    temp = a;
    a = b;
    b = temp;
    
    /*Decrement the value of integer variable c*/
    --c;
    
    /*Return c*/
    return c;
}

int main(){
    srand(time(0));

    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = (rand() % 11);
    int y = (rand() % 11);
    int z = (rand() % 11);
    
    /*Print the values of x, y and z*/
    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of z is %d\n\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int temp = foo(&x, &y, z);
    
    /*Print the values of x, y and z*/
    printf("After foo, the value of x is %d\n", x);
    printf("After foo, the value of y is %d\n", y);
    printf("After foo, the value of z is %d\n", z);
    
    /*Print the value returned by foo*/
    printf("The value returned by foo is %d\n", temp);
 
    
    return 0;
}
    
    

/* 
a. Is the return value different than the value of integer z? Why or why not?
    Yes, because C uses pass by copy. 
    The value of z is copied into c, which is modified and returned from the function.
    The value of z outside the function is not changed.

b. Are the values of integers x and y different before and after calling the
function foo(..)? Why or why not?
    No, the function receives copies of the pointers, so any modifications to the copies
    disapper when the function returns to main. If you wanted to swap a and b, you would
    need to swap the deferenced values within the function.

*/
