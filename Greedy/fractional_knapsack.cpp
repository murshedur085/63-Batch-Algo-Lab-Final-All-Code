#include <bits/stdc++.h>

using namespace std;

struct knap
{
    int object;
    double pbw;
};

bool comparepbw(knap n1, knap n2)
{

    if (n1.pbw > n2.pbw)
        return true;
    else
        return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int profit[n];
    int weight[n];
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    knap sack[n];
    for (int i = 0; i < n; i++)
    {

        sack[i].object = i;
        sack[i].pbw = double(profit[i]) / double(weight[i]);
    }

    sort(sack, sack + n, comparepbw);

    int rw = m;
    double x[n];
    memset(x, 0.0, sizeof(x)); // sob lola array valu gola ke 0 korbe
    int i = 0;
    while (rw > 0)
    {

        if (rw >= weight[sack[i].object])
        {

            x[sack[i].object] = 1;
            rw = rw - weight[sack[i].object];
            i++;
        }
        else
        {
            x[sack[i].object] = double(rw) / double(weight[sack[i].object]);
            rw = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {

        cout << x[i] << " ";
    }

    double maxprofit = 0;
    for (int i = 0; i < n; i++)
    {

        maxprofit = maxprofit + (x[i] * double(profit[i]));
    }
    cout << endl
        << maxprofit << endl;

    return 0;
}
