#include <bits/stdc++.h>
using namespace std;

vector<int> missing_repeat(vector<int> &a)
{
    long long n = a.size();
    long long s = (n * (n + 1)) / 2;
    long long p = (n * (n + 1) * (2 * n + 1)) / 6;
    long long missing = 0, repeat = 0;
    for (int i = 0; i < n; i++)
    {
        s -= (long long)a[i];
        p -= (long long)a[i] * (long long)a[i];
    }

    missing = (s + p / s) / 2;
    repeat = missing - s;

    vector<int> ans;
    ans.push_back(repeat);
    ans.push_back(missing);
    return ans;
}

int main()
{

    return 0;
}