#include <iostream>  /* cin */
#include <stdio.h>   /* printf */

using namespace std;

int main()
{
    int n;
    double d, s=0.0, m;

    cin >> n >> m;

    for (int i=0; i < n; i++) {
        cin >> d;
        s += 1./d;
    }

    long double ss = m/s;

    printf("%.3Lf\n", ss);

    return 0;
}

