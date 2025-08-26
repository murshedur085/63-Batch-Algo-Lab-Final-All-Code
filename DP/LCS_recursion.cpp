#include<bits/stdc++.h>
using namespace std;
int n, m;
int lcs (char a[],char b[],int i, int j )
{
    if(i==n || j==m)
        return 0;
    else if (a[i]==b[j])
        return 1+lcs(a,b,i+1,j+1);
    else
        return max(lcs(a,b,i+1,j), lcs(a,b,i,j+1));

}
int main()
{

    cin >> n>> m;
    char a[n],b[m];
    cin >> a >> b;
    int ans = lcs(a,b,0,0);
    cout << ans << endl;
    return 0;
}
