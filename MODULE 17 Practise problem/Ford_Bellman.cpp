#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
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
int main()
{
    int n,e;
    cin>>n>>e;
    vector<edge>v;
    while (e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edge ed(a,b,w);
        v.push_back(ed);
    }
    int dist[n+1];
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
    }
    dist[1]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<=v.size();j++)
        {
            edge ed=v[j];
            int a=ed.a;
            int b=ed.b;
            int w=ed.w;
            if(dist[a]<INF && dist[a]+w<dist[b])
            {
                dist[b]=dist[a]+w;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>=INF) cout<<"30000"<<" ";
        else cout<<dist[i]<<" ";
    }
    return 0;
}
