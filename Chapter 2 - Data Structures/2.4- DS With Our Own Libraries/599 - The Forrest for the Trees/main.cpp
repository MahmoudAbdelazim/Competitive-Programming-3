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

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> withUs;

int cnt = 0;
int dfs(int s) {
    visited[s] = 1;
    cnt++;
    for (int &i: adj[s]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return cnt;
}

int main() {
    boost();
    int t;
    cin >> t;
    while (t--) {
        adj.clear(); visited.clear(); withUs.clear();
        adj.resize(26); visited.resize(26); withUs.resize(26);
        string str;
        while (cin >> str) {
            if (str[0] == '*') break;
            int x = str[1] - 65;
            int y = str[3] - 65;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cin >> str;
        for (char &c : str) {
            if (c == ',') continue;
            withUs[c - 65] = 1;
        }
        int trees = 0, acorns = 0;
        for (int i = 0; i < 26; i++) {
            if (!visited[i] && withUs[i]) {
                cnt = 0;
                int cur = dfs(i);
                if (cur == 1) acorns++;
                else trees++;
            }
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    }
}