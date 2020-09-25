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

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<ll, pair<int, int>> m;
        int mx = 0;
        int cur = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++) {
            if (m[v[i]].first == 0) {
                m[v[i]].first++;
                m[v[i]].second = i;
                cur++;
                mx = max(mx, cur);
            } else {
                mx = max(mx, cur);
                cur = 0;
                i = m[v[i]].second;
                m.clear();
            }
        }
        cout << mx << "\n";
    }
}