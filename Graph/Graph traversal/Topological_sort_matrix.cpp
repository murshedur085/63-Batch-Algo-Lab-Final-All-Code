#include <bits/stdc++.h>
using namespace std;
int graph[1001][1001];
int visit[1001];
int n, e; // ai gola auto 0 hbe

vector<int> ans; // time complx(verte + edge)

void DFS(int start)
{

    visit[start] = 1;
    for (int j = 1; j <= n; j++)
    {

        if (visit[j] == 0 && graph[start][j] != 0)
        {
            visit[j] = 1;
            DFS(j);
        }
    }
    ans.push_back(start);
}
int main()
{
    cin >> n >> e;
    int u, v;
    for (int i = 1; i <= e; i++)
    {

        cin >> u >> v;
        graph[u][v] = 1;
    }

    for (int i = 1; i <= n; i++)
    {

        if (visit[i] == 0) // only unvisit node jon loop colbe
        {

            DFS(i);
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
