#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int sum=0;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2==0)
    {
        int dp[n][sum+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0) dp[i][j]=true;
                if(i==0) dp[i][j]=false;
                if(a[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][sum-a[i-1]] || dp[i-1][j];
                }
                else 
                {
                    dp[i][j]=dp[i-1][j];
                }
        
            }
        }
        if(dp[n][sum]) cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
