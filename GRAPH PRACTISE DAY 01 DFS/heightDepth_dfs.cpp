#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
int depth[N],height[N];
void dfs(int vertex,int par=-1)
{
    for(int child:g[vertex])
    {
       if(child==par) continue;
       depth[child]=depth[vertex]+1;
       dfs(child,vertex);
       height[vertex]=max(height[vertex],height[child]+1);
      
    }
   
    
}
int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
    return 0;
}
