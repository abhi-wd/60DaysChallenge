#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    set<int> hashSet;

    for (auto num : nums)
    {
        hashSet.insert(num);
    }
    int longestStreak = 0;
    for (auto num : nums)
    {
        if (!hashSet.count(num - 1))
        {
            int currentStreak = 1;
            int currentNum = num;
            while (hashSet.count(currentNum + 1))
            {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}

int main()
{

    return 0;
}