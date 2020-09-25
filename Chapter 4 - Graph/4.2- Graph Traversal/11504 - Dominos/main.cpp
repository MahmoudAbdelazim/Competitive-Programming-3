#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define All(x) x.begin(), x.end()
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

int N, M;
vi visited1, visited2;
vector<vi> adj;
stack<int> stk;

void DFS(int u) {
    visited1[u] = true;
    for (int &v: adj[u]) {
        if (!visited1[v])
            DFS(v);
    }
    stk.push(u);
}

void SCC(int u) {
    visited2[u] = true;
    for (int &v: adj[u]) {
        if (!visited2[v])
            SCC(v);
    }
}

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        adj.clear(); adj.resize(N + 1);
        visited1.assign(N + 1, 0);
        visited2.assign(N + 1, 0);
        for (int i = 0; i < M; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        while (!stk.empty()) stk.pop();
        for (int i = 1; i <= N; i++) {
            if (!visited1[i])
                DFS(i);
        }
        int cnt = 0;
        while (!stk.empty()) {
            int x = stk.top();
            if (!visited2[x]) {
                SCC(x);
                ++cnt;
            }
            stk.pop();
        }
        cout << cnt << "\n";
    }
}