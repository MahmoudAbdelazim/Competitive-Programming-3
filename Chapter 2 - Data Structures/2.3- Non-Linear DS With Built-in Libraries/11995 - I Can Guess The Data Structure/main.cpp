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

int main() {
    boost();
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        vector<int> resS;
        vector<int> resQ;
        vector<int> resPQ;
        vector<int> res;
        bool impossible = false;
        for (int i = 0; i < n; i++) {
            int op, x;
            cin >> op >> x;
            if (op == 1) {
                s.push(x);
                q.push(x);
                pq.push(x);
            } else {
                res.push_back(x);
                if (s.empty() && q.empty() && pq.empty()) impossible = true;
                else {
                    if (!s.empty()) {
                        resS.push_back(s.top());
                        s.pop();
                    }
                    if (!q.empty()) {
                        resQ.push_back(q.front());
                        q.pop();
                    }
                    if (!pq.empty()) {
                        resPQ.push_back(pq.top());
                        pq.pop();
                    }
                }
            }
        }
        if ((res == resS && res == resQ)
        || (res == resS && res == resPQ)
        || (res == resQ && res == resPQ)) cout << "not sure\n";
        else if (impossible) cout << "impossible\n";
        else if (res == resS) cout << "stack\n";
        else if (res == resQ) cout << "queue\n";
        else if (res == resPQ) cout << "priority queue\n";
        else cout << "impossible\n";
    }
}