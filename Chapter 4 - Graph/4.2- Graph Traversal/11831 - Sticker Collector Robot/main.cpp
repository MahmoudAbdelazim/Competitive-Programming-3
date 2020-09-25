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

int n, m, s, total;
int curX, curY;
int dir;
string str;
vector<vi> adj;

void move(char c) {
    if (c == 'D') {
        dir += 90;
        dir %= 360;
    } else if (c == 'E') {
        if (dir == 0) dir = 270;
        else dir -= 90;
    } else if (c == 'F') {
        if (dir == 0) {
            if (curX - 1 == -1 || adj[curX - 1][curY] == 2) {

            } else if (adj[curX - 1][curY] == 1) {
                adj[curX][curY] = 0;
                adj[curX - 1][curY] = 3;
                curX--;
                total++;
            } else {
                adj[curX][curY] = 0;
                adj[curX - 1][curY] = 3;
                curX--;
            }
        } else if (dir == 90) {
            if (curY + 1 == m || adj[curX][curY + 1] == 2) {

            } else if (adj[curX][curY + 1] == 1) {
                adj[curX][curY] = 0;
                adj[curX][curY + 1] = 3;
                curY++;
                total++;
            } else {
                adj[curX][curY] = 0;
                adj[curX][curY + 1] = 3;
                curY++;
            }
        } else if (dir == 180) {
            if (curX + 1 == n || adj[curX + 1][curY] == 2) {

            } else if (adj[curX + 1][curY] == 1) {
                adj[curX][curY] = 0;
                adj[curX + 1][curY] = 3;
                curX++;
                total++;
            } else {
                adj[curX][curY] = 0;
                adj[curX + 1][curY] = 3;
                curX++;
            }
        } else if (dir == 270) {
            if (curY - 1 == -1 || adj[curX][curY - 1] == 2) {

            } else if (adj[curX][curY - 1] == 1) {
                adj[curX][curY] = 0;
                adj[curX][curY - 1] = 3;
                curY--;
                total++;
            } else {
                adj[curX][curY] = 0;
                adj[curX][curY - 1] = 3;
                curY--;
            }
        }
    }
}

int main() {
    boost();
    while (cin >> n) {
        cin >> m >> s;
        total = 0;
        if (n == 0 && m == 0 && n == 0) break;
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> str;
            for (char &c: str) {
                if (c == '.') {
                    adj[i].push_back(0);
                } else if (c == '*')
                    adj[i].push_back(1);
                else if (c == '#')
                    adj[i].push_back(2);
                else {
                    adj[i].push_back(3);
                    if (c == 'N') dir = 0;
                    else if (c == 'L') dir = 90;
                    else if (c == 'S') dir = 180;
                    else if (c == 'O') dir = 270;
                    curX = i;
                    curY = adj[i].size() - 1;
                }
            }
        }
        cin >> str;
        for (char &c: str)
            move(c);
        cout << total << "\n";
    }
}