#include <bits/stdc++.h>
using namespace std;

int optimalmerge(vector<int> files)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < files.size(); i++)
    {
        minHeap.push(files[i]);
    }
    int totalcost = 0;
    while (minHeap.size() > 1)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int mergedcost = first + second;
        totalcost += mergedcost;
        minHeap.push(mergedcost);
    }
    return totalcost;
}

int main()
{
    vector<int> files = {20, 30, 10, 5, 30};
    int cost = optimalmerge(files);

    cout << "Minimum cost = " << cost << endl;

    return 0;
}
