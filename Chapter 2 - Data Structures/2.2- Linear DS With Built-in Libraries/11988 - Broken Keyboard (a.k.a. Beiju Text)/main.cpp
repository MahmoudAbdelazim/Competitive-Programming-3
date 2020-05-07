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
    //boost();
    //=======================================================================
    list<char> l;
    string str;
    char cur = 'e';
    int count = 1;
    while (cin >> str) {
        l.clear();
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[') {
                cur = 'f';
            } else if (str[i] == ']') {
                cur = 'e';
            }
            else {
                if (cur == 'f') {
                    string tmp;
                    for (int j = i; j < str.size() && str[j] != '[' && str[j] != ']'; j++) {
                        tmp += str[j];
                        i = j;
                    }
                    for (int j = tmp.size() - 1; j >= 0; j--) {
                        l.push_front(tmp[j]);
                    }
                } else {
                    l.push_back(str[i]);
                }
            }
        }
        for (char & it : l) {
            cout << it;
        }
        cout << "\n";
    }
}