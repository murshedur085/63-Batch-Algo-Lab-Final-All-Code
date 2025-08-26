#include <bits/stdc++.h>
using namespace std;

void merging(int st, int end, int mid, int arr3[])
{
    int m = mid - st + 1;
    int n = end - mid;
    int arr[m], arr2[n];
    for (int i = 0; i < m; i++)
    {
        arr[i] = arr3[st + i];
    }
    for (int j = 0; j < n; j++)
    {
        arr2[j] = arr3[mid + 1 + j];
    }
    int i = 0, j = 0, k = st;
    while (i < m && j < n)
    {
        if (arr[i] < arr2[j])
        {
            arr3[k] = arr[i];
            k++;
            i++;
        }
        else
        {

            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    for (; i < m; i++)
    {

        arr3[k] = arr[i];
        k++;
    }
    for (; j < n; j++)
    {

        arr3[k] = arr2[j];
        k++;
    }
}

void mergesort(int st, int end, int arr[])
{
    if (st < end)
    {
        int mid = (st + end) / 2;
        mergesort(st, mid, arr);
        mergesort(mid + 1, end, arr);
        merging(st, end, mid, arr);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergesort(0, n - 1, arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
