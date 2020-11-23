#include <iostream>  /* cin */
#include <stdio.h>   /* printf */
#include <math.h>    /* pow */

using namespace std;

int main()
{
    int i,d;
    double res[150],a;

    cin>>d;

    for (i=0; i<d; i++)
    {
        cin >> a;
        res[i] = pow(a, 4.0) * 1 + pow(a, 3.0) * 1.2 + pow(a,2.0) * (-20) + 123.456;
    }

    for (i=0; i<d; i++)
    {
        printf("%.3f\n", res[i]);
    }

    return 0;
}

