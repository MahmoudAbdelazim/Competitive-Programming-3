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
#define cube(x) (x) * (x) * (x)
#define mod 1000000007
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(a[0])))

void boost() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll M, C;
vector<vll> price;
vector<vll> dp;

ll solve(ll money, int g) {
    if (money < 0) return -INF;
    if (g == C) return M - money;
    if (dp[money][g] != -1) return dp[money][g];
    ll ans = -1;
    for (int i = 0; i < price[g].size(); i++) {
        ans = max(ans, solve(money - price[g][i], g + 1));
    }
    return dp[money][g] = ans;
}

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        cin >> M >> C;
        price.clear();
        price.resize(C);
        dp.assign(M + 1, vll(C + 1, -1));
        for (int i = 0; i < C; ++i) {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                ll x;
                cin >> x;
                price[i].push_back(x);
            }
        }
        int ans = solve(M, 0);
        if (ans < 0) cout << "no solution\n";
        else cout << ans << "\n";
    }
}

