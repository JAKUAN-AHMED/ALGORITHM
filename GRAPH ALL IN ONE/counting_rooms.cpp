#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=10005;
int n,m;
int visited[N][N];
vector<pii>path={{-1,0},{1,0},{0,-1},{0,1}};
char arr[N][N];
bool isValid(int ci,int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m && arr[ci][cj]!='#') return true;
    else return false;
}
void dfs(int si,int sj)
{
    visited[si][sj]=true;
    for(int i=0;i<4;i++)
    {
        pii p=path[i];
        int ci=si+p.first;
        int cj=sj+p.second;
        if(isValid(ci,cj) && !visited[ci][cj])
        {
            //visited[ci][cj]=true;
            dfs(ci,cj);
        }
    }

}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visited[i][j] && arr[i][j]=='.')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
