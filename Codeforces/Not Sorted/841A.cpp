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

int n, k;
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
    cin >> n >> k;
    cin >> s;
}
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    vi cnt(26, 0);
    REP (i, 0, s.length() - 1) {
        // cout << s[i] << (s[i] - 'a') << endl;
        cnt[s[i] - 'a']++;
    }
    sort(cnt.begin(), cnt.end(), cmp);
    
    cout << (cnt[0] > k ? "NO" : "YES") << endl;
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}