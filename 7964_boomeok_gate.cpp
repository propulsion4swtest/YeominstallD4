/**
 * swea 7964
 */
#include <iostream>

int kingdom[300000];

void resetKingdom (void) {
    for (int i = 0; i < 300000; i++) {
        kingdom[i] = 0;
    }
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, D, dist, new_gate = 0;
        std::cin >> N >> D;
        dist = D;
        for (int i = 0; i < N; i++) {
            std::cin >> kingdom[i];
            if (kingdom[i] == 0) {
                if (--dist == 0) {
                    new_gate++;
                    dist = D;
                }
            } else {
                dist = D;
            }
        }
        std::cout << "#" << tc << " " << new_gate << "\n";
    }
}