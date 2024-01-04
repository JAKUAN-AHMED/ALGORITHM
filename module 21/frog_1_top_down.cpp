#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N];
int solve(int a[],int n)
{
    if(n==1)
    {
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    else if(n==2)
    {
        return dp[n]=abs(a[2]-a[1]);
    }
    else
    {
        int choice_1=solve(a,n-1)+abs(a[n]-a[n-1]);
        int choice_2=solve(a,n-2)+abs(a[n]-a[n-2]);
        return dp[n]=min(choice_1,choice_2);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        cin>>a[i];
    }
    return 0;
}
