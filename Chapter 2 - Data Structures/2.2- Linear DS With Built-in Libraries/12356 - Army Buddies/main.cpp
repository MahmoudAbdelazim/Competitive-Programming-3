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
int lft[100005];
int rgt[100005];

int main() {
    //boost();
    ll s, b;
    while (cin >> s >> b) {
        if (s == 0 && b == 0) break;
        for (int i = 1; i <= s; i++) {
            lft[i] = i - 1;
            rgt[i] = i + 1;
        }
        lft[1] = -1;
        rgt[s] = -1;
        for (int i = 0; i < b; i++) {
            ll l, r;
            cin >> l >> r;
            lft[rgt[r]] = lft[l];
            if (lft[l] != -1)
                cout << lft[l] << " ";
            else
                cout << "* ";

            rgt[lft[l]] = rgt[r];
            if (rgt[r] != -1)
                cout << rgt[r] << "\n";
            else
                cout << "*\n";
        }
        cout << "-\n";
    }
}