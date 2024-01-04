#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[b] = a;
        }
    }
};

int main() {
    int n;
    cin >> n;

    DSU dsu(n);

    vector<pair<int, int>> roads;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; // Adjust for 0-based indexing
        b--; // Adjust for 0-based indexing
        roads.push_back({a, b});
    }

    int components = n;
    vector<pair<int, int>> plan;

    for (int i = 0; i < n - 1; ++i) {
        int a = roads[i].first;
        int b = roads[i].second;

        if (dsu.find(a) != dsu.find(b)) {
            dsu.union_sets(a, b);
            components--;
            plan.push_back({a + 1, b + 1});
        }
    }

    cout << components - 1 << endl;

    // Add the necessary connections for the disconnected component
    for (int i = 2; i <= n; ++i) {
        if (dsu.find(0) != dsu.find(i - 1)) {
            cout << "1 " << i << " ";
            dsu.union_sets(0, i - 1);
        }
    }

    for (int i = 0; i < components - 1; ++i) {
        cout << plan[i].first << " " << plan[i].second << " ";
        cout << roads[i].first + 1 << " " << roads[i].second + 1 << endl;
    }

    return 0;
}
