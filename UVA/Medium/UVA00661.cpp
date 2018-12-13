#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, c, maxpower, total, sequence = 1;
    bool blown;

    while(cin >> n >> m >> c, (n || m || c)) {
        maxpower = total = 0;
        blown = false;
        vector<int> vin(n);
        vector<bool> vbm(m);

        for (int i = 0; i < n; i++) {
            cin >> vin[i];
            vbm[i] = false;
        }
        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            if (!vbm[temp-1]) {
                total += vin[temp-1];
                vbm[temp-1] = !vbm[temp-1];
            } else {
                total -= vin[temp-1];
                vbm[temp-1] = !vbm[temp-1];
            }
            if (total > c) {
                blown = true;
            } else {
                maxpower = max(total, maxpower);
            }
        }
        printf("Sequence %d\n", sequence);
        if (blown) {
            printf("Fuse was blown.\n\n");
        } else {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n", maxpower);
        }
        sequence++;
    }
}
