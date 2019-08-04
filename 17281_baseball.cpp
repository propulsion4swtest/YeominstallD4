/**
 * boj 17281
 */
#include <bits/stdc++.h>

int N;
int runner[50][9];
int r[8] = {1, 2, 3, 4, 5, 6, 7, 8};

void printPerm (void) {
    for (int i = 0; i < 8; i++) {
        std::cout << r[i] << " ";
    }
    std::cout << "\n";
}

int multiplexer (int m) {
    return (m < 3) ? m : m-1;
} 

int runGame (void) {
    std::cin.tie(0); std::cout.tie(0); std::ios_base::sync_with_stdio(0);
    int q[200];
    int score = 0, out = 0, base = 0, curr;
    int i = 0, j = 0;
    for (i = 0; i < N; i++) {
        for (; ; j++) {
            j %= 9;
            curr = (j == 3) ? runner[i][0] : runner[i][r[multiplexer(j)]];
            if (curr == 0) {
                ++out;
                out %= 3;
                if (out == 0) {j++; break;}
                continue;
            }
            ++base;
            for (int k = 0; k < curr; k++) {
                base <<= 1;
                score += (base >> 4);
                base &= 15;
            }
        }
        base = 0;
    }
    return score;
}

int main (void) {
    int i, j, cs, max_score = -1;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        for (j = 0; j < 9; j++) {
            std::cin >> runner[i][j];
        }
    }
    do {
        cs = runGame();
        // if (cs > max_score) {
        //     for (i = 0; i < 8; i++) {
        //         if (i == 3) std::cout << "  ";
        //         std::cout << runner[0][r[i]] << " ";
        //     }
        //     std::cout << ": " << cs << "\n";
        // }
        max_score = (cs > max_score) ? cs : max_score;
    } while (std::next_permutation(r, r+8));
    std::cout << max_score << "\n";
    return 0;
}