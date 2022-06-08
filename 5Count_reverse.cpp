#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int l, int mid, int h)
{

    int total = 0;
    int j = mid + 1;
    for (int i = l; i <= mid; i++)
    {
        while (j <= h && arr[i] > 2ll * arr[j])
        {
            j++;
        }
        total += (j - (mid + 1));
    }

    int inv_count = 0;
    int l_size = mid - l + 1;
    int r_size = h - mid;
    int l_arr[l_size];
    int r_arr[r_size];

    for (int i = 0; i < l_size; i++)
    {
        l_arr[i] = arr[l + i];
    }
    for (int i = 0; i < r_size; i++)
    {
        r_arr[i] = arr[mid + 1 + i];
    }

    int l_start = 0, r_start = 0, arr_start = l;
    while (l_start < l_size && r_start < r_size)
    {
        if (l_arr[l_start] <= r_arr[r_start])
        {
            arr[arr_start++] = l_arr[l_start];
            l_start++;
        }
        else
        {
            arr[arr_start++] = r_arr[r_start];
            r_start++;
        }
    }
    while (l_start < l_size)
    {
        arr[arr_start] = l_arr[l_start];
        arr_start++;
        l_start++;
    }

    while (r_start < r_size)
    {
        arr[arr_start] = r_arr[r_start];
        arr_start++;
        r_start++;
    }
    return total;
}

int merge_Sort(int arr[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        inv_count += merge_Sort(arr, left, mid);
        // cout << inv_count << endl;
        inv_count += merge_Sort(arr, mid + 1, right);
        // cout << inv_count << endl;

        inv_count += merge(arr, left, mid, right);
        // cout << inv_count << endl;
    }
    return inv_count;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = merge_Sort(arr, 0, n - 1);

    cout << "Total Inversion: " << ans << endl;
    return 0;
}