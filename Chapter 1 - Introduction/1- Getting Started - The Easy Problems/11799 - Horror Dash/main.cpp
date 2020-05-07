#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sort(v) sort(v.begin(), v.end())

int main() {
    cin.sync_with_stdio(0);
    int t, n, min;
    cin >> t;
    int k = 1;
    while (t--) {
        min = 0;
        cin >> n;
        for (int i = 0, u; i < n; i++) {
            cin >> u;
            min = max(min, u);
        }
        cout << "Case " << k << ": " << min << endl;
        k++;
    }
}
