#include <bits/stdc++.h>

using namespace std;

vector<pair<int, double>> v;

int main() {
    int m, n;
    double payment, cost, current_cost, org_cost;
    while (cin >> m) {
        cin >> payment >> cost >> n;
        org_cost = cost;
        current_cost = cost + payment;
        if (m < 0)
            return 0;
        int month;
        double per;
        for (int i = 0; i < n; i++) {
            cin >> month >> per;
            if (i == 0) {
                v.emplace_back(month, per);
            }
            else {
                if (month > v[v.size() - 1].first + 1) {
                    for (int j = v[v.size() - 1].first+1; j < month; j++) {
                        v.emplace_back(j, v[v.size() - 1].second);
                    }
                }
                v.emplace_back(month, per);
            }
        }
        if (month < m) {
            for (int i = month+1; i <= m; i++) {
                v.emplace_back(i, per);
            }
        }
        for (int i = 0; i <= m; i++) {
            if (i > 0)
                cost -= (org_cost / m);
            current_cost -= current_cost * v[i].second;
            if (cost < current_cost) {
                cout << v[i].first << " " << ((v[i].first == 1) ? "month" : "months") << endl;
                break;
            }
        }
        v.clear();
    }
    return 0;
}
