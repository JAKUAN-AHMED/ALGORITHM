#include<bits/stdc++.h>
using namespace std;
const int N=1005;
bool vis[N][N];
int n,m;
typedef pair<int,int>pii;
int dist[N][N];
vector<pii>path={{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int ci,int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m) return true;
    else return false;
}
void bfs(int si,int sj)
{
    queue<pii>q;
    q.push({si,sj});
    dist[si][sj]=0;
    vis[si][sj]=true;
    while (!q.empty())
    {
        pii parent=q.front();
        int pi=parent.first;
        int pj=parent.second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            pii p=path[i];
            int ci=pi+p.first;
            int cj=pj+p.second;
            if(isValid(ci,cj) && !vis[ci][cj])
            {
                vis[ci][cj]=true;
                q.push({ci,cj});
                dist[ci][cj]=dist[pi][pj]+1;
            }
        }
    }
    
}
int main()
{
    cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++)
       {
            cin>>arr[i][j];
       }
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<"Dist of "<<i<<" "<<j<<" : "<<dist[i][j]<<endl;
        }
    }
    return 0;
}
