#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>g[N];
bool visited[N];
int subTreeSum[N];
int val[N];
int even_ct[N];
void dfs(int u,int par=-1)
{
    if(u%2==0){
        even_ct[u]++;
    }
    subTreeSum[u]+=u;
    visited[u]=true;
    for(int v:g[u])
    {
         if(v==u) continue;
        if(visited[v]) continue;
        dfs(v,u);
        subTreeSum[u]+=subTreeSum[v];
        even_ct[u]+=even_ct[v];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<subTreeSum[i]<<" "<<even_ct[i]<<endl;
    }
    // int q; cin>>q;
    // while (q--)
    // {
    //     int v; cin>>v;
    //     dfs(v);
    //     cout<<subTreeSum[v]<<" "<<even_ct[v]<<endl;
    // }
    
    return 0;
}
