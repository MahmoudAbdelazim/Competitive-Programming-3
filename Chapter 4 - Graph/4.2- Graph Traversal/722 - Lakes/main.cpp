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
vector<vi> grid;
int M;
int X, Y;

int floodFill(int x, int y) {
    if (x < 1 || y < 1 || x > X || y > Y) return 0;
    if (grid[x][y] != 0) return 0;
    grid[x][y] = 2;
    int ans = 1;
    ans += floodFill(x + 1, y);
    ans += floodFill(x - 1, y);
    ans += floodFill(x, y + 1);
    ans += floodFill(x, y - 1);
    return ans;
}

int main() {
    boost();
    cin >> M;
    while (M--) {
        X = 0;
        Y = 0;
        grid.resize(100);
        for (int i = 0; i < 100; i++) grid[i].resize(100);
        string str;
        int x, y;
        cin >> x >> y;
        cin.ignore();
        int i = 1;
        while (true) {
            getline(cin, str);
            if (str.empty()) break;
            X++;
            for (int j = 0; j < str.size(); j++) {
                grid[i][j + 1] = str[j] - '0';
                if (X == 1) Y++;
            }
            i++;
        }
        cout << floodFill(x, y) << "\n";
        if (M != 0) cout << "\n";
    }

}