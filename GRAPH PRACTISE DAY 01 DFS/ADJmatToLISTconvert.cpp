#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int val; cin>>val;
            if(val==1)
            {
                adj[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<"List "<<i<<": ";
        for(int j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
