#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int s,int v[],int w[])
{
    if(n==0 || s==0) return 0;
    if(w[n-1]<=s)
    {
        int op1=knapsack(n-1,s-w[n-1],v,w)+v[n-1];
        int op2=knapsack(n-1,s,v,w);
        return max(op1,op2);
    }
    else
    {
        return knapsack(n-1,s,v,w);
    }
}
int main()
{
    int n;
    cin>>n;
    int v[n],w[n];
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    int s; cin>>s;
    // knapsack(n,s,v,w);
    cout<<knapsack(n,s,v,w)<<endl;
    return 0;
}
