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

int N, K;
vector<vector<pair<int, ii>>> adj;
vi dist;

void dijkstra(int s, int el) {
    dist[s] = 0;
    priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    pq.push(make_pair(0, make_pair(s, el)));
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int d = front.first;
        ii u = front.second;
        if (d > dist[u.first]) continue;
        for (auto v: adj[u.first]) {
            int plus = v.second.second - u.second;
            if (plus != 0) plus = 60;
            if (dist[u.first] + v.second.first + plus < dist[v.first]) {
                dist[v.first] = dist[u.first] + v.second.first + plus;
                pq.push(make_pair(dist[v.first], make_pair(v.first, v.second.second)));
            }
        }
    }
}

int main() {
    while (cin >> N >> K) {
        vi elev(N);
        adj.clear();
        adj.resize(101);
        dist.assign(101, INF);
        for (int i = 0; i < N; i++) {
            cin >> elev[i];
        }
        cin.ignore();
        for (int i = 0; i < N; i++) {
            string str;
            getline(cin, str);
            istringstream s(str);
            vi nums;
            int n;
            while (s >> n) {
                nums.push_back(n);
            }
            for (int k = 0; k < nums.size(); k++) {
                for (int j = 0; j < nums.size(); j++) {
                    if (k != j) {
                        adj[nums[k]].push_back(make_pair(nums[j], make_pair(elev[i] * abs(nums[k] - nums[j]), i)));
                        adj[nums[j]].push_back(make_pair(nums[k], make_pair(elev[i] * abs(nums[k] - nums[j]), i)));
                    }
                }
            }
        }
        int mn = INF;
        for (int i = 0; i < adj[0].size(); i++) {
            dist.assign(101, INF);
            dijkstra(0, adj[0][i].second.second);
            mn = min(mn, dist[K]);
        }

        if (mn == INF) cout << "IMPOSSIBLE\n";
        else cout << mn << "\n";
    }
}
