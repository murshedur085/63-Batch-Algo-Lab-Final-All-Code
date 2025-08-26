#include<bits/stdc++.h>
using namespace std;


void insertion(int n, int ara[])
{
    for(int i = 0; i < n; i++) // Picking loop
    {
        int pick = ara[i];
        int j = i-1;
        while(j >= 0 && ara[j] > pick)
        {
            swap(ara[j+1], ara[j]);
            j--;
        }
        ara[j+1] = pick;

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

    insertion(n, ara);

    for(int i = 0; i < n; i++)
    {
        cout<<ara[i]<<" ";
    }

}
