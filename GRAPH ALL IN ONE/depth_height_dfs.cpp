#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>g[N];
bool visited[N];
int height[N];
int depth[N];
void dfs(int u,int par=-1)
{
    visited[u]=true;
    for(auto child:g[u])
    {
        if(child==par) continue;
        if(visited[child]) continue;
        depth[child]=depth[u]+1;
        dfs(child,u);
        height[u]=max(height[u],height[child]+1);
    }
}
int main()
{
    int  n,m;
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
        cout<<"depth of "<<i<<":"<<depth[i]<<endl;
    }
    cout<<"........."<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"height of "<<i<<": "<<height[i]<<endl;
    }
    return 0;
}
