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

int L, U, R;
vi dist;

int getLeast4(int n) {
    int one = n % 10;
    n /= 10;
    int two = n % 10;
    n /= 10;
    int three = n % 10;
    n /= 10;
    int four = n % 10;
    return four * 1000 + three * 100 + two * 10 + one;
}

int main() {
    boost();
    int cnt = 1;
    while (cin >> L) {
        cin >> U >> R;
        if (L == 0 && U == 0 && R == 0) break;
        vector<int> Rs(R);
        for (int i = 0; i < R; i++) {
            cin >> Rs[i];
        }
        dist.assign(10000, INF);
        queue<int> q;
        q.push(L);
        dist[L] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < R; i++) {
                int v = u + Rs[i];
                if (v > 9999) {
                    v = getLeast4(v);
                }
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        if (dist[U] == INF) {
            cout << "Case " << cnt++ << ": " << "Permanently Locked\n";
        } else {
            cout << "Case " << cnt++ << ": " << dist[U] << "\n";
        }
    }
}