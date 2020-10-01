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

int n;
vi v;
vi vv;
int dp[25][250][250];

bool solve(int i, int b1, int b2) {
    if (i == n) return b1 == b2;
    if (dp[i][b1][b2] != -1) return dp[i][b1][b2];
    return dp[i][b1][b2] = max(solve(i + 1, b1 + v[i], b2), solve(i + 1, b1, b2 + v[i]));
}

int main() {
    boost();
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        stringstream ss(s);
        int x;
        v.clear();
        while (ss >> x) v.push_back(x);
        n = v.size();
        vv.assign(n, 0);
        for (auto & i : dp) {
            for (auto & j : i) {
                for (int & k : j) k = -1;
            }
        }
        bool ans = solve(0, 0, 0);
        if (ans) { cout << "YES\n"; }
        else { cout << "NO\n"; }
    }
}

