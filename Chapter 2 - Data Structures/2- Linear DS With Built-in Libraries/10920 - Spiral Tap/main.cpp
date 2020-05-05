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
    ll sz, p;
    while (cin >> sz >> p) {
        if (sz == 0 && p == 0) break;
        ll cur = 1;
        ll x = sz / 2 + 1;
        ll y = sz / 2 + 1;
        char arr[4] = {'u', 'l', 'd', 'r'};
        int moves = 1;
        int it = 0;
        int num = 1;
        for (ll i = 1; i < p; i++) {
            if (arr[it] == 'u') {
                y += moves;
            } else if (arr[it] == 'l') {
                x -= moves;
            } else if (arr[it] == 'd') {
                y -= moves;
            } else if (arr[it] == 'r') {
                x += moves;
            }
            i += moves;
            while (i > p) {
                if (arr[it] == 'u') {
                    --y;
                } else if (arr[it] == 'l') {
                    ++x;
                } else if (arr[it] == 'd') {
                    ++y;
                } else {
                    --x;
                }
                i--;
            }
            if (i == p) break;
            if (num % 2 == 0)
                moves++;
            it++;
            if (it == 4)
                it = 0;
            i--;
            num++;
        }
        cout << "Line = " << y << ", column = " << x << ".\n";
    }
}