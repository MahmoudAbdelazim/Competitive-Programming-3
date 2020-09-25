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
int N;
vector<vi> grid;

void floodFill(int x, int y) {
    if (x < 1 || y < 1 || x > N || y > N) return;
    if (grid[x][y] == 0) return;
    grid[x][y] = 0;
    floodFill(x + 1, y);
    floodFill(x - 1, y);
    floodFill(x, y + 1);
    floodFill(x, y - 1);
}

int main() {
    boost();
    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        cin >> N;
        grid.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            grid[i].resize(N + 1);
            for (int j = 1; j <= N; j++) {
                char c; cin >> c;
                if (c == '.') grid[i][j] = 0;
                else if (c == 'x') grid[i][j] = 1;
                else if (c == '@') grid[i][j] = 2;
            }
        }
        int num = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (grid[i][j] == 1) {
                    num++;
                    floodFill(i, j);
                }
            }
        }
        cout << "Case " << cnt << ": " << num << "\n";
        cnt++;
    }
}