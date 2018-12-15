#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l, b;
    int count = 1;
    cin >> l >> b;
    while(l < b) {
        l *= 3;
        b *= 2;
        count++;
        if ( l > b)
            count--;
    }

    cout << count << "\n";
    return 0;
}
