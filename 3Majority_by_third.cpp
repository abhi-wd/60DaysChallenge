#include <bits/stdc++.h>
using namespace std;

vector<int> majority_element(vector<int> arr)
{
    int count1 = 0;
    int count2 = 0;
    int ele1 = -1;
    int ele2 = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele1)
            count1++;
        else if (arr[i] == ele2)
            count2++;
        else if (count1 == 0)
        {
            count1 = 1;
            ele1 = arr[i];
        }
        else if (count2 == 0)
        {
            count2 = 1;
            ele2 = arr[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele1)
            count1++;
        else if (arr[i] == ele2)
            count2++;
    }
    if (count1 > arr.size() / 3)
        ans.push_back(ele1);
    if (count2 > arr.size() / 3)
        ans.push_back(ele2);
    return ans;
}

int main()
{

    return 0;
}