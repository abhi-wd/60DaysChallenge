#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &num, int target)
{
    sort(num.begin(), num.end());

    vector<vector<int>> ans;
    int n = num.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            int target_2 = target - num[i] - num[j];
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                int two_sum = num[left] + num[right];
                if (two_sum < target_2)
                {
                    left++;
                }
                else if (two_sum > target_2)
                {
                    right--;
                }
                else
                {
                    vector<int> solution(4, 0);
                    solution[0] = num[i];
                    solution[1] = num[j];
                    solution[2] = num[left];
                    solution[3] = num[right];
                    ans.push_back(solution);

                    while (left < right && num[left] == solution[2])
                        ++left;
                    while (left < right && num[right] == solution[3])
                        --right;
                }
            }
            while (j + 1 < n && num[j + 1] == num[j])
                ++j;
        }
        while (i + 1 < n && num[i + 1] == num[i])
            ++i;
    }
    return ans;
}

int main()
{

    vector<int> v = {1, 0, -1, 0, -2, 2};

    vector<vector<int>> sum = fourSum(v, 0);
    cout << "The unique quadruplets are" << endl;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}