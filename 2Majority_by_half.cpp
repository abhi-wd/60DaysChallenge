#include <bits/stdc++.h>
using namespace std;

int majority_element(vector<int> arr)
{
    int count = 1;
    int possible_ans = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == possible_ans)
            count++;
        else
            count--;
        if (count == 0)
        {
            count = 1;
            possible_ans = arr[i];
        }
    }
    count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == possible_ans)
            count++;
    }
    if (count > arr.size() / 2)
        return possible_ans;
}

int main()
{

    return 0;
}