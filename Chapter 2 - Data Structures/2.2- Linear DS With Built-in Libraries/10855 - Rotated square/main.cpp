#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define All(x) x.begin(), x.end()

void boost() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
}

bool isPart(vector<vector<char>> &V, vector<vector<char>> &v, int i, int j) {
    vector<vector<char>> tmp(v.size());
    int idx = 0;
    for (int k = i; k < v.size() + i; k++) {
        for (int l = j; l < v.size() + j; l++) {
            tmp[idx].push_back(V[k][l]);
        }
        idx++;
    }
    return tmp == v;
}

void rotate(vector<vector<char>> &a) {
    int N = a.size();
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            char temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

int main() {
//    boost();
    int N, n;
    while (cin >> N >> n) {
        if (N == 0 && n == 0) break;
        vector<vector<char>> V(N);
        vector<vector<char>> v(n);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char x;
                cin >> x;
                V[i].push_back(x);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char x;
                cin >> x;
                v[i].push_back(x);
            }
        }
        int num = 0;
        for (int k = 0; k < 4; k++) {
            for (int i = 0; i <= N - n; i++) {
                for (int j = 0; j <= N - n; j++) {
                    if (isPart(V, v, i, j)) {
                        ++num;
                    }
                }
            }
            if (k == 3)
                cout << num << "\n";
            else
                cout << num << " ";
            num = 0;
            rotate(v);
        }
    }
}