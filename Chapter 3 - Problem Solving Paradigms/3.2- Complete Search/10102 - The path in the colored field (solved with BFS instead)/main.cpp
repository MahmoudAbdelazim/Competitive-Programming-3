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
#define INF (int)1e8 + 7
#define cube(x) (x) * (x) * (x)

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

vector<vector<char>> grid;
vector<vi> dist;
int M;

bool valid(int i, int j) {
    return !(i < 0 || i >= M || j < 0 || j >= M);
}

void bfs(int x, int y) {
    dist.assign(M, vi(M, INF));
    dist[x][y] = 0;
    queue<ii> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        if (grid[u.first][u.second] == '3') break;
        int arr[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto & i : arr) {
            int curI = u.first + i[0], curJ = u.second + i[1];
            if (valid(curI, curJ)) {
                if (dist[curI][curJ] == INF) {
                    dist[curI][curJ] = dist[u.first][u.second] + 1;
                    q.push(make_pair(curI, curJ));
                }
            }
        }
    }
}

int main() {
//    boost();
    while (cin >> M) {
        grid.assign(M, vector<char>(M));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }
        vi mins;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '1') {
                    int mn = 1e9;
                    bfs(i, j);
                    for (int a = 0; a < M; a++) {
                        for (int b = 0; b < M; b++) {
                            if (grid[a][b] == '3') {
                                mn = min(mn, dist[a][b]);
                            }
                        }
                    }
                    mins.push_back(mn);
                }
            }
        }
        int mx = -1;
        for (int & min : mins)
            mx = max(mx, min);
        cout << mx << "\n";
    }
}
