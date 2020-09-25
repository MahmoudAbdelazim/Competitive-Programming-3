#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define All(x) x.begin(), x.end()

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

ll n;
vector<ll> v;

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        unordered_map<char, int> table;
        for (int i = 0; i < n; i++) {
            char c; int x;
            cin >> c >> x;
            table[c] = x ;
        }
        for (int i = 0; i < 256; i++) {
            if (table[(char)i] == 0) {
                continue;
            }
        }
        int m;
        cin >> m;
        string line;
        double sum = 0;
        cin.ignore();
        for (int i = 0; i < m; i++) {
            getline(cin, line);
            for (char & j : line) {
                sum += table[j];
            }
        }
        sum /= 100;
        printf("%0.2lf$\n", sum);
    }
}