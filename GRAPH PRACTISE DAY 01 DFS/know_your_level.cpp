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
            vis[child]=1;
            level[child]=level[cur_v]+1;
            q.push(child);
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
        if(v1==v2) continue;
        adj[v1].push_back((v2));
        adj[v2].push_back((v1));
    }
    int l; cin>>l;
    int max_possible_level=n-1;
    if(l==0){
        cout<<l<<endl; return 0;
    }
    else if(l>max_possible_level || l<=0)
    {
        cout<<-1<< endl;
        return 0;
    }
    bfs(0);
    set<int>s;
    for(int i=1;i<=N;i++)
    {
        if(level[i]==l)
        {
            s.insert(i);
        }
    }
    if(s.empty())
    {
        cout<<-1<<endl;
    }
    else
    {
        for(auto it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
        }
    }
    return 0;
}
