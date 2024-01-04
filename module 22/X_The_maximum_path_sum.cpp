#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[11][11];
int max_path(int i,int j)
{
    if(i== n-1 && j== m-1) return a[i][j];
    if(i== n+1 || j== m+1) return INT_MIN;
    int right=max_path(i+1,j);
    int down=max_path(i,j+1);
    return a[i][j] + max(right,down);

}
 int main(){ 
   
  // int n,m;
   cin>>n>>m;
   //int a[n][m];
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
   }
  int m= max_path(0,0);
  cout<<m;
  return 0;

}