#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define All(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0
#define INF (int)1e8 + 7
#define cube(x) (x) * (x) * (x)
#define mod 1000000007

void boost() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int board[8][8];
int solution = -1;

bool isSafe(int row, int col, int sol[8][8]) {
    for (int i = 0; i < col; i++) {
        if (sol[row][i]) return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (sol[i][j]) return false;
    }
    for (int i = row + 1, j = col - 1; i < 8 && j >= 0; i++, j--) {
        if (sol[i][j]) return false;
    }
    return true;
}

void solve(int col, int sum, int sol[8][8]) {
    if (col == 8) {
        if (sum > solution) solution = sum;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (isSafe(i, col, sol)) {
            sol[i][col] = 1;
            sum += board[i][col];
            solve(col + 1, sum, sol);
            sol[i][col] = 0;
            sum -= board[i][col];
        }
    }
}

int main() {
    boost();
    int k;
    cin >> k;
    while (k--) {
        solution = -1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) cin >> board[i][j];
        }
        int sol[8][8] = {};
        solve(0, 0, sol);
        cout << setw(5) << right << solution << "\n";
    }
}

