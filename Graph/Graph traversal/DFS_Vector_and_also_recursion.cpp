
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1001];
int visit[1001];
int n, e;

void DFS(int start)
{
    //Using Stack
    //Initial Steps
    visit[start] = 1;
    stack<int>STK;
    STK.push(start);
    cout<<start<<" ";

    //Repeating step
    int x = STK.top();
    while(!STK.empty())
    {
        for(int j = 0; j < graph[x].size(); j++)
        {
            x = STK.top();
            int nd = graph[x][j];
            if(visit[nd] == 0)
            {
                visit[nd] = 1;
                STK.push(nd);
                cout<<nd<<" ";
                j = 0;
            }
        }
        STK.pop();
    }
}


void DFS_RC(int start)
{
    visit[start] = 1;
    cout<<start<<" ";

    for(int j = 0; j < graph[start].size();j++)
    {
        int node = graph[start][j];
        if(visit[node] == 0)
        {
            visit[node] = 1;
            DFS_RC(node);
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
    DFS(1);
    //DFS_RC(1);


}
