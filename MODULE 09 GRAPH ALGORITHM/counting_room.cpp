#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
vector<pii>direc={{0,-1},{0,1},{-1,0},{1,0}};
const int N=1e3+10;
vector<string>g;
int n,m;
int visited[N][N];
bool isValid(int i,int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
void dfs(int i,int j)
{
    if(!isValid(i,j)) return;
    if(visited[i][j]) return;
    if(g[i][j]=='#') return;
    visited[i][j]=true;
    for(auto d:direc)
    {
        dfs(i+d.first,j+d.second);
    }
}
int main()
{  
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        string x;
        cin>>x;
        g.push_back(x);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(g[i][j]=='#') continue;
            if(visited[i][j])  continue;
            dfs(i,j);
            cnt++;

        }
    }
    cout<<cnt<<endl;
    return 0;
}
