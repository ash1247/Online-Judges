#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.ignore(0);
    char s[1000005];
    int cas = 0;
    while (scanf("%s", s) != EOF ) {
        int n, i, j, mn, mx;
        cin >> n;
        cas++;
        cout << "Case " << cas << ":\n";
        bool check;
        while (n--) {
            cin >> i >> j;
            mn = min(i, j);
            mx = max(i, j);
            check = true;
            for (int x = mn; x < mx; x++) {
                if (s[x] != s[x+1]) {
                    check = false;
                }
            }
            cout << ((check) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}
