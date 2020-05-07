#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int k;
    while (true) {
        cin >> k;
        if (k == 0)
            break;
        int n, m;
        cin >> n >> m;
        int x, y;
        while (k--) {
            cin >> x >> y;
            if (x > n && y > m)
                cout << "NE" << endl;
            else if (x < n && y > m)
                cout << "NO" << endl;
            else if (x < n && y < m)
                cout << "SO" << endl;
            else if (x > n && y < m)
                cout << "SE" << endl;
            else
                cout << "divisa" << endl;
        }
    }
    return 0;
}