#include <iostream>
#include <vector>
 
using namespace std;
 
bool canCreateExpression(int n, int x, vector<int>& a, int current_sum, int index) 
{
    if (index == n) {
        return current_sum == x;
    }

    if (canCreateExpression(n, x, a, current_sum + a[index], index + 1)) {
        return true;
    }
    if (canCreateExpression(n, x, a, current_sum - a[index], index + 1)) 
    {
        return true;
    }
    return false;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    if (canCreateExpression(n, x, a, a[0], 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
 
    return 0;

}    
