#include <bits/stdc++.h>
using namespace std;

struct Circle {
    long double x, y;
    long double r;
};
#define sq(x) ((x) * (x))

struct DisjointSetTree {
    long long comp_count;
    vector<long long> parent, comp_size;
    set<long long> roots;
    vector<bool> cut;
    DisjointSetTree(int n) {
        comp_count = n;
        parent.resize(n);
        comp_size.resize(n, 1);
        cut.resize(n, false);
        iota(parent.begin(), parent.end(), 0);
        for (int i = 0; i < n; i++) {
            roots.insert(i);
        }
    }

    int find(int u) {
        if (parent[u] == u)
            return parent[u];
        return parent[u] = find(parent[u]);
    }

    bool merge(int u, int v, bool intercept) {
        u = find(u), v = find(v);
        if (u == v) {
            return cut[u] != intercept;
        }
        parent[u] = v;
        comp_size[v] += comp_size[u];
        comp_size[u] = 0;
        roots.erase(u);
        comp_count--;
        // Number of times the
        cut[v] = ((cut[v] != cut[u]) != intercept);
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    cin >> n;
    vector<Circle> log(n);
    for (int i = 0; i < n; i++)
        cin >> log[i].x >> log[i].y >> log[i].r;
    Circle population;
    cin >> population.x >> population.y;
    population.r = 0.0;
    for (int i = 0; i < n; i++)
        log[i].x -= population.x, log[i].y -= population.y;
    DisjointSetTree dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If the circles intersect, i.e. there is a line formed
            if (sq(log[i].x - log[j].x) + sq(log[i].y - log[j].y) <
                sq(log[i].r + log[j].r + 2 * population.r)) {
                Circle c1 = log[i], c2 = log[j];
                // If the line cuts the positive y-axis
                if (c1.x > c2.x)
                    swap(c1, c2);
                bool cuts = c1.x <= 0 && c2.x > 0 && c1.x * c2.y < c2.x * c1.y;
                // Call the DSU Merge and see if there is a spiral
                if (dsu.merge(i, j, cuts)) {
                    cout << "WE ARE SAFE!" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "KEEP WORKING :(" << endl;
}