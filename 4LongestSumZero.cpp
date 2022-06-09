#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    int sum = 0;
    int maxi = 0;
    unordered_map<int, int> hshMap;

    for (int i = 0; i < A.size(); i++)
    {
        int sum += A[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (hshMap.find(sum) != hshMap.end())
            {
                maxi = max(maxi, i - hshMap[sum]);
            }
            else
                hshMap[sum] = i;
        }
    }
    return maxi;
}

int main()
{

    return 0;
}