#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int m,int r)
{
    int leftsize=m-l+1;
    int rightsize=r-m;
    int L[leftsize];
    int R[rightsize];
    int k=0;
    for(int i=l;i<=m;i++)
    {
        L[k]=arr[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=r;i++)
    {
        R[k]=arr[i];
        k++;
    }
    int i=0,j=0;
    int cur=l;
    while(i<leftsize && j<rightsize)
    {
        if(L[i]<=R[j])
        {
            arr[cur]=L[i];
            i++;
            cur++;
        }
        else
        {
            arr[cur]=R[j];
            j++;
            cur++;
        }
    }
    while(i<leftsize)
    {
        arr[cur]=L[i];
        i++;
        cur++;
    }
    while(j<rightsize)
    {
        arr[cur]=R[j];
        j++;
        cur++;
    }
    
}
int main() 
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge(arr,0,3,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
