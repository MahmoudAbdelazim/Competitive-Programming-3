#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(a[0])))
#define All(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define cube(x) (x) * (x) * (x)
#define INF (int)1e8 + 7
#define INFL 1000000005L
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 0
#define mod 1000000

void boost() {
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
//    boost();
    int c, s;
    int cnt = 1;
    while (scanf("%d %d", &c, &s) != EOF) {
        vi v(s);
        double sum = 0;
        for (int i = 0; i < s; i++) {
            scanf("%d", &v[i]);
            sum += v[i];
        }
        double avg = sum / (double) c;
        while (v.size() != 2 * c) v.push_back(0);
        sort(All(v));
        vector<vi> ans(c);
        for (int i = 0, j = 2 * c - 1; i < j; i++, j--) {
            ans[i].push_back(v[i]);
            ans[i].push_back(v[j]);
        }
        double imbalance = 0.0;
        for (int i = 0; i < c; i++) {
            double sumC = 0;
            for (int j : ans[i]) {
                sumC += j;
            }
            imbalance += fabs(sumC - avg);
        }
        int chamber = 0;
        printf("Set #%d\n", cnt++);
        for (int i = 0; i < c; i++) {
            printf(" %d:", chamber++);
            if (v[i]) printf(" %d", v[i]);
            if (v[2 * c - i - 1]) printf(" %d", v[2 * c - i - 1]);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
}

