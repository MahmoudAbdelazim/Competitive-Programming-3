#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> v;
    int k = 1;
    while (t--) {
        v.resize(3);
        for (int i = 0; i < 3; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        cout << "Case " << k << ": " << v[1] << endl;
        k++;
    }
    v.clear();
    return 0;
}