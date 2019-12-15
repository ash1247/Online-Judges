#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef long long int lli;
typedef vector<int> vi;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    fast_io();
    int k, n;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n;
        string s, t;
        vector<int> v;
        int check = 0;
        cin >> s;
        cin >> t;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                v.push_back(i);
            }
        }
        int size = v.size();
        if (size > 2)
            check = 1;
        if (size != 1) {
            if (size == 2) {
                swap(s[v[0]], t[v[1]]);
            }
        }
        cout << (check == 1 || s != t ? "NO\n" : "YES\n");    
    }
    
}