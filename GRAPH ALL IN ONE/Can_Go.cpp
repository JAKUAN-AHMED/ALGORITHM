#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
const long long int INF=1e9+7;
typedef pair<int,int>pii;
vector<pii>g[N];
vector<long long int>dist(N,INF);
void dijkstra(int s)
{
    dist[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;
        int dist_u=pq.top().first;
        pq.pop();
        if(dist_u>dist[u]) continue;
        for(pii child:g[u])
        {
            int v=child.first;
            int w=child.second;
            if(dist_u+w<dist[v])
            {
                dist[v]=dist_u+w;
                pq.push({dist[v],v});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        long long int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u, w}); 

    }
    int s; cin>>s;
    dijkstra(s);
    int t; cin>>t;
    while(t--)
    {
        long long int d,dw; cin>>d>>dw;
        if(dist[d]<=dw && dist[d]!=INF)
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
