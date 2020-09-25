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
int R, C, M, N;
vector<vi> grid;
vector<bitset<101>> visited;

void dfs(int x, int y) {
    visited[x][y] = 1;
    int numMoves = 4;
    int moves[4][2] = {
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };
    int cnt = 0;
    if (M == 0) {
        for (int i = 0; i < numMoves / 2; i++) {
            int yy = y + N * moves[i][0]; int xx = x;
            if (xx >= 0 && yy >= 0 && xx < R && yy < C && grid[xx][yy] != -1) {
                cnt++;
                if(!visited[xx][yy]) dfs(xx, yy);
            }
        }
        for (int i = 0; i < numMoves / 2; i++) {
            int xx = x + N * moves[i][0]; int yy = y;
            if (xx >= 0 && yy >= 0 && xx < R && yy < C && grid[xx][yy] != -1) {
                cnt++;
                if(!visited[xx][yy]) dfs(xx, yy);
            }
        }
    }
    else if (N == 0) {
        for (int i = 0; i < numMoves / 2; i++) {
            int yy = y + M * moves[i][0]; int xx = x;
            if (xx >= 0 && yy >= 0 && xx < R && yy < C && grid[xx][yy] != -1) {
                cnt++;
                if(!visited[xx][yy]) dfs(xx, yy);
            }
        }
        for (int i = 0; i < numMoves / 2; i++) {
            int xx = x + M * moves[i][0]; int yy = y;
            if (xx >= 0 && yy >= 0 && xx < R && yy < C && grid[xx][yy] != -1) {
                cnt++;
                if(!visited[xx][yy]) dfs(xx, yy);
            }
        }
    }
    else {
        for (int i = 0; i < numMoves; i++) {
            int xx = x + M * moves[i][0]; int yy = y + N * moves[i][1];
            if (xx >= 0 && yy >= 0 && xx < R && yy < C && grid[xx][yy] != -1) {
                cnt++;
                if (!visited[xx][yy]) dfs(xx, yy);
            }
        }
        if (N != M) {
            for (int i = 0; i < numMoves; i++) {
                int xx = x + N * moves[i][0]; int yy = y + M * moves[i][1];
                if (xx >= 0 && yy >= 0 && xx < R && yy < C && grid[xx][yy] != -1) {
                    cnt++;
                    if (!visited[xx][yy]) dfs(xx, yy);
                }
            }
        }
    }
    grid[x][y] = cnt;
}

int main() {
    boost();
    int t, cnt = 1;
    cin >> t;
    while (t--) {
        cin >> R >> C >> M >> N;
        grid.clear(); visited.clear();
        grid.resize(101); visited.resize(101);
        for (int i = 0; i < 101; i++)
            grid[i].resize(101, -2);
        int w; cin >> w;
        for (int i = 0, x, y; i < w; i++) {
            cin >> x >> y;
            grid[x][y] = -1;
        }
        dfs(0, 0);
        int even = 0, odd = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] >= 0) {
                    if (grid[i][j] & 1) odd++;
                    else even++;
                }
            }
        }
        cout << "Case " << cnt << ": " << even << " " << odd << "\n";
        ++cnt;
    }
}