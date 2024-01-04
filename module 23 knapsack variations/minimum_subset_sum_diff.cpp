#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    bool dp[n+1][s+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(j==0) dp[i][j]=true;
            if(i==0) dp[i][j]=false;
            if(a[i-1]<=j)
            {
                dp[i][j]=dp[i-1][s-a[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(dp[i][j]==1)
            {
                v.push_back(j);
            }
        }
    }
    int ans=INT_MAX;
    for(int val:v)
    {
        int s1=val;
        int s2=s-s1;
        ans=min(ans,abs(s1-s2));
    }
    cout<<ans<<endl;
    return 0;
}
