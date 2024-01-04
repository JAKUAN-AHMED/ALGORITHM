#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int parent[N];
int parentSize[N];
void dsu_set(int n)
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
            //A leader
            parent[leaderB]=leaderA;
            parentSize[leaderA]+=parentSize[leaderB];
        }
        else
        {
            //B leader
            parent[leaderA]=leaderB;
            parentSize[leaderB]+=parentSize[leaderA];
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while(e--)
    {
        int u,v;
        cin>>u>>v;
        dsu_union(u,v);
    }
    map<int,bool>mp;
    for(int i=1;i<=n;i++)
    {
        int ldr=dsu_find(i);
        mp[ldr]=true;
    }
    vector<int>v;
    for(pair<int,bool>p:mp)
    {
        v.push_back(p.first);
    }
    cout<<v.size()-1<<endl;
    for(int i=0;i<v.size()-1;i++)
    {
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
    return 0;
}
