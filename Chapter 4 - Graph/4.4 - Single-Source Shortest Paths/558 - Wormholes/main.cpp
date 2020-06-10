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
#define INF (int)1e9

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

vector<vii> adj;
vi dist;
int N, M;

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        adj.clear(); adj.resize(N);
        dist.assign(N, INF);
        for (int i = 0; i < M; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back(make_pair(y, w));
        }
        dist[0] = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int u = 0; u < N; u++) {
                for (ii v: adj[u]) {
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
                }
            }
        }
        bool negCycle = false;
        for (int u = 0; u < N; u++) {
            for (ii v: adj[u]) {
                if (dist[u] + v.second < dist[v.first]) {
                    negCycle = true;
                    break;
                }
            }
            if (negCycle) break;
        }
        if (negCycle) cout << "possible\n";
        else cout << "not possible\n";
    }
}
