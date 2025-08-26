#include<bits/stdc++.h>
using namespace std;
vector <int> graph[1001];
int visit[1001];
int n,e;
vector<int>ans;
void DFS(int start)
{
    visit[start] = 1;
    for(int j = 0; j< graph[start].size();j++)//indx aigola
    {
        int node = graph[start][j];
        if(visit[node] == 0)
        {
            visit[node] =1;
            DFS(node);
        }
    }
    ans.push_back(start);
}
int main()
{
    cin >> n>> e;
    int u,v;
    for(int i =1; i<=e; i++)
    {

        cin>> u>>v;
        graph[u].push_back(v);
    }
    for(int i =1; i<= n; i++)
    {

        if(visit[i]==0)// only unvisit node jon loop colbe
        {

            DFS(i);
        }
    }

    for(int i = ans.size()-1; i >=0; i--)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
