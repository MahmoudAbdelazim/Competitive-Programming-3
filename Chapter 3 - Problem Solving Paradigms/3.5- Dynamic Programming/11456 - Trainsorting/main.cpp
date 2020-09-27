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
            while (t--) {
                int n;
                cin >> n;
                vi v(n);
                for (int &i: v) cin >> i;
                int lis[n];
                for (int i = n - 1; i >= 0; i--) {
                    lis[i] = 1;
                    for (int j = i + 1; j < n; j++) {
                        if (v[i] > v[j] && lis[j] + 1 > lis[i]) {
                            lis[i] = lis[j] + 1;
                        }
                    }
                }
                int lds[n];
                for (int i = n - 1; i >= 0; i--) {
                    lds[i] = 1;
                    for (int j = i + 1; j < n; j++) {
                        if (v[i] < v[j] && lds[j] + 1 > lds[i]) {
                            lds[i] = lds[j] + 1;
                        }
                    }
                }
                int mx = 0;
                for (int i = 0; i < n; i++) {
                    mx = max(mx, lis[i] + lds[i] - 1);
                }
                cout << mx << "\n";
            }
        }

