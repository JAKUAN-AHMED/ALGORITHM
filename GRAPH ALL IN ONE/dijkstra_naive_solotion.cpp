#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+7;
vector<pii>g[N];
int INF=INT_MAX;
vector<int>dist(N,INF);
void dijkstra(int src)
{
    queue<int>q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(pii child:g[u])
        {
            int v=child.first;
            int w=child.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});

    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"shortest path of "<<i<<": "<<dist[i]<<endl;
    }
    return 0;
}
