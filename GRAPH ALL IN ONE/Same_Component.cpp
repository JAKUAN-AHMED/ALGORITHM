#include<bits/stdc++.h>
using namespace std;
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
const int N=1005;
bool visited[N][N];
bool isValid(int r,int c,int n,int m)
{
    return r>=0 && r<n && c>=0 && c<m;
}
bool SameComponent(vector<string>&mat,int si,int sj,int di,int dj)
{
    int n=mat.size();
    int m=mat[0].size();
    queue<pair<int,int>>q;
    q.push({si, sj});
    visited[si][sj]=true; 
    while (!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(r==di && c==dj)
        {
            return true;
        }
        for (int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i]; 
            if (isValid(nr,nc,n,m) && !visited[nr][nc] && mat[nr][nc]=='.')
            {
                q.push({nr,nc});
                visited[nr][nc]=true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<string>matrix(n);
    for (int i=0;i<n;i++)
    {
        cin>>matrix[i];
    }  
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    if(SameComponent(matrix,si,sj,di,dj))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    
    return 0;
}
