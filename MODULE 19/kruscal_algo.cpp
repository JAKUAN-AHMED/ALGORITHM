#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int parent[N];
int parentSize[N];
void dsu_Set(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        parentSize[i]=1;
    }
}
int dsu_find(int node)
{
    while(parent[node]!=-1)
    {
        node=parent[node];
    }
    return node;
}
void dsu_union(int a,int b)
{
    int leaderA=dsu_find(a);
    int leaderB=dsu_find(b);
    if(leaderA!=leaderB)
    {
        if(parentSize[leaderA]>parentSize[leaderB])
        {
            parent[leaderB]=leaderA;
            parentSize[leaderA]+=parentSize[leaderB];
        }
        else 
        {
            parent[leaderA]=leaderB;
            parentSize[leaderB]+=parentSize[leaderA];
        }
    }
}
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
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<edge>v;
    vector<edge>ans;
    dsu_Set(n);
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v.push_back(edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        int a=v[i].a;
        int b=v[i].b;
        int w=v[i].w;
        int leaderA=dsu_find(a);
        int leaderB=dsu_find(b);
        if(leaderA==leaderB) continue;
        ans.push_back(v[i]);
        dsu_union(a,b);
    }
    for(edge val:ans)
    {
        int a=val.a;
        int b=val.b;
        int w=val.w;
        cout<<a<<" "<<b<<" "<<w<<endl;
    }
    return 0;
}
