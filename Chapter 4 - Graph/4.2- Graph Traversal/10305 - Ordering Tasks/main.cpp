#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define All(x) x.begin(), x.end()

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}
int n, m;
vector<vi> adj;
bool visited[105];
vector<int> sorted;

void dfs(int s) {
    visited[s] = 1;
    for (int &i: adj[s]) {
        if (!visited[i])
            dfs(i);
    }
    sorted.push_back(s);
}

void topSort() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    boost();
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        memset(visited, 0, sizeof(visited));
        sorted.clear();
        adj.clear();
        adj.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        topSort();
        for (int i = sorted.size() - 1; i >= 0; i--)
            cout << sorted[i] << " ";
        cout << "\n";
    }
}