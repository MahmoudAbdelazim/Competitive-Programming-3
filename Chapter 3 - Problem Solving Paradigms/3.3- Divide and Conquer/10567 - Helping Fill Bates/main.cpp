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
#define INF (int)1e9

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

int main() {
    boost();
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        string ss;
        cin >> ss;
        int j = 0;
        bool is = true;
        int start = -1, end = -1;
        for (int c = 0; c < ss.size(); c++) {
            for (int i = j; i < s.size(); i++) {
                if (s[i] == ss[c]) {
                    j = i;
                    if (c == 0) start = i;
                    else end = i;
                    j++; break;
                }
                else if (i == s.size() - 1) {
                    is = false; break;
                }
            }
        }
        if (end == -1) end = start;
        if (is) cout << "Matched " << start << " " << end << "\n";
        else cout << "Not matched\n";
    }
}