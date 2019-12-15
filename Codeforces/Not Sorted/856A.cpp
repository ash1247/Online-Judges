#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPR(i, a, b) for (int i = a; i >= b; --i)
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

int t;
int f[1000009];
int a[109];

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> t;
}

void solve() {
    while(t--) {
        int n;
        cin >> n;
        REP(i, 0, n - 1)
            cin >> a[i];
        sort(a, a + n);
        REP(i, 0, n - 1) {
            REP(j, i + 1, n - 1) {
                f[a[j] - a[i]] = t + 1;
                //cout << a[j] - a[i] << endl;
            }
        }
        int flag = 0;
        REP(i, 1, 10000) {
            flag=0;
            for(int j = i; j <= i * (n - 1); j += i) {
                if(f[j] == t + 1) {
                    flag = 1; 
                    //cout << i << " " << j << " " << f[j] << endl;
                    break;
                }
            }
            // cout << i << " " << flag << endl;
            if(flag == 0) {
                cout << "YES" << endl;
                for(int j = 1; j <= 1 + (n - 1) * i; j += i)
                    cout << j << " ";
                cout << endl;
                break;
            }
        }
    }    
}

int main() {
    fast_io();
    input();
    solve();
    return 0;
}
