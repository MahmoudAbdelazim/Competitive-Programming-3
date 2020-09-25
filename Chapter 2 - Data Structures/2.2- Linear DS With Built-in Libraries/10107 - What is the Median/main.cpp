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
//    boost();
    //=======================================================================
    vector<ll> v;
    ll x;
    while (cin >> x) {
        v.push_back(x);
        if (v.size() % 2 != 0) {
            nth_element(v.begin(), v.begin() + (int) v.size() / 2, v.end());
            cout << v[(int)v.size() / 2] << "\n";
        }
        else {
            nth_element(v.begin(), v.begin() + (int)v.size() / 2, v.end());
            nth_element(v.begin(), v.begin() + (int)v.size() / 2 - 1, v.end());
            nth_element(v.begin(), v.begin() + (int)v.size() / 2, v.end());
            nth_element(v.begin(), v.begin() + (int)v.size() / 2 - 1, v.end());
            cout << (v[(int)v.size() / 2 - 1] + v[(int)v.size() / 2]) / 2 << "\n";
        }
    }
}