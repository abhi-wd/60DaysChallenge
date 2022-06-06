#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void display(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void reverse_row(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        int j = 0, k = cols - 1;
        while (j < k)
        {
            swap(matrix[i][j], matrix[i][k]);
            j++;
            k--;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    display(matrix);
    transpose(matrix);
    cout << "Transpose" << endl;
    display(matrix);
    reverse_row(matrix);
    cout << "Reverse" << endl;
    display(matrix);

    return 0;
}