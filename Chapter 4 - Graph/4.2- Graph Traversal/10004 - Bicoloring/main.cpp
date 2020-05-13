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
int N, E;
vector<vi> adj;

bool isBipartite(int s) {
    vi color(N, -1);
    color[s] = 0;
    queue<int> q;
    q.push(s);
    bool isBip = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &i: adj[u]) {
            if (color[i] == -1) {
                color[i] = 1 - color[u];
                q.push(i);
            } else if (color[i] == color[u]) {
                isBip = false; break;
            }
        }
    }
    return isBip;
}

int main() {
    boost();
    while (cin >> N) {
        if (N == 0) break;
        adj.resize(N);
        cin >> E;
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        if (isBipartite(0)) {
            cout << "BICOLORABLE.\n";
        }
        else {
            cout << "NOT BICOLORABLE.\n";
        }
        adj.clear();
    }
}