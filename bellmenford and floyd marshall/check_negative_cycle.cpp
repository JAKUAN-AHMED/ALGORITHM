#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a;
    int b;
    int w;
    Edge(int a,int b,int w)
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
    vector<Edge> v;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        Edge ed(a,b,w);
        v.push_back(ed);
    }
    int dist[n+1];
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[1]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            Edge ed=v[j];
            int a=ed.a;
            int b=ed.b;
            int w=ed.w;
            if(dist[a]+w<dist[b])
            {
                dist[b]=dist[a]+w;
            }
        }
    }
    bool cycleExists=false;
     for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            Edge ed=v[j];
            int a=ed.a;
            int b=ed.b;
            int w=ed.w;
            if(dist[a]+w<dist[b])
            {
                cycleExists=true;
                break;
                dist[b]=dist[a]+w;
            }
        }
    }
    if(cycleExists)
    {
        cout<<"cycle detected"<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"Dist of "<<i<<": "<<dist[i]<<endl;
        }
    }
    return 0;
}
