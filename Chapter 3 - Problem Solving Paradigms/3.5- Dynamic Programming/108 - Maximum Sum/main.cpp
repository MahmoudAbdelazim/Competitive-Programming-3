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
    cin >> n;
    vector<vll> v(n, vll(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (i > 0) v[i][j] += v[i - 1][j];
            if (j > 0) v[i][j] += v[i][j - 1];
            if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];
        }
    }
    ll mx = -INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    ll cur = v[k][l];
                    if (i > 0) cur -= v[i - 1][l];
                    if (j > 0) cur -= v[k][j - 1];
                    if (j > 0 && i > 0) cur += v[i - 1][j - 1];
                    mx = max(mx, cur);
                }
            }
        }
    }
    cout << mx << "\n";
}

