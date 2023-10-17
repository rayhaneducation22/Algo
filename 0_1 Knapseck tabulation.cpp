#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    int profit[n], weight[n], take[n];

    for(int i = 0; i<n; i++)
    {
        cin>>profit[i];
    }

    for(int i = 0; i<n; i++)
    {
        cin>>weight[i];
    }

    int v[n+1][m+1];
    memset(v, 0, sizeof(v));
    memset(take, 0, sizeof(take));

    for(int i =1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(j<weight[i-1])
            {
                v[i][j] = v[i-1][j];
            }
            else
            {
                v[i][j] = max(v[i-1][j], profit[i-1] + v[i-1][j - weight[i-1]]);
            }
        }
    }

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=m; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int i = n, j =m;
    while(i>0 && j >0)
    {
        if(v[i][j] == v[i-1][j])
        {
            take[i-1] = 0;
            i--;
        }
        else
        {
            take[i-1] =1;
            i--;
            j = j-weight[i];
        }
    }

    for(int i = 0; i< n; i++)
    {
        cout<<take[i]<<" ";
    }
    cout<<endl;

    return 0;
}
