#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int N=1e5+7;
vector<pii>g[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt; cin>>v1>>v2>>wt;

        //without weight
        
        // g[v1].push_back(v2);
        // g[v2].push_back(v1);

        //with weight
        g[v1].push_back({v2,wt});
        g[v2].push_back({v1,wt});
    }
    return 0;
}
