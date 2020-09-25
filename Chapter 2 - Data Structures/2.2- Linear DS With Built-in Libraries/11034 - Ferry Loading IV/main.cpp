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

queue<pair<int, int>> Lcars;
queue<pair<int, int>> Rcars;

int main() {
//    boost();
    //=======================================================================
    int c;
    cin >> c;
    int l, m;
    while (c--) {
        cin >> l >> m;
        l *= 100;
        for (int i = 0; i < m; i++) {
            int x;
            string str;
            cin >> x >> str;
            if (str == "left") {
                Lcars.emplace(x, i);
            } else {
                Rcars.emplace(x, i);
            }
        }
        int cur = 'l';
        int times = 0;
        while (!Lcars.empty() || !Rcars.empty()) {
            if (cur == 'l') {
                int emptySpace = l;
                while (!Lcars.empty() && Lcars.front().first <= emptySpace) {
                    emptySpace -= Lcars.front().first;
                    Lcars.pop();
                }
                cur = 'r';
            } else {
                int emptySpace = l;
                while (!Rcars.empty() && Rcars.front().first <= emptySpace) {
                    emptySpace -= Rcars.front().first;
                    Rcars.pop();
                }
                cur = 'l';
            }
            times++;
        }
        cout << times << "\n";
    }
}