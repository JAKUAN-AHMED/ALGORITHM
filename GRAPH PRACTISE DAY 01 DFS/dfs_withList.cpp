#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
bool vis[N];
void dfs(int vertex)
{
    //after entering
    //if(vis[vertex]) return; 
    vis[vertex]=true;
    for(int child:g[vertex])
    {
        // cout<<"parent "<<vertex<<":child("<<child<<") ";
        //before entering child
        if(vis[child]) continue;
        cout<<"parent "<<vertex<<":child("<<child<<") "<<endl;
        dfs(child);
        //after entering child
    }
    //cout<<endl;
    //exiting node
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
    return 0;
}
