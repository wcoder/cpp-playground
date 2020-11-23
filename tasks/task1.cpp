#include <iostream>  /* cin */
#include <stdio.h>   /* printf */
#include <math.h>    /* pow */

using namespace std;

int main()
{
    int i, d;
    double res[150], x;

    cin >> d;

    for (i=0; i < d; i++)
    {
        cin >> x;
        res[i] = pow(x, 4.0) * 1     // A
               + pow(x, 3.0) * 1.2   // B
               + pow(x, 2.0) * (-20) // C
               + pow(x, 1.0) * 0     // D
               + 123.456;            // E
    }

    for (i=0; i < d; i++)
    {
        printf("%.3f\n", res[i]);
    }

    return 0;
}

