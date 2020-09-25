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
int k;

int main() {
//    boost();
    while (cin >> k) {
        vii sols;
        for (int x = k + 1; x <= 2 * k; x++) {
            if ((x * k) % (x - k) == 0) {
                sols.push_back(make_pair((x * k)/ (x - k), x));
            }
        }
        cout << sols.size() << "\n";
        for (int i = 0; i < sols.size(); i++)
            cout << "1/" << k << " = 1/" << sols[i].first << " + 1/" << sols[i].second << "\n";
    }
}
