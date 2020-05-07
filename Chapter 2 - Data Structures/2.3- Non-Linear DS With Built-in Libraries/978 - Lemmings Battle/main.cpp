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
    int t, b, sg, sb;
    cin >> t;
    while (t--) {
        cin >> b >> sg >> sb;
        multiset<int> green;
        for (int i = 0; i < sg; i++) {
            int x; cin >> x; green.insert(x);
        }
        multiset<int> blue;
        for (int i = 0; i < sb; i++) {
            int x; cin >> x; blue.insert(x);
        }
        while (!green.empty() && !blue.empty()) {
            vector<int> currentG;
            vector<int> currentB;
            vector<int> diffs;
            for (int i = 0; i < b; i++) {
                int gsv = 0, bsv = 0;
                if (!green.empty()) {
                    auto gs = --green.end();
                    gsv = *gs;
                    green.erase(gs);
                }
                if (!blue.empty()) {
                    auto bs = --blue.end();
                    bsv = *bs;
                    blue.erase(bs);
                }
                diffs.push_back(gsv - bsv);
            }
            for (int & diff : diffs) {
                if (diff > 0) {
                    green.insert(diff);
                } else if (diff < 0) {
                    blue.insert(-diff);
                }
            }
        }
        if (green.empty() && blue.empty())
            cout << "green and blue died\n";
        else if (!green.empty()) {
            cout << "green wins\n";
            for (auto it = --green.end(); it != green.begin(); it--) {
                cout << *it << "\n";
            }
            cout << *(green.begin()) << "\n";
        } else {
            cout << "blue wins\n";
            for (auto it = --blue.end(); it != blue.begin(); it--) {
                cout << *it << "\n";
            }
            cout << *(blue.begin()) << "\n";
        }
        if (t != 0) cout << "\n";
    }
}