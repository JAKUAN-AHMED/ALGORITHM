#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
int main()
{
    int n,e;
    cin>>n>>e;
    int dist[n+1][n+1];
    bool cycleExists=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=e;j++)
        {
            dist[i][j]=INF;
            if(i==j) dist[i][j]=0;
        }
    }
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        dist[a][b]=w;
        
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j && dist[i][j]<0)
                {
                    cycleExists=true;
                    break;
                }
                else if(dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    if(cycleExists) cout<<"cycle detectd"<<endl;
    else
    {
        cout<<"updated..."<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]==INF) cout<<"INF"<<" ";
                else cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
