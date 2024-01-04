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
        //cout<<"parent "<<vertex<<":child("<<child<<") ";
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
    for(int i=0;i<1000;i++)
    {
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        if(current_cc.size()==1) continue;
        else cc.push_back(current_cc);
    }
    vector<int>st;
    for(auto current_cc:cc)
    {
        st.push_back(current_cc.size());
    }
    sort(st.begin(),st.end());
    for(int i=0;i<st.size();i++)
    {
        cout<<st[i]<<" ";
    }
    
    return 0;
}
