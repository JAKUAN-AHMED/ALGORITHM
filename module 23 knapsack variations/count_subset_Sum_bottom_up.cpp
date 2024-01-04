#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s; cin>>s;
    int dp[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(j==0)
            {
                dp[i][j]=1;
            }
            else if(i==0)
            {
                dp[i][j]=0;
            }
            else if(a[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
            }
            else
            {
                        
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s];
    return 0;
}
// 4
// 1 2 4 6
// 5
