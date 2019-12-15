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
vi weather;

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
    weather.resize(n);
    REP(i, 0, n - 1) {
        cin >> weather[i];
    }    
}

void solve() {
    int diff = weather[1] - weather[0];
    bool prog = true;
    REP(i, 1, n - 1) {
        if(weather[i] - weather[i - 1] != diff) {
            prog = false; 
            break;
        }
    }
    cout << (weather.back() + (prog ? diff : 0)) << std::endl;
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}
