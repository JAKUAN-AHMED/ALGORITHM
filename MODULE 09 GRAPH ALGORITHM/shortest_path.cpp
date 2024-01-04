#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int level[N];
bool visited[N];
int parent[N];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visited[source]=true;
    level[source]=0;
    parent[source]=-1;
    while (!q.empty())
    {
        int pr=q.front();
        q.pop();
        for(int child:adj[pr])
        {
            if(visited[child]==true) continue;
            q.push(child);
            visited[child]=true;
            level[child]=level[pr]+1;
            parent[child]=pr;
        }
    }
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    int s,d;
    cin>>s>>d;
    bfs(s);
    cout<<"Distance :"<<level[d]<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Parent of "<<i<<": "<<parent[i]<<endl;
    // }
    vector<int>path;
    int cur=d;
    while(cur!=-1)
    {
        path.push_back(cur);
        cur=parent[cur];
    }
    reverse(path.begin(),path.end());
    cout<<"path :"<<" ";
    for(int node:path)
    {
        cout<<node<<" ";
    }
    return 0;
}
