#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int coin[n];
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    int amount; cin>>amount;
    int dp[n][amount+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(i==0) dp[i][j]=INT_MAX;
            else if(j==0) dp[i][j]=0;
            else if(coin[i-1]<=j)
            {
                dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][amount];
    return 0;
}
