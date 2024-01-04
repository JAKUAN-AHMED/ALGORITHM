#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
bool visited[N];
int level[N];

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visited[source]=true;
    level[source]=0; // Change 1 to 0 for the source node
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        // for(int v : g[u])
        // {
        //     if(!visited[v])
        //     {
        //         q.push(v);
        //         level[v]=level[u]+1;
        //         visited[v]=true;
        //     }
        // }
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(!visited[v])
            {
                q.push(v);
                level[v]=level[u]+1;
                visited[v]=true;
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
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Level of "<<i<<": "<<level[i]<<endl;
    }
    return 0;
}
