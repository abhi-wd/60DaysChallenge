#include <bits/stdc++.h>
using namespace std;

void permu(int index, string &s, vector<string> &ans)
{
    if (index == s.size())
    {
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        swap(s[i], s[index]);
        permu(index + 1, s, ans);
        swap(s[i], s[index]);
    }
}

void nextPermutation(vector<int> nums)
{
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
            break;
    }
    if (k < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
                break;
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans;

    permu(0, s, ans);
    for (auto st : ans)
    {
        cout << st << " ";
    }
    return 0;
}