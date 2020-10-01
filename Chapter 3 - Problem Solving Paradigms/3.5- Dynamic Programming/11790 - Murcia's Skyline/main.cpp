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
        int n;
        cin >> n;
        vi h(n), w(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        for (int i = 0; i < n; i++) cin >> w[i];
        int lis[n];
        lis[0] = w[0];
        int lds[n];
        lds[0] = w[0];
        for (int i = 1; i < n; i++) {
            lis[i] = w[i];
            lds[i] = w[i];
            for (int j = 0; j < i; j++) {
                if (h[j] < h[i] && lis[j] + w[i] > lis[i]) {
                    lis[i] = lis[j] + w[i];
                }
                if (h[j] > h[i] && lds[j] + w[i] > lds[i]) {
                    lds[i] = lds[j] + w[i];
                }
            }
        }
        int mxlds = *max_element(lds, lds + n);
        int mxlis = *max_element(lis, lis + n);
        if (mxlis >= mxlds) {
            cout << "Case " << cnt++ << ". Increasing (" << mxlis << "). Decreasing (" << mxlds << ").\n";
        } else {
            cout << "Case " << cnt++ << ". Decreasing (" << mxlds << "). Increasing (" << mxlis << ").\n";
        }
    }
}

