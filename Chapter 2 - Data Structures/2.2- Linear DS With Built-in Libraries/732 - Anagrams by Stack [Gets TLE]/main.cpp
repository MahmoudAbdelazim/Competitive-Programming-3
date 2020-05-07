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


int main() {
    boost();
    //=======================================================================
    string src, dest;
    while (cin >> src) {
        cin >> dest;
        int n = src.size();
        cout << "[\n";
        if (n == dest.size()) {
            vector<string> v;
            string curPermutation;
            curPermutation += string(n, 'i');
            curPermutation += string(n, 'o');
            string limit;
            for (int i = 0; i < 2 * n - 2; i++) {
                if (i % 2 == 0) {
                    limit.push_back('i');
                } else {
                    limit.push_back('o');
                }
            }
            limit.push_back('o');
            limit.push_back('i');
            while (curPermutation != limit) {
                string res;
                stack<char> stk1;
                int idx = 0;
                for (int i = 0; i < 2 * n; i++) {
                    if (curPermutation[i] == 'i') {
                        stk1.push(src[idx]);
                        ++idx;
                    } else {
                        if (!stk1.empty()) {
                            res.push_back(stk1.top());
                            stk1.pop();
                        } else {
                            res = "";
                            break;
                        }
                    }
                }
                if (res == dest) {
                    v.push_back(curPermutation);
                }
                next_permutation(curPermutation.begin(), curPermutation.end());
            }
            sort(All(v));
            for (auto & i : v) {
                for (char &c: i) {
                    cout << c << " ";
                }
                cout << "\n";
            }
        }
        cout << "]\n";
    }
}