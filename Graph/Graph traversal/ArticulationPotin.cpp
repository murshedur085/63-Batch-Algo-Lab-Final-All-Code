#include <bits/stdc++.h>
using namespace std;
int graph[1001][1001];
int visit[1001];
int dis[1001], low[1001];
bool isAP[1001];
int timer = 0;
int n, e;
/*
6 7
1 4
1 2
4 3
2 3
3 5
3 6
5 6
*/
void DFS(int u, int parent)
{
    visit[u] = 1;
    dis[u] = low[u] = ++timer;

    int child = 0;
    for (int j = 1; j <= n; j++)
    {
        if (visit[j] == 0 && graph[u][j] != 0)
        {
            child++;
            DFS(j, u);

            low[u] = min(low[u], low[j]);

            if (parent != -1 && dis[u] <= low[j])
            {
                isAP[u] = true;
            }
        }

        else if (j != parent && graph[u][j] != 0)
        {
            low[u] = min(low[u], dis[j]);
        }
    }

    if (parent == -1 && child > 1)
    {
        isAP[u] = true;
    }
}

int main()
{
    cin >> n >> e;
    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    DFS(1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (isAP[i] == true)
        {
            cout << i << " is an AP" << endl;
        }
    }
}
