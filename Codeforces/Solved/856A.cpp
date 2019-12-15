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

int t, n;
vi v(MAX);
vector<bool> check(MAX);

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
    REP (i, 1, n) 
        cin >> v[i];
}

void solve() {
    cout << "YES\n";
    int p = 1;
    REP (i, 1, n) {
        cout << p << ((i == n) ? " \n" : " ");
        REP (j, 1, n) {
            REP (k, 1, n) {
                int l = p + v[j] - v[k];
                if (1 <= l and l <= 1000000)
                    check[l] = true;
            }
        }
        while (check[p]) p++;
    }
    REP(i, 1, 1000000) check[i] = false;
}

int main() {
    fast_io();
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}