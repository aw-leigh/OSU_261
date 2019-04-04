#include <stdio.h>
#include <math.h>


int main (int argc, const char * argv[])
{
    double a = 5;
    double b = 6;
    double c = 7;
    double s = (a + b + c) / 2;
    double result;

    result = sqrt(s * (s - a) * (s - b) * (s - c));

    printf("The area is %g\n", result);

    return 0;
}