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
#define INF (int)1e8 + 7
#define cube(x) (x) * (x) * (x)

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

int N;
vi busyness;
vi dist;
vector<vii> adj;

int main() {
    boost();
    int cnt = 1;
    while (cin >> N) {
        busyness.clear();
        busyness.resize(N + 1);
        adj.clear();
        adj.resize(N + 1);
        dist.assign(N + 1, INF);
        for (int i = 1; i <= N; i++) {
            cin >> busyness[i];
        }
        int r;
        cin >> r;
        for (int i = 0; i < r; i++) {
            int x, y;
            cin >> x >> y;
            int w = cube(busyness[y] - busyness[x]);
            adj[x].push_back(make_pair(y, w));
        }
        dist[1] = 0;
        for (int i = 1; i <= N - 1; i++) {
            for (int u = 1; u <= N; u++) {
                for (ii v: adj[u]) {
                    if (dist[u] != INF && dist[v.first] > dist[u] + v.second) {
                        dist[v.first] = dist[u] + v.second;
                    }
                }
            }
        }
        for (int i = 1; i <= N - 1; i++) {
            for (int u = 1; u <= N; u++) {
                for (ii v: adj[u]) {
                    if (dist[u] != INF && dist[v.first] > dist[u] + v.second) {
                        dist[v.first] = -INF;
                    }
                }
            }
        }
        int q;
        cin >> q;
        cout << "Set #" << cnt++ << "\n";
        while (q--) {
            int x;
            cin >> x;
            if (dist[x] == INF || dist[x] == -INF || dist[x] < 3) {
                cout << "?\n";
            } else {
                cout << dist[x] << "\n";
            }
        }
    }
}
