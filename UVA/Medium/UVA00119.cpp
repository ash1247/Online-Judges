#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

int main() {
    int givers_num, receivers_num, amount;
    string givers_name, receivers_name;
    map<string, int> msi;
    vector<string> vs;

    cin >> givers_num;

    while(1) {
        vs.clear();
        msi.clear();
        for(int i = 0; i < givers_num; i++) {
            cin >> givers_name;
            vs.push_back(givers_name);
        }

        for(int i = 0; i < givers_num; i++) {
            cin >> givers_name >> amount >> receivers_num;
            if (receivers_num != 0)
                msi[givers_name] -= receivers_num*(amount/receivers_num);

            for(int j = 0; j < receivers_num; ++j) {
                cin >> receivers_name;
                msi[receivers_name] += (amount / receivers_num);
            }
        }
        for(int i = 0; i < givers_num; ++i) {
            cout << vs[i] << " " << msi[vs[i]] << endl;
        }
        if (cin >> givers_num)
            cout << endl;
        else break;
    }
    return 0;
}
