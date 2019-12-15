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

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {

}

void input() {
    int t, check;
    cin >> t;
    while (t--) {
        check = 0;
        int x, y;
        cin >> x >> y;
        if (x == 2 | x == 3) {
            if (y == 1 | y == 2 | y == 3)
                check = 1;
        }
        if (x == 1) {
            if (y == 1)
                check = 1;
        }
        if (x > 3)
            check = 1;
        
        cout << (check == 1 ? "YES" : "NO") << endl; 
    }
}

int main() {
    fast_io();
    input(); 
    return 0;
}