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

struct item {
    int nxt;
    int q;
    int t;
};

bool operator < (const item &lp,const item &rp) {
    if (lp.nxt == rp.nxt) return lp.q < rp.q;
    return lp.nxt < rp.nxt;
}

priority_queue<item> pq;
string str; int q, p;

int main() {
    boost();

    while (cin >> str) {
        if (str == "#") break;
        item pr;
        cin >> pr.q >> pr.t;
        pr.nxt = pr.t;
        pr.q = -pr.q; pr.t = -pr.t; pr.nxt = -pr.nxt;
        pq.push(pr);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        item pr = pq.top(); pq.pop();
        cout << -pr.q << "\n";
        pr.nxt += pr.t;
        pq.push(pr);
    }
}