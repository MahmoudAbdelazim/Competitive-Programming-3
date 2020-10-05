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

ll origV;
vector<vector<pair<ll, ll>>> dp;

pair<ll, ll> minCoins(vll &coins, int i, ll V) {
    int n = coins.size();
    if (V == 0) return make_pair(0, 0);
    if (V < 0) return make_pair(-V, 0);
    if (i == n && V > 0) return make_pair(INF, INF);
    if (dp[i][V].first != -1 && dp[i][V].second != -1) return dp[i][V];
    pair<ll, ll> op1 = minCoins(coins, i + 1, V);
    pair<ll, ll> op2 = minCoins(coins, i + 1, V - coins[i]);
    op2.second++;
    if (op1.first < op2.first) {
        return dp[i][V] = op1;
    } else if (op1.first == op2.first) {
        if (op1.second <= op2.second) {
            return dp[i][V] = op1;
        } else {
            return dp[i][V] = op2;
        }
    } else {
        return dp[i][V] = op2;
    }
}

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        ll V, n;
        cin >> V >> n;
        origV = V;
        dp.assign(105, vector<pair<ll, ll>>(10005, pair<ll, ll>(-1, -1)));
        vll coins(n);
        for (int i = 0; i < n; i++) cin >> coins[i];
        auto ans = minCoins(coins, 0, V);
        cout << origV + ans.first << " " << ans.second << "\n";
    }
}

