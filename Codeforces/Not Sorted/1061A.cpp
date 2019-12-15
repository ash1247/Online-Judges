#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 1.1e5;
lli s, n;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> n >> s;
}

void solve() {
    lli ans = (s + n - 1) / n;
    cout << ans << endl;
}

int main() {
    fast_io();
    input();
    solve();    
    return 0;
}