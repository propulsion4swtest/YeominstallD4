/**
 * swea 7853
 */

#include <iostream>

#define MOD 1000000007

bool dict[1000][26];

void openDict (void) {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 26; j++) {
            dict[i][j] = false;
        }
    }
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        long long num = 1;
        std::string original;
        std::cin >> original;
        openDict();
        for (int i = 0; i < original.size(); i++) {
            if (i != 0) {
                dict[i][original.at(i-1) - 'a'] = true;
            }
            dict[i][original.at(i) - 'a'] = true;
            if (i != (original.size() - 1)) {
                dict[i][original.at(i+1) - 'a'] = true;
            }
        }
        for (int i = 0; i < original.size(); i++) {
            int counter = 0;
            for (int j = 0; j < 26; j++) {
                if (dict[i][j]) {
                    counter++;
                }
            }
            (num *= counter) %= MOD;
        }
        std::cout << "#" << tc << " " << num << "\n";
    }
    return 0;
}