#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;

lli n;

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
}

void solve() {
    lli div = 2, sq = sqrtl(n) + 1;
    while (div <= sq) {
        if (n % div == 0) {
            break;
        }
        div++;
    }
    if (n % div != 0) {
        cout << n << endl;
        return;
    }
    lli left = n;
    while (left % div == 0) {
        left /= div;
    }
    if (left == 1) {
        cout << div << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    fast_io();
    input();
    solve();    
    return 0;
}