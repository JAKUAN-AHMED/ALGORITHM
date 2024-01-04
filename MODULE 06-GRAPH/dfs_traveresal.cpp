#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adjlist[N];
bool visited[N];
int depth[N];
int height[N];
void dfs(int u)
{
    
    visited[u]=true;
    // cout<<"visiting Node:"<<u<<endl;
    for(int v:adjlist[u])
    {
        //action before entering neighbour
        if(visited[v]==true) continue;
        {
            depth[v]=depth[u]+1;
            dfs(v);
            // if(height[v]+1>height[u])
            // {
            //     height[u]=height[v]+1;
            // }
            height[u]=max(height[u],height[v]+1);
        }
        //action after exiting neighbour
    }
    //action afte exiting node u
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Node"<<" "<<i<<":";
    //     for(int j:adjlist[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(1);
    //visited all node
    cout<<"Visiting height........"<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<"Depth of Node "<<i<<":=>"<<depth[i]<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        cout<<"Height of Node "<<i<<":="<<height[i]<<endl;
    }
    return 0;
}
