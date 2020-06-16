#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define All(x) x.begin(), x.end()
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0
#define INF (int)1e8 + 7
#define cube(x) (x) * (x) * (x)

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

int n;
vi arr;

int main() {
//    boost();
    int cnt = 1;
    while (cin >> n) {
        arr.clear();
        if (n == 0) break;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(All(arr));
        int m;
        cin >> m;
        cout << "Case " << cnt++ << ":\n";
        while (m--) {
            int x;
            cin >> x;
            int mn = 1e9;
            bool foundExact = false;
            int res = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        int sum = arr[i] + arr[j];
                        if (sum == x) {
                            foundExact = true;
                            res = sum;
                            break;
                        }
                        if (abs(sum - x) < mn) {
                            mn = abs(sum - x);
                            res = sum;
                        }
                    }
                }
                if (foundExact) break;
            }
            cout << "Closest sum to " << x << " is " << res << ".\n";
        }

    }
}
