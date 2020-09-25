#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define All(x) x.begin(), x.end()
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0
#define INF (int)1e9

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

int N, s;
vector<vi> adj;
vi dist, p;
map<string, int> strInt;
map<int, string> intStr;

bool isEdge(string &s1, string &s2) {
    int cnt = abs((int)s1.size() - (int)s2.size());
    if (cnt > 1) return false;
    if (s1 == s2) return false;
    for (int i = 0; i < s1.size() && i < s2.size(); i++) {
        if (s1[i] != s2[i]) {
            cnt++;
            if (cnt > 1) return false;
        }
    }
    return true;
}

int main() {
    boost();
    int t;
    cin >> t;
    bool first = true;
    while (t--) {
        strInt.clear(); intStr.clear();
        adj.clear(); adj.resize(201);
        string str;
        cin >> str;
        int idx = 0;
        while (str != "*") {
            if (strInt.find(str) == strInt.end()) {
                strInt[str] = idx;
                intStr[idx] = str;
                idx++;
            }
            cin >> str;
        }
        for (int i = 0; i < idx; i++) {
            for (int j = 0; j < idx; j++) {
                if (i != j) {
                    if (isEdge(intStr[i], intStr[j])) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        cin.ignore();
        string s1, s2;
        int i = 1;
        if (!first) cout << "\n";
        else first = false;
        while (getline(cin, str)) {
            s1 = "", s2 = "";
            i = 1;
            if (str == "") break;
            for (char &c: str) {
                if (isalpha(c)) {
                    if (i == 1) {
                        s1 += c;
                    } else {
                        s2 += c;
                    }
                } else {
                    i = 2;
                }
            }
            dist.assign(201, INF);
            p.assign(201, 0);
            s = strInt[s1];
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v: adj[u]) {
                    if (dist[v] == INF) {
                        dist[v] = dist[u] + 1;
                        p[v] = u;
                        q.push(v);
                    }
                }
            }
            cout << s1 << " " << s2 << " ";
            cout << dist[strInt[s2]] << "\n";
        }
    }
}