#include <bits/stdc++.h>
using namespace std;
double myPow(double a, int n)
{
    long long nn = n;
    double ans = 1.0;
    if (n < 0)
        nn = -1ll * n;
    while (nn > 0)
    {
        if (nn & 1)
        {
            ans = ans * a;
        }
        a = a * a;
        nn >>= 1;
    }
    if (n < 0)
        ans = (double)1.0 / ans;
    return ans;
}

int main()
{

    return 0;
}