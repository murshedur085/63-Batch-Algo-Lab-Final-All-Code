#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;                      // size declare
    cin >> n;                   // size input
    int List[n];                // array declare with that size
    for (int i = 0; i < n; i++) // array input using for loop
    {
        cin >> List[i];
    }
    int LIS[n];
    int parent[n]; 
    for (int i = 0; i < n; i++)
    {
        LIS[i] = 1;
        parent[i] = -1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (List[j] < List[i])
            {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
                parent[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << LIS[i] << " ";
    }
    cout << endl;
    int mx = INT_MIN;
    int lastIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (mx < LIS[i])
        {
            mx = LIS[i];
            lastIndex = i;
        }
    }
    cout << "LIS Length = " << mx << endl;

    int sequence[mx];
    int k = mx - 1;
    while (lastIndex != -1)
    {
        sequence[k--] = List[lastIndex];
        lastIndex = parent[lastIndex];
    }
    cout << "LIS Values: ";
    for (int i = 0; i < mx; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;
}
