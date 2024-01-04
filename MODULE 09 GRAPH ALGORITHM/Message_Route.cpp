#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>adj[N];
vector<bool>visited(N,false);
vector<int>level(N,0);
vector<int>parent(N,-1);
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visited[source]=true;
    level[source]=0;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(!visited[v])
            {
                q.push(v);
                visited[v]=true;
                level[v]=level[u]+1;
                parent[v]=u;
            }
        }
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
    bfs(1);
    cout<<level[n]<<endl;
    int cur=n;
    vector<int>path;
    while(cur!=-1)
    {
        path.push_back(cur);
        cur=parent[cur];
    }
    reverse(path.begin(),path.end());
    for(auto p:path)
    {
        cout<<p<<" ";
    }
    return 0;
}
