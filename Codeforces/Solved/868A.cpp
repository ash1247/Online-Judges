#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define REPR(i,a,b) for (int i = a; i >= b; --i)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;

const int MAX = 1e6+6;

string pw;
int n;
vs v;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> pw;
    cin >> n;
    v.resize(n);
    REP (i, 0, n - 1) {
        cin >> v[i];
    }
}

void solve() {
    bool check =  false;
    REP (i, 0, n - 1) {
        if (check) break;
        REP (j, 0, n - 1) {
            string s = v[i] + v[j];
            if (s.find(pw) != string::npos) {
                check = true;
                break;
            }
        }
    }
    cout << (check ? "YES" : "NO") << endl;
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}