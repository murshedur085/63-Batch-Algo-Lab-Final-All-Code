#include<bits/stdc++.h>
using namespace std;


void selection(int n, int ara[])
{
    for(int i = 0; i < n-1; i++) //for selecting the index/position
    {
        for(int j = i+1; j < n; j++) // pointer for checking forward
        {
            if(ara[i] > ara[j])  //ara[i] is the picked positioned value           {
            {
                swap(ara[i], ara[j]);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int ara[n];
    for(int i = 0; i < n; i++)
    {
        cin>>ara[i];
    }

    selection(n, ara);

    for(int i = 0; i < n; i++)
    {
        cout<<ara[i]<<" ";
    }

}

