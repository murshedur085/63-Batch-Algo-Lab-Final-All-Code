#include<bits/stdc++.h>
using namespace std;
void merging(int A[],int B[],int C[],int m,int n)
{
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(A[i]<B[j])
        {
            C[k]=A[i];
            k++;
            i++;
        }
        else
        {
            C[k]=B[j];
            k++;
            j++;
        }
    }
    for(; i<m; i++)
    {
        C[k]=A[i];
        k++;
    }
    for(; j<n; j++)
    {
        C[k]=B[j];
        k++;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    int A[m],B[n];
    for(int i=0; i<m; i++)
    {
        cin>>A[i];
    }
    for(int j=0; j<n; j++)
    {
        cin>>B[j];

    }
    int C[m+n];
    merging(A,B,C,m,n);
    for(int k=0; k<m+n; k++)
    {
        cout<<C[k]<<" ";
    }

    return 0;
}
