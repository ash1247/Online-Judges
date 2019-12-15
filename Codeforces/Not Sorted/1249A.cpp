#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<int> vi;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    int q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (abs(arr[i] - arr[j]) == 1)
                    ok = 0;
            }
        }
        cout << 2 - ok << endl;
    }
    return 0;
}