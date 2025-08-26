#include <bits/stdc++.h>
using namespace std;
/*
0 1 2 3 4 5 6 
1 0 1 2 3 4 5 
2 1 1 2 3 4 5 
3 2 2 1 2 3 4 
4 3 3 2 2 2 3 
5 4 4 3 2 3 3 
f is replaced by d
d is deleted 
b is replaced by y

*/
int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int m = s1.size();
    int n = s2.size();
    int edit[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {

        edit[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++)
    {

        edit[0][j] = j;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[j - 1] == s2[i - 1])
            {

                edit[i][j] = edit[i - 1][j - 1];
            }
            else
            {

                edit[i][j] = 1 + min({edit[i - 1][j], edit[i][j - 1], edit[i - 1][j - 1]});
            }
        }
    }
    for (int i = 0; i < n + 1; i++)

    {
        for (int j = 0; j < m + 1; j++)
        {

            cout << edit[i][j] << " ";
        }
        cout << endl;
    }

    int i = n, j = m;
    while (i > 0)
    {

        if (s2[i - 1] == s1[j - 1])
        {

            i--;
            j--;
        }
        else
        {
            if (edit[i][j] == 1 + edit[i - 1][j - 1])
            {

                cout << s1[j - 1] << " is replaced by " << s2[i - 1] << endl;
                i--;
                j--;
            }
            else if (edit[i][j] == 1 + edit[i][j - 1])
            {

                cout << s1[j - 1] << " is deleted " << endl;
                j--;
            }
            else
            {

                cout << s2[i - 1] << " is inseted" << endl;
                i--;
            }
        }
    }

    return 0;
}
