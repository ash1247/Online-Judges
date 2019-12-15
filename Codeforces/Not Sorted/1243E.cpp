#include <bits/stdc++.h>

#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define REPR(i,a,b) for (int i = a; i >= b; --i)
#define FS first
#define SC second

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;

const int MAXK = 16;
const int MAXN = 5010 * MAXK;

int N;
int k;
lli arr[MAXN];
lli sum[MAXK];
lli total;
int box_num[MAXN];
map<lli, int> item_num;

int nxt[MAXN];
int visited[MAXN];
vi cyc_items[1 << MAXK];
int prv[1 << MAXK];


void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

void input() {
    cin >> k;
    REP (i, 0, k - 1) {
        int n;
        cin >> n;
        REP (j, 0, n - 1) {
            cin >> arr[N];
            box_num[N] = i;
            sum[i] += arr[N];
            total += arr[N];
            item_num[arr[N]] = N;
            N++; 
        }
    }
}
void check_cycle() {
    REP (i, 0, N - 1) {
        lli nxt_a = total - (sum[box_num[i]] - arr[i]);
        if (!item_num.count(nxt_a)) {
            nxt[i] = -1;
        } else {
            nxt[i] = item_num[nxt_a];
        }
    }
    REP (i, 0, N - 1) {
        if (visited[i]) continue;
        int cur = i;
        visited[cur] = i + 1;
        while (true) {
            cur = nxt[cur];
            if (cur == -1) break;
            if (visited[cur] == i + 1) break;
            else if (visited[cur]) {
                cur = -1;
                break;
            }
            visited[cur] = i + 1;
        }
        if (cur == -1) {
            continue;
        }

        int st = cur;
        int mask = 0;
        vi cyc;
        do {
            if (mask & (1 << box_num[cur])) {
                mask = -1;
                break;
            } else {
                mask |= (1 << box_num[cur]);
            }
            cyc.push_back(cur);
            cur = nxt[cur];
        } while (cur != st);
        if (mask == -1) {
            continue;
        }
        cyc_items[mask] = cyc;
    }
    for (int m = 1; m < (1 << k); ++m) {
        prv[m] = -1;
        for (int v = m; v > 0; v = (v - 1) & m) {
            if (!cyc_items[v].empty() && prv[m ^ v] != -1) {
                prv[m] = v;
                break;
            }    
        }
    }
}

void solve() { 
    if (total % k != 0) {
        cout << "No\n";
        return;
    }
    total /= k;
    check_cycle();
    if (prv[(1 << k) - 1] == -1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<plli> ans(k);
    for (int m = (1 << k) - 1; m > 0; m ^= prv[m]) {
        vi cyc = cyc_items[prv[m]];
        for (int i = 0; i < int(cyc.size()); ++i) {
            int cur = cyc[i], nxt = cyc[(i + 1) % int(cyc.size())];
            ans[box_num[nxt]] = {arr[nxt], box_num[cur]};
        }
    }

    REP (i, 0, k - 1) {
        cout << ans[i].FS << " " << ans[i].SC + 1 << endl; 
    }
}

int main() {
    fast_io();
    input();
    solve(); 
    return 0;
}