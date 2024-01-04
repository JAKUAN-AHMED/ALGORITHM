#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    int dist[n+1][n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
            if (i == j) {
                dist[i][j] = 0;
            } else if (dist[i][j] == -1) {
                dist[i][j] = INF; 
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    int mx = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] > mx && dist[i][j] != INF) {
                mx = dist[i][j];
            }
        }
    }
    
    cout << mx;
    return 0;
}
