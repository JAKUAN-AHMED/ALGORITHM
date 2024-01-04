#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+7;
vector<pii>g[N];
bool visited[N];
class edge
{
public:
    int a;
    int b;
    int w;
    edge(int a,int b,int w)
    {
        this->a=a;
        this->b=b;
        this->w=w;
    }
};
class cmp
{
public:
    bool operator()(edge a,edge b)
    {
        return a.w>b.w;
    }
};
void prims(int s)
{
    priority_queue<edge,vector<edge>,cmp>pq;
    vector<edge>edgelist;
    pq.push(edge(s,s,0));
    while(!pq.empty())
    {
        edge parent = pq.top();
        pq.pop();
        int a=parent.a;
        int b=parent.b;
        int w=parent.w;
        if(visited[b]) continue;
        visited[b]=true;
        edgelist.push_back(parent);
        for(int i=0;i<g[b].size();i++)
        {
            pii child=g[b][i];
            if(visited[child.first]) continue;
            pq.push(edge(b,child.first,child.second));
        }
    }
    edgelist.erase(edgelist.begin());
    for(edge val:edgelist)
    {
        cout<<val.a<<" "<<val.b<<" "<<val.w<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
        
    }
    prims(1);
    return 0;
}
