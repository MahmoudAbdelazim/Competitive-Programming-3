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
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int N, n, ans;
vi sol, best;

void backtrack(vi &arr, int i, int cur) {
    if (i == n) {
        if (cur > ans) {
            ans = cur;
            best.clear();
            for (int x: sol) {
                best.push_back(x);
            }
        }
        return;
    }
    backtrack(arr, i + 1, cur); // try skip track i
    if (arr[i] + cur <= N) {
        sol.push_back(arr[i]);
        backtrack(arr, i + 1, cur + arr[i]); // try choose track i
        sol.pop_back(); //backtrack
    }
}

int main() {
//    boost();
    while (cin >> N) {
        cin >> n;
        vi arr(n);
        sol.clear(); best.clear();
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        backtrack(arr, 0, 0);
        for (int x: best) {
            cout << x << " ";
        }
        cout << "sum:" << ans << "\n";
    }
}
