#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
vector<pii>direc={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
const int N=1005;
bool visited[N][N];
int bfs(int n,int m,int ki,int kj,int qi,int qj) 
{
    queue<pii>q;
    q.push({ki,kj});
    visited[ki][kj]=true;
    int steps=0;
    while(!q.empty()) 
    {
        int sz=q.size();
        for (int i=0;i<sz;i++) 
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if (x==qi && y==qj)
             {
                return steps;
            }
            for (int j=0;j<8;j++) 
            {
                int nx=x+direc[j].first;
                int ny=y+direc[j].second;
                if (nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny])
                {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        steps++;
    }
    return -1;
}
int main() 
{
    int T;
    cin>>T;
    while (T--)
    {      
        int n,m;
        cin>>n>>m;
        int ki,kj,qi,qj;
        cin>>ki>>kj>>qi>>qj;
        memset(visited, false, sizeof(visited));
        int result=bfs(n,m,ki,kj,qi,qj);
        cout<<result<<endl;
    }
    return 0;
}
