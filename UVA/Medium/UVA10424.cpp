#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int love_calculator(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i]))
            sum += s[i] - 'a' + 1;
        if (isupper(s[i]))
            sum += s[i] - 'A' + 1;
    }
    if (sum % 9 == 0) {
        return 9;
    } else {
        return sum % 9;
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.ignore(0);
    string name1, name2;
    while(getline(cin, name1)) {
        getline(cin, name2);
        double ratio;
        double sum1 = love_calculator(name1);
        double sum2 = love_calculator(name2);

        ratio = min(sum1/ sum2, sum2/sum1);
        printf("%.2lf %%\n", ratio*100);
    }
    return 0;
}
