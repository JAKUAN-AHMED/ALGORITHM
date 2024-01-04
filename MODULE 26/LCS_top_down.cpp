#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N];
int lcs(string a,int n,string b,int m)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(a[n-1]==b[m-1])
    {
        return dp[n][m]=1+lcs(a,n-1,b,m-1);
        
    }
    else
    {
        return dp[n][m]=max(lcs(a,n-1,b,m),lcs(a,n,b,m-1));
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size(); 
    int m=b.size();
    memset(dp,-1,sizeof(dp));
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         dp[i][j]=-1;
    //     }
    // }
    cout<<lcs(a,n,b,m)<<endl;
    return 0;
}
// abcdfgr
// acfdgr
