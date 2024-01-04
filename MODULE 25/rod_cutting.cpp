#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dp[N][N];
int unbounded_knapsack(int n,int s,int v[],int w[])
{
    if(n==0 || s==0) return 0;
    if(dp[n][s]!=-1) return dp[n][s];
    if(w[n-1]<=s)
    {
        int ch1=unbounded_knapsack(n,s-w[n-1],v,w)+v[n-1];
        int ch2=unbounded_knapsack(n-1,s,v,w);
        return dp[n][s]= max(ch1,ch2);
    }
    else
    {
        return dp[n][s]=unbounded_knapsack(n-1,s,v,w);
    }
}
int main()
{
    int n;
    cin>>n;
    int v[n],wt[n];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        wt[i]=i+1;

    }
    cout<<unbounded_knapsack(n,n,v,wt)<<endl;
    return 0;
}
// input
// 8
// 2 4 4 5 8 14 12 9
// output-18