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
    int n;
    map<vector<int>, int> m;
    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            vector<int> tmp(5);
            for (int& x: tmp)
                cin >> x;
            sort(All(tmp));
            m[tmp]++;
        }
        int mx = -1;
        for (auto &it: m) {
            mx = max(mx, it.second);
        }
        int cnt = 0;
        for (auto &it: m) {
            if (mx == it.second) cnt++;
        }
        cout << cnt * mx << "\n";
        m.clear();
    }
}