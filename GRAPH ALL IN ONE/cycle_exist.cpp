#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>g[N];
bool visited[N];
bool dfs(int vertex,int par=-1)
{
    visited[vertex]=true;
    bool isCycleExists=false;
    for(int child:g[vertex])
    {
        if(visited[child] && child==par) continue;
        if(visited[child]) return true;
        isCycleExists|=dfs(child,vertex);
    }
    return isCycleExists;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool isCycleExists=false;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]) continue;
        if(dfs(i))
        {
            isCycleExists=true;
            break;
        }
    }
    if(isCycleExists) cout<<"cycle detected"<<endl;
    else cout<<"cycle not detected"<<endl;
    return 0;
}
