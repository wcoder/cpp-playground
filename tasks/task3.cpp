#include <iostream>  /* cin */
#include <stdio.h>   /* printf */

using namespace std;

int main()
{
    int b,a1,a,b1,n,i,j,s=0,mn=0;
    long p=1;

    cin >> a1 >> b1 >> n;

    a=max(a1,b1);
    b=min(a1,b1);

    long cur=0;

    for (i=0; i <= n; i+=a)
    {
        for (j=0; j <= n; j+=b)
        {
            if (i+j == n)
            {
                if (i!=0) {
                    for (int h=1; h <= i/a; h++) { p *= a; }
                }
                if (j!=0) {
                    for (int h=1; h <= j/b; h++) { p *= b; }
                }
                if (p > cur) {
                    cur=p;
                    mn=1;
                }
                p=1;
            }
        }
    }

    if (mn == 1) cout << cur;
    else cout << 0;

    return 0;
}

