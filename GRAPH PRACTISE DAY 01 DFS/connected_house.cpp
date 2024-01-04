#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
bool vis[N];
int cnt=0;
void dfs(int vertex,int k)
{
    vis[vertex]=true;
    
    for(int child:g[vertex])
    {
    
        
        if(vis[child]) continue;
        dfs(child,k);
        cnt++;   
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
        g[v1].push_back(v2);
        //g[v2].push_back(v1);
    }
    int k; cin>>k;
    dfs(k,k);
    cout<<cnt<<endl;
    return 0;
}
