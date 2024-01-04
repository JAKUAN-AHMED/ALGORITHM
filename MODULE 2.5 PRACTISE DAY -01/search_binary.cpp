#include<bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int>&arr,int value)
{
    int left=0;
    int right=arr.size()-1;
    while (left<=right)
    {
        int mid=(left+right)/2;
        if (arr[mid]==value)
        {
            return true;
        }
        else if(arr[mid]<value)
        {
            left=mid+1;
        }
        else 
        { 
            right=mid-1;
        }
    }
    return false;
}
int main()
{
    int n,val;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cin>>val;
    if (binarySearch(nums,val))
    {
        cout<<"found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<" ";
    }

    return 0;
}
