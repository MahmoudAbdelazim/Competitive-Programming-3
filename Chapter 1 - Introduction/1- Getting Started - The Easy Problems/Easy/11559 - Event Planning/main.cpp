#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sort(v) sort(v.begin(), v.end())

int main() {
    cin.sync_with_stdio(0);
    int N, B, H, W, p, Min = 5000001;
    while (cin >> N) {
        Min = 5000001;
        cin >> B >> H >> W;
        for (int j = 0; j < H; j++) {
            cin >> p;
            for (int i = 0, u; i < W; i++) {
                cin >> u;
                if (u >= N) {
                    Min = min(Min, N * p);
                }
            }
        }
        if (Min <= B)
            cout << Min << endl;
        else
            cout << "stay home" << endl;
    }
}
