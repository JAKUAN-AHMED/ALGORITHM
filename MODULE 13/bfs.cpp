#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dist[N];
bool vis[N];
vector<int>adj[N];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=true;
    dist[src]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        cout<<p<<endl;
        for(int i=0;i<adj[p].size();i++)
        {
            int child=adj[p][i];
            if(vis[child]==false)
            {
                q.push(child);
                dist[child]=dist[p]+1;
                vis[child]=true;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for (int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<": "<< dist[i]<<endl;
    }
    return 0;
}
