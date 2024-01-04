#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];
vector<int>Traversal;
void dfs(int u)
{
    visited[u]=true;
    Traversal.push_back(u);
    for(int v:adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i=Traversal.size()-1;i>=0;i--)
    {
        cout<<Traversal[i]<<" ";
    }
    return 0;
}
