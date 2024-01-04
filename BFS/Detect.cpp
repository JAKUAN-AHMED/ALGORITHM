#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];
bool cycleExist=false;
bool dfs(int u,int p=-1)
{
    visited[u]=true;
    for(int v:adj[u])
    {
        if(v==p) continue;
        if(visited[v]) return true;
        cycleExist|=dfs(v,u);
    }
    return cycleExist;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // if(dfs(1))
    // {
    //     cout<<"cycle detectd";
    // }
    // else cout<<"no";
    bool cycleFound=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        cycleFound|=dfs(1);
    }
    if(cycleFound) cout<<"cycle detected";
    else cout<<"cylce not detected";
    return 0;
}
