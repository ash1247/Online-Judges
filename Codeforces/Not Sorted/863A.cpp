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
    auto it = s.end() - 1;
    while (*it == '0')
        --it;
    string str(s.begin(), it + 1);
    string rev_str(str.rbegin(), str.rend());
    cout << (str == rev_str ? "YES" : "NO") << endl;
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}