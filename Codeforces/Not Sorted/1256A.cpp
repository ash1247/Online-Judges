#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;
typedef long long int lli;


void fileio(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    fastio();
    int q;
    long long int a, b, n, S;
    cin >> q; 
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> n >> S;
        long long x = min(S / n, a);
        S -= x * n;
        cout << (S <= b ? "YES\n" : "NO\n");
    }
    return 0;
}