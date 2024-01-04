#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int graph[N][N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;

        //without weight
        graph[v1][v2]=1;
        graph[v2][v1]=1;

        //with weight
        graph[v1][v2]=wt;
        graph[v2][v1]=wt;
        
    }
    return 0;
}
