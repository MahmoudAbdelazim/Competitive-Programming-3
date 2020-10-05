#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define All(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0
#define INF (int)1e8 + 7
#define INFL 1000000005L
#define cube(x) (x) * (x) * (x)
#define mod 1000000007
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(a[0])))

void boost() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll m, V;
ll dp[301][301][41];
vector<pair<ll, ll>> coins;

ll minCoins(ll x, ll y, ll availableCoins) {
    ll currentV = x * x + y * y;
    if (currentV == V) return 0;
    if (currentV > V || availableCoins < 0) return INF;
    if (dp[x][y][availableCoins] != -1) return dp[x][y][availableCoins];
    return dp[x][y][availableCoins] = min(minCoins(x, y, availableCoins - 1),
                                          1 +
                                          minCoins(x + coins[availableCoins].first, y + coins[availableCoins].second,
                                                   availableCoins));
}

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> V;
        coins.resize(m, make_pair(0, 0));
        for (int i = 0; i < m; i++) {
            cin >> coins[i].first >> coins[i].second;
        }
        V *= V;
        memset(dp, -1, sizeof(dp));
        ll ans = minCoins(0, 0, m - 1);
        if (ans > 1e4) cout << "not possible\n";
        else cout << ans << "\n";
    }
}

