#include <bits/stdc++.h>
using namespace std;

int fib(int n, int f[])
{
    if (n <= 1) // 0,1asle aikne dokbe
    {
        f[n] = n;
        return f[n];
    }
    if (f[n] == -1)
    {
        f[n] = fib(n - 1, f) + fib(n - 2, f);
    }
    return f[n];
}

int main()
{

    int n;
    cin >> n;
    int f[n + 1];
    memset(f, -1, sizeof(f));

    int ans = fib(n, f);

    cout << ans << endl;

    return 0;
}
