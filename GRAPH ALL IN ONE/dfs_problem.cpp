#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>g[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:g[u])
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
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
