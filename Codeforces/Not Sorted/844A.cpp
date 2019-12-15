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

string str;
int k;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> str >> k;
}
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    set<char> s;
    REP(i, 0, str.length() - 1)
        s.insert(str[i]);
    if (str.length() < k) {
        cout << "impossible" << endl;
        return;
    }
    if (k < s.size()) {
        cout << 0 << endl;
        return;
    }
    cout << k - s.size() << endl;
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}