#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
bool vis[N];
bool dfs(int vertex,int par=-1)
{
    vis[vertex]=true;
    bool IsCycleExists=false;
    for(int child:g[vertex])
    {
        if(vis[child] && child==par) continue;
        if(vis[child]) return true;
        IsCycleExists|=(child,vertex);
      
    }
    return IsCycleExists;
    
}
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool IsCycleExists=false;
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        if(dfs(i))
        {
            IsCycleExists=true;
            break;
        }
    }
    if(IsCycleExists) cout<<"cycle detected";
    else cout<<"not detected";
    return 0;
}
