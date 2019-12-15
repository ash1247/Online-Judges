#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)

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
    fast_io();
    int k, n;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> n;
        int arr[n], ans = 0;
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        sort(arr, arr + n);
        reverse(arr, arr + n);
        for (int p = 0; p < n; ++p) {
            if (arr[p] >= p + 1)
                ans = p + 1;          
        }
        cout << ans << endl;
    }
    
}