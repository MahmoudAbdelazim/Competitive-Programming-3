#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sort(v) sort(v.begin(), v.end())

int main() {
    cin.sync_with_stdio(0);

    double h, u, d, f;
    while (cin >> h) {
        cin >> u >> d >> f;
        if (h == 0)
            break;
        f = f/100.0 * u;
        double cur = 0;
        int day = 0;
        while (cur >= 0 && cur <= h) {
            day++;
            cur += u;
            if (cur > h)
                break;
            cur -= d;
            if (cur < 0)
                break;
            u -= f;
            if (u < 0)
                u = 0;
        }
        if (cur < 0)
            cout << "failure on day " << day << endl;
        else
            cout << "success on day "<< day << endl;
    }
}
