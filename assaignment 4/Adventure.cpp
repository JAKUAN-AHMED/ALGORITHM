#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n,s; cin>>n>>s;
        int w[n],v[n];
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        vector<vector<int>> dp(n + 1,vector<int>(s + 1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(w[i-1]<=j)
                {
                    int op1=dp [i-1][j-w[i-1]]+v[i-1];
                    int op2=dp[i-1][j];
                    dp[i][j]=max(op1,op2);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }

        }
        cout<<dp[n][s]<<endl;
    }
    return 0;
}