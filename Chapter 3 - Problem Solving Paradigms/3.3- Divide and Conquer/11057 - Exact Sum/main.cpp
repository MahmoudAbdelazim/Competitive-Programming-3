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

int N, M;
vi books;

int main() {
//    boost();
    while (cin >> N) {
        books.clear();
        books.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> books[i];
        }
        cin >> M;
        int cur = 0;
        sort(All(books));
        int a = -1, b = -1;
        vii sol;
        for (int i = 0; i < N; i++) {
            a = i;
            int s = 0, e = N - 1;
            cur = books[a];
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (mid == i) mid++;
                b = mid;
                cur += books[b];
                if (cur == M) {
                    break;
                } else if (cur < M) {
                    s = mid + 1;
                    cur = books[a];
                } else {
                    int oldE = e;
                    e = mid - 1;
                    if (e == oldE) e--;
                    cur = books[a];
                }
            }
            if (cur == M) {
                sol.emplace_back(books[a], books[b]);
                a = -1, b = -1;
            }
        }
        int mnDiff = abs(sol[0].second - sol[0].first);
        int mnIdx = 0;
        for (int i = 1; i < sol.size(); i++) {
            if (abs(sol[i].second - sol[i].first) < mnDiff) {
                mnDiff = abs(sol[i].second - sol[i].first);
                mnIdx = i;
            }
        }
        a = sol[mnIdx].first, b = sol[mnIdx].second;
        cout << "Peter should buy books whose prices are " << (a < b ? a : b) << " and "
             << (a > b ? a : b) << ".\n\n";
    }
}