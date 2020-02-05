#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(vector<vector<int>> &adjList, int curr, int prev, int depth,
                   vector<int> &vis) {
    // Takes the graph and gives the farthest node from the starting vertex and
    // its distance as a pair
    vis[curr] = 1;
    int dpt = depth;
    int cd = curr;
    for (auto neigh : adjList[curr]) {
        if (neigh == prev)
            continue;
        if (vis[neigh] == 0) {
            pair<int, int> ss = dfs(adjList, neigh, curr, depth + 1, vis);
            if (ss.second > dpt) {
                dpt = ss.second;
                cd = ss.first;
            }
        }
    }
    vis[curr] = 2;
    return {cd, dpt};
}

int find_dia(vector<vector<int>> &adjList2, int st, vector<int> &visited) {
    // Return the diameter of the given tree
    pair<int, int> vertex = dfs(adjList2, st, -1, 0, visited);
    fill(visited.begin(), visited.end(), 0);
    pair<int, int> vertex2 = dfs(adjList2, vertex.first, -1, 0, visited);
    return vertex2.second;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> visited(n + 1, false);
    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        if (visited[i])
            continue;
        ans = max(ans, find_dia(adjList, i, visited));
    }
    cout << ans << endl;
    return 0;
}