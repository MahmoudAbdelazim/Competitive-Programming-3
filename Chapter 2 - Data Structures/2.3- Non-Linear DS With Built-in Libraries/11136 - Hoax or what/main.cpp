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
    multiset<int> bills;
    while (cin >> n, n) {
        ll total = 0;
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            for (int i = 0, x; i < k; i++) {
                cin >> x;
                bills.insert(x);
            }
            auto mx = --bills.end();
            auto mn = bills.begin();
            total += (*mx - *mn);
            bills.erase(mx); bills.erase(mn);
        }
        cout << total << "\n";
        bills.clear();
    }
}