#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool find(ll sub_mult,ll n,vector<int>&dp)
{
    if (sub_mult==n) return true;
    if (sub_mult>n || sub_mult<1) return false;
    if (dp[sub_mult]!=-1) return dp[sub_mult];

    bool op1 = find(sub_mult + 3,n,dp);
    bool op2 = find(sub_mult * 2, n,dp);

    dp[sub_mult]=op1 || op2;
    return dp[sub_mult];
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int>DP(n + 1,-1);
        if (find(1,n,DP))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
