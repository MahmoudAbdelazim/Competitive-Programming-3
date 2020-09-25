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
int N;
vector<vi> adj;
vi color;

bool isBipartite(int s) {
    color[s] = 1;
    bool isBip = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &i: adj[u]) {
            if (color[i] == -1) {
                color[i] = 1 - color[u];
                q.push(i);
            }
            else if (color[i] == color[u]) {
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
        adj.clear(); adj.resize(N + 1);
        color.clear(); color.resize(N + 1, -1);
        int x, y;
        while (cin >> x >> y) {
            if (x == 0 && y == 0) break;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool isBip = true;
        for (int i = 1; i <= N; i++) {
            if (color[i] == -1) {
                if (!isBipartite(i)) {
                    isBip = false;
                    break;
                }
            }
        }
        if (isBip)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}