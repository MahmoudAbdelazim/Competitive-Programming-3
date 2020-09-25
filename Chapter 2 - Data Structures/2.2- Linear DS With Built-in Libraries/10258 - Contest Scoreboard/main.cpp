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

bool sortFunc(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2) {
    if (p1.first.first < p2.first.first)
        return true;
    else if (p1.first.first == p2.first.first) {
        if (p1.first.second > p2.first.second)
            return true;
        else if (p1.first.second == p2.first.second) {
            if (p1.second > p2.second)
                return true;
        }
    }
    return false;
}

int main() {
    boost();
    int t;
    cin >> t;
    cin.ignore();
    char str;
    cin.get(str);
    bool first = true;
    bitset<101> participated;
    vector<bitset<10>> solved;
    vector<vector<int>> tried;
    while (t--) {
        solved.resize(101);
        tried.resize(101);
        for (int i = 0; i < 101; i++) {
            tried[i] = vector<int>(10);
        }
        vector<pair<pair<int, int>, int>> v(101);
        participated.reset();
        for (int i = 1; i <= 101; i++) {
            v[i].second = i;
        }
        while (cin.get(str)) {
            int contestant, problem, time;
            char c;
            if (str == '\n') break;
            else {
                char str2;
                char str3;
                cin.get(str2);
                cin.get(str3);
                if (str2 == ' ') {
                    contestant = str - '0';
                    problem = str3 - '0';
                    cin >> time >> c;
                }
                else if (str3 == ' '){
                    contestant = (str - '0') * 10 + (str2 - '0');
                    cin >> problem >> time >> c;
                } else {
                    contestant = (str - '0') * 100 + (str2 - '0') * 10 + (str3 - '0');
                    cin >> problem >> time >> c;
                }
            }
            cin.ignore();
            participated[contestant] = 1;
            if (c == 'I') {
                if (!solved[contestant][problem]) {
                    v[contestant].first.second += 20;
                    tried[contestant][problem]++;
                }
            }
            else if (c == 'C') {
                if (!solved[contestant][problem]) {
                    v[contestant].first.second += time;
                    v[contestant].first.first++;
                }
                solved[contestant][problem] = 1;
                tried[contestant][problem] = 0;
            }
        }
        for (int i = 0; i < 101; i++) {
            if (v[i].first.first == 0) {
                v[i].first.second = 0;
            }
            else {
                for (int j = 1; j < 10; j++) {
                    if (tried[i][j] > 0) {
                        v[i].first.second -= (20 * tried[i][j]);
                        tried[i][j] = 0;
                    }
                }
            }
        }
        sort(v.rbegin(), v.rend(), sortFunc);
        for (int i = 0; i < v.size(); i++) {
            if (!participated[v[i].second]) continue;
            cout << v[i].second << " " << v[i].first.first << " " << v[i].first.second << "\n";
        }
        solved.clear();
        tried.clear();
        if (t != 0) cout << "\n";
    }
}