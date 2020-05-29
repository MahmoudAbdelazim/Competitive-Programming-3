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

int N;
vector<vi> adj;
vi dist;

int main() {
    boost();
    cin >> N;
    adj.clear(); adj.resize(N);
    for (int i = 0; i < N; i++) {
        int n, x;
        cin >> n;
        while (n--) {
            cin >> x;
            adj[i].push_back(x);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        dist.assign(N, INF);
        int s; cin >> s;
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int &v: adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        sort(All(dist));
        vi eachDist(N);
        int cur = 1;
        for (int i : dist) {
            if (i == 0) continue;
            if (i == cur) {
                eachDist[cur]++;
            } else {
                if (i == INF) break;
                cur = i;
                eachDist[cur]++;
            }
        }
        int mx = 0, mxInt = 0;
        for (int i = 1; i < eachDist.size(); i++) {
            if (eachDist[i] > mx) {
                mx = eachDist[i];
                mxInt = i;
            }
        }
        if (!mx) cout << "0\n";
        else cout << mx << " " << mxInt << "\n";
    }
}