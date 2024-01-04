#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int dp[N];
int s(int sz,int num)
{
   int i=0,l,r;
   if(i==N) return;
   if(num==l) return l;
   else if(num==r) return r;
   else
   {
     l=s(sz,dp[i++]+1);
     r=s(sz,dp[i++]+2);
   }
   
}
int main()
{   int sz; cin>>sz;
    int sum; cin>>sum;
    cout<<s(sz,sum);
    return 0;
}
