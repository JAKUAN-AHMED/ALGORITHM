#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        int a[n];
        for (int i= 0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==0)
        {
            bool dp[n+1][sum/2+1]; 
            for (int i=0;i<=n;i++)
            {
                for (int j=0;j<=sum/2;j++)
                {
                    if (j==0) dp[i][j]=true;
                    if (i==0) dp[i][j]=false;
                    
                }
            }
            for(int i=1;i<=n;i++)
            {
                for (int j=1;j<=sum/2;j++)
                {
                     if (j==0) dp[i][j]=true;
                    else if (i==0) dp[i][j]=false;
                    else if(a[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            if (dp[n][sum/2]) cout<<"YES"<<endl;
            else  cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
