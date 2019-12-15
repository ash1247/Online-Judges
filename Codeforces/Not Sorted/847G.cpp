#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define REPR(i,a,b) for (int i = a; i >= b; --i)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef pair<lli, lli> plli;

const int MAXK = 16;
const int MAXN = 5010 * MAXK;

int n;
vs grp;

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
    grp.resize(n);
    REP(i, 0, n - 1) {
        cin >> grp[i];
    }    
}

void solve() {
    int ans = 0;
    REP(col, 0, 6){
        int cnt = 0;
        REP(row, 0, n - 1) {
            cnt += grp[row][col] - '0';
        }
        ans = (ans > cnt) ? ans : cnt;
    }
    std::cout << ans << std::endl;
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}