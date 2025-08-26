#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node,edge;
    cin >> node >> edge;
    int u,v,w;
    int graph[node+1][node+1];
    memset(graph,0,sizeof(graph));
    for(int i = 1; i <= edge; i++)
    {
        cin >> u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;//we can go from u to v and v to u
    }

    for(int i = 1; i < node+1; i++)
    {

        for(int j =1; j< node+1; j++)
        {

            cout << graph[i][j] << " ";
        }
        cout<< endl;
    }


    return 0;
}
