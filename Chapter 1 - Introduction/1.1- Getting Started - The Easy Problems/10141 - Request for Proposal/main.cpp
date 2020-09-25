#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sort(v) sort(v.begin(), v.end())

int main() {
    cin.sync_with_stdio(0);

    int n, p, req;
    double price;
    string str, s, h;
    double lowest_price = 1e9;
    int k = 1;
    bool first = true;
    while (cin >> n) {
        cin >> p;
        if (n == 0)
            break;
        if (!first)
            cout << endl;
        if (n > 0)
            cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, str);
        }
        int mx = -1;
        for (int i = 0; i < p; i++) {
            getline(cin, s);
            cin >> price >> req;
            cin.ignore();
            for (int j = 0; j < req; j++)
                getline(cin, str);
            if (req > mx) {
                mx = req;
                h = s;
                lowest_price = price;
            } else if (req == mx) {
                if (price < lowest_price) {
                    h = s;
                    lowest_price = price;
                }
            }
        }
        first = false;
        cout << "RFP #" << k << endl << h << endl;
        k++;
    }
}
