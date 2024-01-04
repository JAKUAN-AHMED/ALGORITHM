#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>g[N];
bool vis[N];
vector<vector<int>>cc;
vector<int>current_cc;
void dfs(int vertex)
{
    //after entering
    //if(vis[vertex]) return; 
    current_cc.push_back(vertex);
    vis[vertex]=true;
    for(int child:g[vertex])
    {
        // cout<<"parent "<<vertex<<":child("<<child<<") ";
        //before entering child
        if(vis[child]) continue;
       //cout<<"parent "<<vertex<<":child("<<child<<") "<<endl;
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
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }
    cout<<cc.size()<<endl;
    for(auto current_cc:cc)
    {
        for(auto vertex:current_cc)
        {
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
    return 0;
}
