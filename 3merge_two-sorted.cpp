#include <bits/stdc++.h>
using namespace std;

void merge(int ar1[], int n, int ar2[], int m)
{
    int gap = ceil((float)(m + n) / 2);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;

        while (j < (n + m))
        {
            if (j < n && i < n && ar1[i] > ar1[j])
                swap(ar1[i], ar1[j]);
            else if (j >= n && i < n && ar1[i] > ar2[j - n])
                swap(ar1[i], ar2[j - n]);
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n])
                swap(ar2[i - n], ar2[j - n]);
            j++;
            i++;
        }
        // due to ceil function
        if (gap == 1)
            gap = 0;
        else
            gap = ceil((float)gap / 2);
    }
    for (int i = 0; i < m; i++)
    {
        ar1[i + n] = ar2[i];
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 0, 0, 0};
    int arr2[] = {2, 5, 6};

    merge(arr1, 3, arr2, 3);
    cout << "After merge:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}