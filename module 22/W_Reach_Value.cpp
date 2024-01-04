#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
bool reach_value(ll current)
{
  if(current == n) return true;
  if(current>n) return false;
  else
  {
    bool op1= reach_value(current*10);
    bool op2= reach_value(current *20);
    return op1|| op2;
  }
}
 int main(){
   
   int t;
   cin>>t;
   while(t--){
    cin>>n;
   if(reach_value(1))
   {
   cout<<"YES"<<endl;
   }
   else{
    cout<<"NO"<<endl;
   }
 }
  return 0;

}