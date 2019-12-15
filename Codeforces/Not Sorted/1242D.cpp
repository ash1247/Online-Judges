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

lli k;

void file_io(char *input,char *output) {
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

plli last_sum(lli n) {
    if (n < k * (k + 1) / 2) {
        return {0, 0};
    }
    lli start_cnd = (n - k * (k + 1) / 2) / k + 1;
    auto it = last_sum(start_cnd + (k - 1));
    lli sum_val = it.FS;
    lli sum_cnt = it.SC;

    lli num_prev = (sum_val - sum_cnt) / k;
    lli pref_size = (sum_val - sum_cnt) % k;
    lli suff_size = k - pref_size;
    lli wrap_sum = (sum_val - pref_size) * k + k * (k - 1) / 2 + suff_size;

    if (wrap_sum > n) 
        return {(sum_val - pref_size - k) * k + k * (k - 1) / 2, num_prev};
    assert(wrap_sum <= n);
    lli next_sum = (sum_val + suff_size + 1) * k + k * (k - 1) / 2;
    if (next_sum > n) 
        return {wrap_sum, num_prev + 1};
    else {
        lli incr = (n - next_sum) / (k * k);
        return {next_sum + k * k * incr, num_prev + 1 + 1 + incr};
    }
}

lli solve(lli n) {
    auto it = last_sum(n);
    lli sum_val = it.FS;
    lli sum_cnt = it.SC;
    if (sum_val == n) 
        return sum_cnt * (k + 1);
    return n - sum_cnt + (n - sum_cnt - 1) / k;
}

void input() {
    int t; lli n;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << solve(n) << endl;
    }
}

int main() {
    fast_io();
    input(); 
    return 0;
}