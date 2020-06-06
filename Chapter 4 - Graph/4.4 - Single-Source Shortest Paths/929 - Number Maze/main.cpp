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

int N, M;
vector<vi> adj;
vector<vi> dist;

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        adj.assign(N, vi(M, INF));
        dist.assign(N, vi(M, INF));
        for (int i = 0; i < N; i++) {
            int x;
            for (int j = 0; j < M; j++) {
                cin >> x;
                adj[i][j] = x;
            }
        }
        dist[0][0] = adj[0][0];
        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        pq.push(make_pair(0, make_pair(0, 0)));
        while (!pq.empty()) {
            auto front = pq.top(); pq.pop();
            int d = front.first;
            auto u = front.second;
            if (d > dist[u.first][u.second]) {
                continue;
            }
            if (u.first > 0) {
                auto v = make_pair(u.first - 1, u.second);
                if (dist[u.first][u.second] + adj[v.first][v.second] < dist[v.first][v.second]) {
                    dist[v.first][v.second] = dist[u.first][u.second] + adj[v.first][v.second];
                    pq.push(make_pair(dist[v.first][v.second], make_pair(v.first, v.second)));
                }
            }
            if (u.first < N - 1) {
                auto v = make_pair(u.first + 1, u.second);
                if (dist[u.first][u.second] + adj[v.first][v.second] < dist[v.first][v.second]) {
                    dist[v.first][v.second] = dist[u.first][u.second] + adj[v.first][v.second];
                    pq.push(make_pair(dist[v.first][v.second], make_pair(v.first, v.second)));
                }
            }
            if (u.second > 0) {
                auto v = make_pair(u.first, u.second - 1);
                if (dist[u.first][u.second] + adj[v.first][v.second] < dist[v.first][v.second]) {
                    dist[v.first][v.second] = dist[u.first][u.second] + adj[v.first][v.second];
                    pq.push(make_pair(dist[v.first][v.second], make_pair(v.first, v.second)));
                }
            }
            auto v = make_pair(u.first, u.second + 1);
            if (u.second < M - 1) {
                if (dist[u.first][u.second] + adj[v.first][v.second] < dist[v.first][v.second]) {
                    dist[v.first][v.second] = dist[u.first][u.second] + adj[v.first][v.second];
                    pq.push(make_pair(dist[v.first][v.second], make_pair(v.first, v.second)));
                }
            }
        }
        cout << dist[N-1][M-1] << "\n";

    }
}
