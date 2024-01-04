#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+7;
vector<pii>g[N];
int INF=INT_MAX;
vector<int>dist(N,INF);
bool visited[N];
void dijkstra(int src)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        pii parent=pq.top();
        int parentNode=parent.second;
        int parentCost=parent.first;
        pq.pop();
        if(visited[parentNode]) continue;
        visited[parentNode]=true;
        for(pii child:g[parentNode])
        {
            int childNode=child.first;
            int childCost=child.second;
            if(parentCost+childCost<dist[childNode])
            {
                dist[childNode]=parentCost+childCost;
                pq.push({dist[childNode],childNode});
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
