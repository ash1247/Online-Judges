#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define REPR(i,a,b) for (int i = a; i >= b; --i)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;

const int MAX = 1e6+6;

int n;
vi cnt(101, 0);
set<int> si;

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
    REP (i, 0, n - 1) {
        int p;
        cin >> p;
        si.insert(p);
        cnt[p]++;
    }
}

void solve() {
    vi sv(si.begin(), si.end());
    if (sv.size() == 2 and cnt[sv[0]] == cnt[sv[1]]) {
        cout << "YES\n";
        cout << sv[0] << " " << sv[1] << endl;
        return;
    }
    cout << "NO\n";
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}