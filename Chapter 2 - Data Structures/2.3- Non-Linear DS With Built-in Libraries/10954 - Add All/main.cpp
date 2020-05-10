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

int n;
priority_queue<int> pq;

int main() {
    boost();
    while (cin >> n, n) {
        for (int i = 0, x; i < n; i++) {
            cin >> x; x = -x; pq.push(x);
        }
        int totalCur = 0;
        while (pq.size() > 1) {
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();
            totalCur += (top1 + top2);
            pq.push(top1 + top2);
        }
        cout << -totalCur << "\n";
        while (!pq.empty()) pq.pop();
    }
}