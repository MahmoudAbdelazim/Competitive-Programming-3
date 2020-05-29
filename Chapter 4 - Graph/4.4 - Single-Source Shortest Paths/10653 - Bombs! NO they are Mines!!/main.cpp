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

int R, C;
vector<vi> grid, dist;

bool valid(int r, int c) {
    return (r >= 0 && r < R && c >= 0 && c < C)
           && dist[r][c] == INF && grid[r][c] != 1;
}

int main() {
    boost();
    while (scanf("%d", &R) != EOF) {
        scanf("%d", &C);
        if (R == 0 && C == 0) break;
        grid.assign(R, vi(C));
        dist.clear();
        dist.resize(R);
        for (int i = 0; i < R; i++) {
            dist[i].assign(C, INF);
        }
        int rows;
        scanf("%d", &rows);
        for (int i = 0; i < rows; i++) {
            int row;
            scanf("%d", &row);
            int num;
            scanf("%d", &num);
            for (int j = 0; j < num; j++) {
                int col;
                scanf("%d", &col);
                grid[row][col] = 1;
            }
        }
        int sx, sy, dx, dy;
        scanf("%d %d", &sx, &sy);
        scanf("%d %d", &dx, &dy);
        queue<ii> q;
        q.push(make_pair(sx, sy));
        dist[sx][sy] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            sx = u.first;
            sy = u.second;
            if (valid(sx + 1, sy)) {
                dist[sx + 1][sy] = dist[sx][sy] + 1;
                q.push(make_pair(sx + 1, sy));
            }
            if (valid(sx - 1, sy)) {
                dist[sx - 1][sy] = dist[sx][sy] + 1;
                q.push(make_pair(sx - 1, sy));
            }
            if (valid(sx, sy + 1)) {
                dist[sx][sy + 1] = dist[sx][sy] + 1;
                q.push(make_pair(sx, sy + 1));
            }
            if (valid(sx, sy - 1)) {
                dist[sx][sy - 1] = dist[sx][sy] + 1;
                q.push(make_pair(sx, sy - 1));
            }
        }
        printf("%d\n", dist[dx][dy]);
    }
}