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
    //=======================================================================
    string str;
    while (cin >> str) {
        if (str == "#") break;
        bool exist = next_permutation(All(str));
        if (exist)
            cout << str << "\n";
        else
            cout << "No Successor\n";
    }
}