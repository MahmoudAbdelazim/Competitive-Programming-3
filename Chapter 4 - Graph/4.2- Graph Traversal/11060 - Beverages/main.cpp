#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define All(x) x.begin(), x.end()

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

std::hash<string> hsh;
vector<string> withUs;

unsigned int toInt(string &s) {
    return hsh(s) % (int) (1e5 + 1);
}

vector<string> ord;
int N, M;
string str;
typedef pair<int, string> val_name;
typedef pair<string, int> name_val;
map<string, int> nameval;
map<int, string> valname;
vector<vi> adj;

struct compareVal {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

void topSort() {

}

int main() {
//    boost();
    int cnt = 1;
    while (cin >> N) {
        nameval.clear();
        valname.clear();
        adj.clear();
        adj.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> str;
            nameval.insert(name_val(str, i));
            valname.insert(val_name(i, str));
        }
        cin >> M;
        vector<int> in_degrees(N);
        for (int i = 0; i < M; i++) {
            string x, y;
            cin >> x >> y;
            adj[nameval[x]].push_back(nameval[y]);
            in_degrees[nameval[y]]++;
        }
        priority_queue<int, vector<int>, compareVal> q;
        for (int i = 0; i < N; i++) {
            if (in_degrees[i] == 0) q.push(i);
        }
        vector<string> ordered;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            ordered.push_back(valname[u]);
            for (int &i: adj[u]) {
                if (--in_degrees[i] == 0) q.push(i);
            }
        }
        cout << "Case #" << cnt << ": Dilbert should drink beverages in this order:";
        cnt++;
        for (int i = 0; i < N; i++) {
            cout << " " << ordered[i];
        }
        cout << ".\n\n";
    }
}