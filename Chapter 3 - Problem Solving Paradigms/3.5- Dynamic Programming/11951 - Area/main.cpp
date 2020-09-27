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
    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        ll n, m, p;
        cin >> n >> m >> p;
        vector<vll> v(n, vll(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                if (i > 0) v[i][j] += v[i - 1][j];
                if (j > 0) v[i][j] += v[i][j - 1];
                if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];
            }
        }
        ll pay = 10000000000;
        ll mxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < m; l++) {
                        ll cur = v[k][l];
                        if (i > 0) cur -= v[i - 1][l];
                        if (j > 0) cur -= v[k][j - 1];
                        if (i > 0 && j > 0) cur += v[i - 1][j - 1];
                        ll size = (l - (j - 1)) * (k - (i - 1));
                        if (size > mxSize && cur <= p) {
                            pay = cur;
                            mxSize = size;
                        } else if (size == mxSize) {
                            if (cur < pay) {
                                pay = cur;
                            }
                        }
                    }
                }
            }
        }
        if (mxSize > 0)
            cout << "Case #" << cnt++ << ": " << mxSize << " " << pay << "\n";
        else cout << "Case #" << cnt++ << ": 0 0\n";
    }
}

