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
    int t;
    cin >> t;
    while (t--) {
        int n, s, q;
        cin >> n >> s >> q;
        vector<queue<int>> stations(n + 1);
        for (int i = 1; i <= n; i++) {
            int qi;
            cin >> qi;
            for (int j = 0; j < qi; j++) {
                int x;
                cin >> x;
                stations[i].push(x);
            }
        }
        stack<int> carrier;
        ll time = 0;
        bool first = true;
        set<int> nonEmptyStations;
        while (true) {
            bool nothing = false;
            for (int i = 1; i <= n; i++) {
                if (!first)
                    time += 2;
                first = false;
                while (!carrier.empty()) {
                    if (carrier.top() == i) {
                        carrier.pop();
                        ++time;
                    } else {
                        if (q - stations[i].size() > 0) {
                            stations[i].push(carrier.top());
                            carrier.pop();
                            ++time;
                        } else {
                            break;
                        }
                    }
                }
                while (s - carrier.size() > 0 && !stations[i].empty()) {
                    carrier.push(stations[i].front());
                    stations[i].pop();
                    ++time;
                }
                if (!stations[i].empty())
                    nonEmptyStations.insert(i);
                else {
                    auto el = nonEmptyStations.find(i);
                    if (el != nonEmptyStations.end())
                        nonEmptyStations.erase(el);
                }
                if (nonEmptyStations.empty() && carrier.empty()) {
                    nothing = true;
                    break;
                }
            }
            if (nothing) {
                break;
            }
        }
        cout << time << "\n";
    }
}