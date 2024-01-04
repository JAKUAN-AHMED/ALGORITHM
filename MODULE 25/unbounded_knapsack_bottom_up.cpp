#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    int v[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(dp[i][j-wt[i-1]]+v[i-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            } 

        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}
//input
// 4 6
// 5 3 2 4
// 4 1 3 2

//output-18
