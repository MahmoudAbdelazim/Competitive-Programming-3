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

int main() {
    boost();
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vi v(n);
        for (int &i: v) cin >> i;
        ll sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        if (ans > 0) cout << "The maximum winning streak is " << ans << ".\n";
        else cout << "Losing streak.\n";
    }
}

