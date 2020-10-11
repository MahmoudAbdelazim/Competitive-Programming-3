#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(a[0])))
#define All(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define cube(x) (x) * (x) * (x)
#define INF (int)1e8 + 7
#define INFL 1000000005L
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0
#define mod 1000000

#define SMALL 1e-8

void boost() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll p, q, r, s, t, u;

double can(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * (x * x) + u;
}

int main() {
    boost();
    while (cin >> p >> q >> r >> s >> t >> u) {
        double minx = 0.0, maxx = 1.0;
        double ans = INF;
        while (minx < maxx) {
            double mid = minx + (maxx - minx) / 2;
            double val = can(mid);
            if (fabs(val) < SMALL) {
                ans = mid;
                break;
            } else if (val < 0) {
                maxx = mid;
            } else {
                minx = mid;
            }
        }
        if (ans != INF) printf("%.4lf\n", ans);
        else printf("No solution\n");
    }
}

