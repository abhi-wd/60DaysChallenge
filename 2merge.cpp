#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() < 2)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> temp = intervals[0];
    for (auto it : intervals)
    {
        if (it[0] <= temp[1])
        {
            temp[1] = max(temp[1], it[1]);
        }
        else
        {
            ans.push_back(temp);
            temp = it;
        }
    }
    ans.push_back(temp);
    return ans;
}
vector<vector<int>> merge2(vector<vector<int>> &intervals)
{
    if (intervals.size() < 2)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            vector<int> v = {intervals[i][0], intervals[i][1]};
            ans.push_back(v);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr;
    arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}, {15, 18}, {16, 17}};
    vector<vector<int>> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
    return 0;
}