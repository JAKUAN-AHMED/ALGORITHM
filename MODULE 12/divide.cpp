#include<bits/stdc++.h>
using namespace std;
void divide(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        divide(arr,l,mid);
        divide(arr,mid+1,r);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    divide(arr,0,n-1);
    return 0;
}
