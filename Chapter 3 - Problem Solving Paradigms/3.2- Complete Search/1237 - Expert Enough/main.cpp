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
    boost();
    int t, d, p;
    cin >> t;
    string str;
    bool first = true;
    vector<pair<string, vi>> data;
    while (t--) {
        cin >> d;
        data.clear();
        data.resize(d);
        for (int i = 0; i < d; i++) {
            cin >> str;
            data[i].first = str;
            for (int j = 0; j < 2; j++) {
                int x; cin >> x;
                data[i].second.push_back(x);
            }
        }
        int q;
        cin >> q;
        if (!first) cout << "\n";
        else first = false;
        while (q--) {
            cin >> p;
            bool found = false;
            int idx = -1;
            for (int i = 0; i < data.size(); i++) {
                if (data[i].second[0] <= p && data[i].second[1] >= p) {
                    if (!found) found = true;
                    else {
                        found = false;
                        break;
                    }
                    idx = i;
                }
            }
            if (found) cout << data[idx].first << "\n";
            else cout << "UNDETERMINED\n";
        }
    }
}
