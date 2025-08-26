#include<bits/stdc++.h>
using namespace std;

int main()
{

    int node, edge;
    cin>> node>> edge;
    vector<int>graph[node+1];
    int u,v;
    for(int i =1;i<=edge;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i<= node;i++)
    {
        cout << "Node "<< i << " -> ";
        for(int j =0; j< graph[i].size();j++)
        {

            cout<< graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
