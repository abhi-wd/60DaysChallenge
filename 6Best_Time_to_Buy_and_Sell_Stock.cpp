#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int max_pro = 0;
    int mini = INT_MAX;
    for (auto price : prices)
    {
        mini = min(price, mini);
        max_pro = max(max_pro, price - mini);
    }
    return max_pro;
}