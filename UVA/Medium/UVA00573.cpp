#include <iostream>

using namespace std;

int main() {
    int h, u, f;
    double d;
    bool check;
    while ( cin >> h >> d >> u >> f, (h || d || u || f) ) {
        double sum = 0;
        double perc = 0;
        int day = 0;
        perc = d * ((double)f/100);
        check = false;
        while( sum < h && sum >= 0) {
            if ( d < 0)
                d = 0;
            // cout << day << " " << sum << endl;
            sum += d;
            day++;
            if ( sum > h) {
                // cout << day << " " << sum << endl;
                check = true;
                break;
            }
            sum -= u;
            d -= perc;
            // cout << d << endl;
        }
        cout << (check ? "success " : "failure ") << "on day " << day << endl;
    }
}
