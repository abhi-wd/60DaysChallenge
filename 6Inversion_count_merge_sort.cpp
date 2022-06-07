#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long l, long long mid, long long h)
{
    long long inv_count = 0;
    long long l_size = mid - l + 1;
    long long r_size = h - mid;
    long long l_arr[l_size];
    long long r_arr[r_size];

    for (long long i = 0; i < l_size; i++)
    {
        l_arr[i] = arr[l + i];
    }
    for (long long i = 0; i < r_size; i++)
    {
        r_arr[i] = arr[mid + 1 + i];
    }

    long long l_start = 0, r_start = 0, arr_start = l;
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
            inv_count += l_size - l_start;
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
    return inv_count;
}

long long merge_Sort(long long arr[], long long left, long long right)
{
    long long mid, inv_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        inv_count += merge_Sort(arr, left, mid);
        cout << inv_count << endl;
        inv_count += merge_Sort(arr, mid + 1, right);
        cout << inv_count << endl;

        inv_count += merge(arr, left, mid, right);
        cout << inv_count << endl;
    }
    return inv_count;
}

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long ans;
    for (long long x : arr)
    {
        cout << x << ",";
    }
    cout << endl;
    ans = merge_Sort(arr, 0, n - 1);

    for (long long x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Total Inversion: " << ans << endl;
    return 0;
}