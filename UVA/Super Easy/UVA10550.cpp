#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.ignore(0);
    int u, v, w, x, ans;
    while(cin >> u >> v >> w >> x, (u || v || w || x)) {
        ans = 1080;
        ans += ((u-v+40) % 40 + (w-v+40) % 40 + (w-x+40) % 40) * 9;
        cout << ans << "\n";
    }
}
