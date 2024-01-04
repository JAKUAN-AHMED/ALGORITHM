#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef pair<int, int> pii;
vector<pii>directions={{-1,0},{1,0},{0,-1},{0,1}};
int visited[N][N];
bool isValid(int i,int j,int n,int m)
{
    return i>=0 && i<n && j>=0 && j<m;
}
int dfs(vector<string>&matrix,int i,int j)
{
    int n=matrix.size();
    int m=matrix[0].size();
    visited[i][j]=1;
    int area=1;
    for (pii dir:directions)
    {
        int nr=i+dir.first;
        int nc=j+dir.second;
        if (isValid(nr,nc,n,m) && !visited[nr][nc] && matrix[nr][nc]=='.')
        {
            area+=dfs(matrix, nr, nc);
        }
    }
    return area;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<string>arr(n);
    for (int i=0;i<n;i++) 
    {
        cin>>arr[i];
    }
    int mn=INT_MAX;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (!visited[i][j] && arr[i][j]=='.')
            {
                int area=dfs(arr,i,j);
                mn=min(mn,area);
            }
        }
    }
    if (mn==INT_MAX)
    {
        cout<<-1<<endl;
    } 
    else
    {
        cout<<mn<<endl;
    }

    return 0;
}
