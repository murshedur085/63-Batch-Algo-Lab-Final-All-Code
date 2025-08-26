#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1001];
int visit[1001];
int n, e;

void BFS(int start)
{
    //Initial Step
    visit[start] = 1;
    cout<<start<<" ";
    queue<int>Q;
    Q.push(start);

    //Repeating Step
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for(int j = 0; j < graph[x].size(); j++)
        {
            int node = graph[x][j];
            if(visit[node] == 0)
            {
                visit[node] = 1;
                cout<<node<<" ";
                Q.push(node);
            }
        }
    }
}

int main()
{
    cin>>n>>e;
    int u, v;
    for(int i = 1; i <= e; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(1);
}
