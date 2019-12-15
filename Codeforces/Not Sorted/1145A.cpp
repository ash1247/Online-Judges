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

int thanos_sort(int *arr, int start, int end) {
    bool check = false;
    int count = 1, mid = (start + end) / 2;
    for (int i = start; i < end; i++) {
        if (arr[i] > arr[i + 1]) {
            check = true;
            break;
        }
        count++;
    }
    if (!check)
        return count;
    count = max(thanos_sort(arr, start, mid),
                    thanos_sort(arr, mid + 1, end));
    return count;
}

int main() {
    fast_io();
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
                            
    cout << thanos_sort(arr, 1, n) << endl;

}