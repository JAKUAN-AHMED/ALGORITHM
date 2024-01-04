#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e3+5;
int level[N][N];
int visited[N][N];
vector<pii>direc={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
bool isValid(int i,int j)
{
    return(i>=0 && i<8 && j>=0 && j<8);
}
void bfs(int si,int sj)
{
    queue<pii>q;
    q.push({si,sj});
    level[si][sj]=0;
    visited[si][sj]=true;
    while(!q.empty())
    {
        pii upair= q.front();
        int i=upair.first;
        int j=upair.second;
        q.pop();
        for(auto d:direc)
        {
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj])
            {
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
            }
        }
    }
}
void resert_level_vis()
{
     for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            level[i][j]=0;
            visited[i][j]=false;
            
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int si,sj,di,dj;
    for(int i=0;i<n;i++)
    {
        string x,y;
        cin>>x>>y;
        si=x[0]-'a';
        sj=x[1]-'1';

        di=y[0]-'a';
        dj=y[1]-'1';
        bfs(si,sj);
        cout<<level[di][dj]<<endl;

    }
    return 0;
}
