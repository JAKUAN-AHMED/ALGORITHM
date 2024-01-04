#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+5;
vector<pii>adj[N];
vector<bool>visited(N);
int INF=1e9+5;
vector<int>dist(N,INF);
void dijkstra(int source)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    dist[source]=0;
    pq.push({dist[source],source});
    while (!pq.empty())
    {
        int pr=pq.top().second;
        pq.pop();
        visited[pr]=true;
        for(pii vpair:adj[pr])
        {
            int v=vpair.first;
            int w=vpair.second;
            if(visited[v]) continue;
            if(dist[v]>dist[pr]+1)
            {
                dist[v]=dist[pr]+w;
                pq.push({dist[v],v});
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
        int v1,v2,w;
        cin>>v1>>v2>>w;
        adj[v1].push_back({v2,w});
       //  adj[v2].push_back({v1,w});

    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Distance of Node "<<i<<" :";
        cout<<dist[i]<<endl;

    }
    return 0;
}
