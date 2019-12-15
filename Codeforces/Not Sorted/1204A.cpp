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

const int MAXK = 16;
const int MAXN = 5010 * MAXK;

string s;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> s;
}

void solve() {
    int l = s.size();
    int cnt = 0;
    REP(i, 0, l - 1) {
        if (s[i] == '1')
            cnt++;
        if (cnt > 1)
            break;
    }
    if (l == 0) {
        cout << 0 << endl;
        return;
    }
    cout << (cnt > 1 ? ceil(l / 2.00) : 
                ceil((l - 1.00) / 2.00)) << endl;
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}