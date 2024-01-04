#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dist[N];
bool vis[N];
vector<int>adj[N];
void dfs(int src)
{
    vis[src]=true;
    cout<<src<<endl;
    for(int i=0;i<adj[src].size();i++)
    {
        int child=adj[src][i];
        if(vis[child]==false)
        {
            dfs(child);
        
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    return 0;
}
