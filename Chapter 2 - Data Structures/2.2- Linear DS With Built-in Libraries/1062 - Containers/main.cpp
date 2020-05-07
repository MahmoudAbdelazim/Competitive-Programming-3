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
    string str;
    int count = 1;
    while (cin >> str) {
        vector<stack<char>> stacks(26);
        if (str == "end") break;
        int cur = 0;
        for (int i = 0; i < str.size(); i++) {
            if (stacks[cur].empty())
                stacks[cur].push(str[i]);
            else {
                bool foundStack = false;
                for (int j = 0; j <= cur; j++) {
                    if (stacks[j].top() >= str[i]) {
                        stacks[j].push(str[i]);
                        foundStack = true;
                        break;
                    }
                }
                if (!foundStack) {
                    cur++;
                    i--;
                }
            }
        }
        cout << "Case " << count << ": " << cur + 1 << "\n";
        ++count;
    }
}