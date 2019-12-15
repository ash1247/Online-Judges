#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define REPR(i,a,b) for (int i = a; i >= b; --i)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 1.1e5;
int n;
set<int> exists;
vi ans;

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
    int arr[n];
    REP (i, 0, n - 1) {
        cin >> arr[i];
    }
    REPR(i, n - 1, 0) {
        if (exists.find(arr[i]) == exists.end())
            ans.push_back(arr[i]);
        exists.insert(arr[i]);
    }
}

void solve() {
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) 
        cout << i << " ";
    cout << endl;
}

int main() {
    fast_io();
    input();
    solve();    
    return 0;
}