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
int M, N;
vector<vi> grid;

void floodFill(int x, int y) {
    if (x < 1 || y < 1 || x > M || y > N) return;
    if (grid[x][y] != 1) return;
    grid[x][y] = 0;
    floodFill(x + 1, y);
    floodFill(x - 1, y);
    floodFill(x, y + 1);
    floodFill(x, y - 1);
    floodFill(x + 1, y + 1);
    floodFill(x - 1, y - 1);
    floodFill(x + 1, y - 1);
    floodFill(x - 1, y + 1);

}

int main() {
    boost();
    while (cin >> M) {
        if (M == 0) break;
        grid.resize(M + 1);
        cin >> N;
        for (int i = 1; i <= M; i++) {
            grid[i].resize(N + 1);
            for (int j = 1; j <= N; j++) {
                char c; cin >> c;
                if (c == '*') grid[i][j] = 0;
                else grid[i][j] = 1;
            }
        }
        int num = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (grid[i][j] == 1) {
                    num++;
                    floodFill(i, j);
                }
            }
        }
        cout << num << "\n";
        grid.clear();
    }
}