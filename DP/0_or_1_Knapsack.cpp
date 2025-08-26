#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int profit[n];
    int weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int sack[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
    {
        sack[i][0] = 0;
    }
    for (int j = 0; j < m + 1; j++)
    {
        sack[0][j] = 0;
    }
    for (int i = 1; i < n + 1; i++) // product
    {

        for (int j = 1; j < m + 1; j++) // bagur weight
        {
            if (weight[i - 1] > j)
            {

                sack[i][j] = sack[i - 1][j];
            }
            else
            {
                sack[i][j] = max(sack[i - 1][j], sack[i - 1][j - weight[i - 1]] + profit[i - 1]);
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {

        for (int j = 0; j < m + 1; j++)
        {

            cout << sack[i][j] << " ";
        }
        cout << endl;
    }

    cout << sack[n][m] << endl;

    int i = n, j = m;
    while (i > 0)
    {
        if (sack[i][j] == sack[i - 1][j])
        {

            i--;
            continue;
        }
        else
        {
            cout << "Object " << i << " is selecteds" << endl;
            j = j - weight[i - 1];
            // 8 = 8-weight[4-1 = 3] // 8= 8-5 // 8 = 3 // 3 number selected
            i--;
        }
    }

    return 0;
}
