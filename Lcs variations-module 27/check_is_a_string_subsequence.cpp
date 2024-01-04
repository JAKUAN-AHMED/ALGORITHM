#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    //normal approach-n+m/o(m) complexity
    //algorithmic approach n*m;
    //if size of lps==size of first string
    bool ans=false;
    int x=0;
    for(char c:b)
    {
        if(c==a[x])
        {
            x++;
        }
        if(x==n)
        {
            ans=true;
            break;
        }
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
