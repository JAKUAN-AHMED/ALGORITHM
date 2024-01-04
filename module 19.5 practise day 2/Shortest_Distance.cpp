#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const int N=1e3;
long long dist[N][N];	
bool vis[N][N];
int n,m;
void inf_zero()
{
	for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=n;j++)
        {
			dist[i][j]=INF;
            if(i==j) dist[i][j] =0;
		}
	}
}

int main()
{
	cin>>n>>m;
	inf_zero();
	for(int i=0;i<m;i++)
    {
		long long int u,v,w;
		cin>>u>>v>>w;
		dist[u][v]=min(dist[u][v],w);
		
	}
	for(int k=1;k<=n;k++)
    {
		for(int i=1;i<=n;i++)
        {
			for(int j=1;j<=n;j++)
            {
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	int q;
	cin>>q;
	while(q--)
    {
		int a,b;
		cin>>a>>b;
        if(dist[a][b]!=INF) cout<<dist[a][b]<<endl;
        else cout<<"-1"<<endl;
	}
    return 0;
}