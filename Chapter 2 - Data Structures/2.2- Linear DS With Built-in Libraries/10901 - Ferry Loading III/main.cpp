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
    boost();
    //=======================================================================
    int c;
    cin >> c;
    int n, t, m;
    bool first = true;
    while (c--) {
        if (!first) cout << "\n";
        first = false;
        cin >> n >> t >> m;
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
        int curTime = 0;
        int cur = 'l';
        vector<int> v(m);
            while (!Lcars.empty() || !Rcars.empty()) {
            if (cur == 'l') {
                if (!Lcars.empty() && Lcars.front().first > curTime) {
                    if (Rcars.empty()) {
                        curTime = Lcars.front().first;
                        for (int i = 0; i < n; i++) {
                            if (!Lcars.empty() && Lcars.front().first <= curTime) {
                                v[Lcars.front().second] = curTime + t;
                                Lcars.pop();
                            }
                            else break;
                        }
                    } else {
                        if (Rcars.front().first >= Lcars.front().first) {
                            curTime = Lcars.front().first;
                            for (int i = 0; i < n; i++) {
                                if (!Lcars.empty() && Lcars.front().first <= curTime) {
                                    v[Lcars.front().second] = curTime + t;
                                    Lcars.pop();
                                }
                                else break;
                            }
                        } else {
                            curTime = max(curTime, Rcars.front().first);
                        }
                    }
                } else {
                    if (Lcars.empty() && Rcars.front().first > curTime) {
                        curTime = Rcars.front().first;
                    }
                    for (int i = 0; i < n; i++) {
                        if (!Lcars.empty() && Lcars.front().first <= curTime) {
                            v[Lcars.front().second] = curTime + t;
                            Lcars.pop();
                        }
                        else break;
                    }
                }
                cur = 'r';
            } else {
                if (!Rcars.empty() && Rcars.front().first > curTime) {
                    if (Lcars.empty()) {
                        curTime = Rcars.front().first;
                        for (int i = 0; i < n; i++) {
                            if (!Rcars.empty() && Rcars.front().first <= curTime) {
                                v[Rcars.front().second] = curTime + t;
                                Rcars.pop();
                            }
                            else break;
                        }
                    } else {
                        if (Lcars.front().first >= Rcars.front().first) {
                            curTime = Rcars.front().first;
                            for (int i = 0; i < n; i++) {
                                if (!Rcars.empty() && Rcars.front().first <= curTime) {
                                    v[Rcars.front().second] = curTime + t;
                                    Rcars.pop();
                                }
                                else break;
                            }
                        } else {
                            curTime = max(curTime, Lcars.front().first);
                        }
                    }
                } else {
                    if (Rcars.empty() && Lcars.front().first > curTime) {
                        curTime = Lcars.front().first;
                    }
                    for (int i = 0; i < n; i++) {
                        if (!Rcars.empty() && Rcars.front().first <= curTime) {
                            v[Rcars.front().second] = curTime + t;
                            Rcars.pop();
                        }
                        else break;
                    }
                }
                cur = 'l';
            }
            curTime += t;
        }
        for (int i = 0; i < m; i++) {
            cout << v[  i] << "\n";
        }
    }
}