#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    int diff;
    cin >> diff;
    // Calculate the target sum
    int targetSum = (s + diff) / 2;
    int dp[n + 1][targetSum + 1];
    // Initialize dp array
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= targetSum; j++)
        {
            if (j == 0)
                dp[i][j] = 1; 
            else if (i == 0)
                dp[i][j] = 0;
            else if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][targetSum] << endl;
    return 0;
}
