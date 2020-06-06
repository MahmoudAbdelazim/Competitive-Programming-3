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

int N, M, E, T;
vector<vii> adj;
vi dist;

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        for (auto v: adj[u]) {
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
}

int main() {
    boost();
    int t;
    cin >> t;
    bool first = true;
    while (t--) {
        cin >> N >> E >> T >> M;
        adj.clear(); adj.resize(N + 1);
        dist.assign(N + 1, INF);
        for (int i = 0; i < M; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back(make_pair(b, w));
        }
        int num = 0;
        for (int i = 1; i <= N; i++) {
            dist.assign(N + 1, INF);
            dijkstra(i);
            if (dist[E] <= T) {
                num++;
            }
        }
        if (!first) cout << "\n";
        else first = false;
        cout << num << "\n";
    }
}
