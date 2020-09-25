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
vi color;
int total1, total2;

bool isBipartite(int s) {
    color[s] = 1;
    total1 = 1;
    total2 = 0;
    bool isBip = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &i: adj[u]) {
            if (color[i] == -1) {
                if (color[u] == 1) total2++;
                else total1++;
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
    int t; cin >> t;
    while(t--) {
        cin >> N >> E;
        adj.resize(N); color.resize(N, -1); total1 = 0, total2 = 0;
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int total = 0;
        bool isBip = true;
        for (int i = 0; i < N; i++) {
            if (color[i] == -1) {
                isBip = isBipartite(i);
                if (total2 == 0) total += total1;
                else total += min(total1, total2);
                if (!isBip) {
                    break;
                }
            }
        }

        if (isBip) {
            cout << total << "\n";
        } else {
            cout << -1 << "\n";
        }
        adj.clear(); color.clear();
    }
}