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

int main() {
//    boost();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vi b(n);
        ll sum = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] <= arr[i]) {
                    sum++;
                }
            }
        }
        cout << sum << "\n";
    }
}
