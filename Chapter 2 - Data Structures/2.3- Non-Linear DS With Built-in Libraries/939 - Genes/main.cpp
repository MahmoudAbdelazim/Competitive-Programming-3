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

    int n;
    cin >> n;
    map<string, string> genes;
    map<string, pair<string, string>> parents;
    set<string> output;
    while (n--) {
        string str1, str2;
        cin >> str1 >> str2;
        if (str2 == "non-existent" || str2 == "recessive" || str2 == "dominant") {
            genes[str1] = str2;
            output.insert(str1.append(" ").append(str2));
        }
        else {
            if (parents[str2].first.empty())
                parents[str2].first = str1;
            else {
                parents[str2].second = str1;
            }
        }
    }
    while (true) {
        bool allKnown = true;
        for (auto it = parents.begin(); it != parents.end(); it++) {
            if (genes[it->second.first].empty() || genes[it->second.second].empty()) {
                allKnown = false;
                continue;
            }
            if ((genes[it->second.first] == "recessive" && genes[it->second.second] == "recessive")
                || (genes[it->second.first] == "dominant" || genes[it->second.second] == "dominant")) {
                if ((genes[it->second.first] == "dominant" && genes[it->second.second] == "dominant")
                    || (genes[it->second.first] == "dominant" && genes[it->second.second] == "recessive")
                    || (genes[it->second.first] == "recessive" && genes[it->second.second] == "dominant")) {
                    genes[it->first] = "dominant";
                } else {
                    genes[it->first] = "recessive";
                }
            } else {
                genes[it->first] = "non-existent";
            }
            string str = it->first;
            output.insert(str.append(" ").append(genes[it->first]));
        }
        if (allKnown) break;
    }
    for (auto it = output.begin(); it != output.end(); it++)
        cout << *it << "\n";
}