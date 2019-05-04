#include <stdio.h>
#include <stdlib.h>


int main(){

    int x = 1;

    if(--x == 0){
        printf("The value of x is %d\n", x);
    }

    printf("The value of x is %d\n", x);


    return 0;
}