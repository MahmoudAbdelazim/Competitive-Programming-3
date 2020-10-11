#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(a[0])))
#define All(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define cube(x) (x) * (x) * (x)
#define INF (int)1e8 + 7
#define INFL 1000000005L
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0
#define mod 1000000

void boost() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vector<vll> dp;
ll solve(ll n, ll k) {
    if (k == 1) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    ll sum = 0;
    for (ll x = 0; x <= n; x++) {
        sum += solve(n - x, k - 1) % mod;
        sum %= mod;
    }
    return dp[n][k] = sum;
}


int main() {
    boost();
    ll n, k;
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        dp.assign(n + 1, vll(k + 1, -1));
        cout << solve(n, k) << "\n";
    }
}

