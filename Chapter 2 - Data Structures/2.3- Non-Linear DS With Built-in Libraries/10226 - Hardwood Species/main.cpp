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
    cin.ignore();
    cin.ignore();
    unordered_map<string, int> m;
    vector<pair<string, int>> freq;
    int total = 0;
    while (t--) {
        string str;
        while (getline(cin, str)    ) {
            if (str == "") break;
            m[str]++;
            total++;
        }
        for (auto & it : m) {
            freq.emplace_back(it.first, it.second);
        }
        sort(freq.begin(), freq.end());
        for (auto &i: freq)
            cout << i.first << " " << fixed << setprecision(4) << ((double)i.second / total) * 100 << "\n";
        freq.clear();
        m.clear();
        total = 0;
        if (t != 0) cout << "\n";
    }
}