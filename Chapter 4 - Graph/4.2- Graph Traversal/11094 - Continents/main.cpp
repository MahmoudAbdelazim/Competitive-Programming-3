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
int X, Y;
vector<vi> grid;

int floodFill(int x, int y, int oldC, int newC) {
    if (x < 0 || x >= M) {
        return 0;
    }
    if (y == -1) y = N - 1;
    else if (y == N) y = 0;
    if (grid[x][y] != oldC) return 0;
    grid[x][y] = newC;
    int ans = 1;
    ans += floodFill(x + 1, y, oldC, newC);
    ans += floodFill(x - 1, y, oldC, newC);
    ans += floodFill(x, y + 1, oldC, newC);
    ans += floodFill(x, y - 1, oldC, newC);
    return ans;
}

int main() {
    boost();
    while (cin >> M >> N) {
        char c;
        bool isFirst = true;
        char firstC;
        grid.resize(M);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                cin >> c;
                c = tolower(c);
                if (isFirst) firstC = c, isFirst = false;
                if (c == firstC) grid[i].push_back(0);
                else grid[i].push_back(1);
            }
        }
        cin >> X >> Y;
        int land, water;
        if (grid[X][Y] == 0) land = 0, water = 1;
        else land = 1, water = 0;
        floodFill(X, Y, land, water);
        int mx = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == land) {
                    mx = max(mx, floodFill(i, j, land, water));
                }
            }
        }
        cout << mx << "\n";
        grid.clear();
    }
}