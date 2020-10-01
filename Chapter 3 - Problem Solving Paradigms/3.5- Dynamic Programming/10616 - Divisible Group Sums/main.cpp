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

vll v;
ll d, m, n, q;
vector<vector<vll>> dp;

ll solve(ll sum, ll idx, ll rem) {
    if (rem == 0 && sum == 0) return 1;
    if (rem == 0 && sum != 0) return 0;
    if (idx >= n || rem < 0) return 0;
    if (dp[idx][rem][sum] != -1) return dp[idx][rem][sum];
    return dp[idx][rem][sum] = solve(sum, idx + 1, rem)
           + solve((((sum + v[idx]) % d) + d ) % d, idx + 1, rem - 1);
}

int main() {
//    boost();
    int set = 0;
    while (cin >> n >> q) {
        ++set;
        if (n == 0 && q == 0) break;
        v.clear();
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int query = 0;
        cout << "SET " << set << ":\n";
        while (q--) {
            ++query;
            cin >> d >> m;
            dp.assign(n + 5, vector<vll>(m + 5, vll(30, -1)));
            ll ans = solve(0, 0, m);
            cout << "QUERY " << query << ": " << ans << "\n";
        }
    }
}

