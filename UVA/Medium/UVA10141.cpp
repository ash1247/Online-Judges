#include <iostream>
#include <cfloat>

using namespace std;

int main() {
    int req, prop;
    int count = 0;
    string x;

    while (cin >> req >> prop, (req || prop)) {
        count++;

        string prop_name, name;
        double price = DBL_MAX, p;
        int req_met = -1, rm;

        for (int i = 0; i < req; i++) {
            cin.ignore();
            getline(cin, x);
        }

        while(prop--) {
            getline(cin, name);
            cin >> p >> rm;
            if(rm > req_met) {
                req_met = rm;
                price = p;
                prop_name = name;
            } else if ( rm == req_met && p < price) {
                req_met = rm;
                price = p;
                prop_name = name;
            }

            for (int i = 0; i < rm; i++) {
                cin.ignore();
                getline(cin, x);
            }
        }

        if(count > 1)
            cout << "\n";
        cout << "RFP #" << count << endl;
        cout << prop_name << endl;
    }
}
