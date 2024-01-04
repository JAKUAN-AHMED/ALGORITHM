#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,m;
vector<int>g[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:g[u])
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    vector<int>cmp;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            
            dfs(i);
            cmp.push_back(i);
        }
    }
    cout<<cmp.size()-1<<endl;
    for(int i=0;i<cmp.size()-1;i++)
    {
        cout<<cmp[i]<<" -> "<<cmp[i+1]<<endl;
    }
    return 0;
}
