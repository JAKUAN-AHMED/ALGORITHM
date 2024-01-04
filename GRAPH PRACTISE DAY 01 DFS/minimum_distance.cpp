#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int level[N];
int vis[N];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;
    level[source]=0;
    while (!q.empty())
    {
        int cur_v=q.front();
        q.pop();
        for(int child:adj[cur_v])
        {
            if(vis[child]) continue;
            q.push(child);
            vis[child]=1;
            level[child]=level[cur_v]+1;
        }
    }
    
}
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back((v2));
        adj[v2].push_back((v1));
    }
    int query; cin>>query;
    while (query--)
    {
        int f,d;
        cin>>f>>d;
        for(int i=0;i<N;i++)
        {
            vis[i]=0;
            level[i]=0;
        }
        bfs(f);
        if (vis[d])
        {
            cout<<level[d]<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    
    return 0;
}
