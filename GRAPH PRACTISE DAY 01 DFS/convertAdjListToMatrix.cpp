#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Print the adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            bool isConnected = false;
            for (int v : adj[i]) {
                if (v == j) {
                    isConnected = true;
                    break;
                }
            }
            cout << isConnected << " ";
        }
        cout << endl;
    }

    return 0;
}
