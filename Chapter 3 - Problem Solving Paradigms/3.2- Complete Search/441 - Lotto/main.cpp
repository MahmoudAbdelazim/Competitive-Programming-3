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

set<vi> all;

bool valid(vi &v) {
    for (int i = 0; i < (int)v.size() - 1; i++) {
        if (v[i] == v[i + 1]) {
            return false;
        }
    }
    if (all.find(v) == all.end()) {
        all.insert(v);
        return true;
    }
    return false;
}

int main() {
    boost();
    bool first = true;
    while (cin >> n) {
        arr.clear();
        all.clear();
        if (n == 0) break;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (!first) cout << "\n";
        else first = false;
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                for (int c = 0; c < n; c++) {
                    for (int d = 0; d < n; d++) {
                        for (int e = 0; e < n; e++) {
                            for (int f = 0; f < n; f++) {
                                vi v {arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]};
                                sort(v.begin(), v.end());
                                if (valid(v)) {
                                    for (int i = 0; i < 5; i++) {
                                        cout << v[i] << " ";
                                    }
                                    cout << v[v.size() - 1] << "\n";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
