/**
 * swea 1244
 */

#include <iostream>

int pool[6];
int p;

void setPool (int N) {
    p = 0;
    for (p = 0; p < 6; p++) {
        pool[p] = 0;
    }
    while (N != 0) {
        pool[p++] = N % 10;
        N /= 10;
    }
}

void swap (void) {
    int max  = -1, max_i;
    for (int i = 0; i < p; i++) {
        if (max < pool[i]) {
            max = pool[i];
            max_i = i;
        }
    }
    
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, c;
        std::cin >> N >> c;
        p = setPool(N);
        for (int i = 0; i < c; i++) {
            swap();
        }
        std::cout << "#" << tc;
        for (int i = 0; i < p; i++) {
            std::cout << pool[i];
        }
        std::cout << "\n";
    }
}