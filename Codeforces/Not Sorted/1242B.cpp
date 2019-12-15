#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; i++)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = 1.1e5;
int m, n;
set<int> adj[MAXN];

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> n >> m;
    for (int e = 0; e < m; ++e) {
        int a , b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
}

void solve() {
    vector<int> unadded;
    for (int i = 0; i < n; i++) {
        unadded.push_back(i);
    }
    vector<int> added;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (i >= added.size()) {
            ans++;
            added.push_back(unadded.back());
            unadded.pop_back();
        }
        int cur = added[i];
        vector<int> no_unadded;
        for (int v : unadded) {
            if (adj[cur].count(v)) {
                no_unadded.push_back(v);
            } else added.push_back(v);
        }
        unadded = move(no_unadded);
    }
    cout << ans << '\n';
}

int main() {
    fast_io();
    input();
    solve();    
    return 0;
}