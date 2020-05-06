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

int N, c;
stack<int> cars;

void solve() {
    while (true) {
        while (!cars.empty()) cars.pop();
        int j = 0;
        for (int i = 0; i < N; i++) {
            cin >> c;
            if (c == 0) return;

            while (j < N && j != c) {
                if (!cars.empty() && cars.top() == c)
                    break;
                cars.push(++j);
            }
            if (cars.top() == c) cars.pop();
        }
        if (cars.empty()) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    //boost();
    //=======================================================================
    while (cin >> N) {
        if (!N) return 0;
        solve();
        cout << "\n";
    }
}