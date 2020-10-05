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

int main() {
//    boost();
    ll coins[] = {1, 5, 10, 25, 50};
    ll V = 31000;
    ll m = 5;
    ll table[V + 1][m];
    for (ll i = 0; i < m; i++) table[0][i] = 1;
    for (ll i = 1; i <= V; i++) {
        for (ll j = 0; j < m; j++) {
            ll x = (i - coins[j] >= 0) ? table[i - coins[j]][j] : 0;
            ll y = (j > 0) ? table[i][j - 1] : 0;
            table[i][j] = x + y;
        }
    }
    ll n;
    while (cin >> n) {
        ll ans = table[n][4];
        if (ans != 1)
            cout << "There are " << ans << " ways to produce " << n << " cents change.\n";
        else
            cout << "There is only 1 way to produce " << n << " cents change.\n";
    }

}

