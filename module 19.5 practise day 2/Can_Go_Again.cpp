#include<bits/stdc++.h>
using namespace std;
const long long ss=1e18;
class Edge
{
public:
	int u;
	int v;
	int w;
	Edge(int u,int v,int w)
    {
		this->u=u;
		this->v=v;
		this->w=w;
	}
};
int main()
{
	int n,e;
	cin>>n>>e;
	vector<Edge>list;
	while(e--)
    {
		int u,v,w;
		cin>>u>>v>>w;
		Edge ed(u,v,w);
		list.push_back(ed);
	}
	int s;
	cin>>s;
	vector<long long> dis(n+1,ss);
	dis[s]=0;
	 for (int i=1;i<=n-1;i++)
     {
        for (Edge ob:list) 
        {
            if (dis[ob.u]!=ss && dis[ob.v]>dis[ob.u]+ob.w)
            {
                dis[ob.v]=dis[ob.u]+ob.w;
            }
        }
    }
	bool flag=false;
	for(Edge ob:list)
    {
		if(dis[ob.u]!=ss && dis[ob.u]+ob.w<dis[ob.v])
        {
			flag=true;
			break;
		}
	}
	int q;
	cin>>q;
	while(q--)
    {
		int d;
		cin>>d;
		if(flag)
        {
			cout<<"Negative Cycle Detected\n";
			break;
		}
		else if(dis[d]==ss)
        {
                cout<<"Not Possible"<<endl;
		}
		else
        {
            cout<<dis[d]<<endl;
		}
	}

	return 0;
}