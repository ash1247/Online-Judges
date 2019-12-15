#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;


string s, t;
int n;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> n;
    cin >> s >> t;
}

void solve() {
    vector<int> counts(26, 0);
    for (char c : s) {
        counts[c - 'a']++;
    }
    for (char c : t) {
        counts[c - 'a']++;
    }
    for (int i : counts) {
        if (i & 1) {
            cout << "NO\n";
            return;
        }
    }
    vector<pii> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i])
            continue;
        bool found = 0;
        for (int j = i + 1; j < n; ++j) {
            if (t[i] == t[j]) {
                ans.push_back({i, j});
                swap(s[i], t[j]);
                found = true;
                break;
            }
        }
        if (found) continue;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == t[i]) {
                ans.push_back({j, i + 1});
                swap(s[j], t[i + 1]);
                ans.push_back({i, i + 1});
                swap(s[i], t[i + 1]);
                break;
            }
        }
    }
    cout << "YES\n" << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.FS + 1 << " " << i.SC + 1 << endl;
    }
}

int main() {
    fast_io();
    int k;
    cin >> k;
    while (k--) {
        input();
        solve();    
    }
    return 0;
}