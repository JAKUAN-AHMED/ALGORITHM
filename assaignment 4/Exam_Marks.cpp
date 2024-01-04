#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N][N];
bool subset_Sum(int n,int a[],int s)
{
    if (n==0)
    {
        if (s==0) return true;
        else  return false;
    }
    if (dp[n][s]!=-1)
        return dp[n][s];
    if (a[n-1]<=s)
    {
        bool op1=subset_Sum(n-1,a,s-a[n-1]);
        bool op2=subset_Sum(n-1,a,s);
        return dp[n][s]=(op1 || op2);
    }
    else
    {
        return dp[n][s]=subset_Sum(n-1,a,s);
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int s=1000-m;
        int a[n];
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<=n;i++)
        {
            for (int j=0;j<=s;j++)
            {
                dp[i][j]=-1;
            }
        }
        if(subset_Sum(n,a,s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
