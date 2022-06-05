#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal_tri(int n)
{
    vector<vector<int>> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j <= i - 1; j++)
        {
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans;
    ans = pascal_tri(n);
    for (auto row : ans)
    {
        for (int e : row)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}