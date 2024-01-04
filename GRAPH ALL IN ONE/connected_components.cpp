#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int>g[N];
bool visited[N];
vector<vector<int>>cc;
vector<int>current_cc;

void dfs(int vertex)
{
    current_cc.push_back(vertex);
    visited[vertex]=true;
    for(int child:g[vertex])
    {
        if(!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
        }
    }

    cout<<cc.size()<<endl;
    return 0;
}
