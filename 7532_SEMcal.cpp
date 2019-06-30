/**
 * swea 7532
 */

#include <iostream>

int main (void) {
    std::cin.tie(0);std::cout.tie(0);std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int S, E, M;
        std::cin >> S >> E >> M;
        for (int cs = S; cs <= 254040; cs += 365) {
            if (((cs - E) % 24 == 0) && ((cs - M) % 29) == 0) {
                std::cout << "#" << tc << " " << cs << "\n";
                break;
            }
        }
    }
    return 0;
}