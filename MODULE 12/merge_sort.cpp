#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r)
{
    int leftsize=mid-l+1;
    int rightsize=r-mid;
    int L[leftsize];
    int R[rightsize];
    int k=0;
    for(int i=l;i<=mid;i++)
    {
        L[k]=arr[i];
        k++;
    }
    k=0;
    for(int i=mid+1;i<=r;i++)
    {
        R[k]=arr[i];
        k++;
    }
    int i=0,j=0;
    int cur=l;
    while (i<leftsize && j<rightsize)
    {
        if(L[i]<=R[j])
        {
            arr[cur]=L[i];
            i++;
            cur++;
        }
        else{
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
void merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
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
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
