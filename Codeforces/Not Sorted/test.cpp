#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string str) {
    const int NO_OF_CHARS = 256;
    int n = str.size();
    if (n == 0)
        return 0;
    int cur_len = 1;
    int max_len = 1;
    int prev_index;
    
    int visited[NO_OF_CHARS];
    for (int i = 0; i < NO_OF_CHARS; ++i) {
        visited[i] = -1;
    }
    visited[str[0]] = 0;
    
    for (int i = 1; i < n; ++i) {
        prev_index = visited[str[i]];
        if (prev_index == -1 || i - cur_len > prev_index)
            cur_len++;
        else {
            if (cur_len > max_len)
                max_len = cur_len;
            cur_len = i - prev_index;
        }
        visited[str[i]] = i;
    }

    int count = 0;
    for (auto x : visited) {
        cout << char(count++) << "  " << x << endl;
    }
    if (cur_len > max_len)
        max_len = cur_len;
    
    return max_len;
}

int main() {
    cout << lengthOfLongestSubstring("ABCDEFGABCEDE");
}