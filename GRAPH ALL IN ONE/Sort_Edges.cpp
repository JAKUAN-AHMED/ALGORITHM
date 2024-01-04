#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
int main()
{
    int n;
    cin>>n;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    while(n--)
    {
        int u,v; cin>>u>>v;
        pq.push({u,v});

    }
    while(!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}
