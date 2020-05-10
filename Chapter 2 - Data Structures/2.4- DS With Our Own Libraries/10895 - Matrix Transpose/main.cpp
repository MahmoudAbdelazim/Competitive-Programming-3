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

vector<vector<pair<int, int>>> adj;
int n, m, r;

void transpose() {
    vector<vector<pair<int, int>>> tmp(10005);
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            tmp[adj[i][j].first].emplace_back(i, adj[i][j].second);
        }
    }
    adj = tmp;
}

void print() {
    cout << n << " " << m << "\n";
    for (int i = 1; i < 10005; i++) {
        if (i > n) break;
        cout << adj[i].size();
        if (adj[i].size() > 0) cout << " ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j].first + 1;
            if (j < adj[i].size() - 1) cout << " ";
        }
        cout << "\n";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j].second;
            if (j < adj[i].size() - 1) cout << " ";
        }
        cout << "\n";
    }
}

int main() {
    boost();
    while (cin >> n) {
        adj.clear();
        adj.resize(10005);
        cin >> m;
        for (int i = 0; i < n; i++) {
            cin >> r;
            if (r == 0) continue;
            vector<int> indices(r);
            for (int j = 0, x; j < r; j++) {
                cin >> indices[j];
            }
            for (int j = 0, x; j < r; j++) {
                cin >> x;
                adj[i].emplace_back(indices[j], x);
            }
        }
        swap(m, n);
        transpose();
        print();
    }
}