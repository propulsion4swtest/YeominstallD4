/**
 * swea 4013
 */

#include <iostream>

int magnet[4][8];

int getScore (void) {
    int score = 0;
    for (int i = 0; i < 4; i++) {
        score += magnet[i][0] << i;
    }
    return score;
}

void turnMagnet (int mn, int cw) {
    int tmp;
    if (cw == 1) {      // clockwise
        tmp = magnet[mn][7];
        for (int i = 7; i > 0; i--) {
            magnet[mn][i] = magnet[mn][i-1];
        }
        magnet[mn][0] = tmp;
    } else {            // counter clockwise
        tmp = magnet[mn][0];
        for (int i = 0; i < 7; i++) {
            magnet[mn][i] = magnet[mn][i+1];
        }
        magnet[mn][7] = tmp;
    }
}

void printMagnet (void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << magnet[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main (void) {
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int K, m, cw;
        bool flag[3] = {false, false, false};
        std::cin >> K;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                std::cin >> magnet[i][j];
            }
        }
        std::cout << "[cinprint]\n"; printMagnet();
        for (int i = 0; i < K; i++) {
            std::cin >> m >> cw;
            --m;
            for (int j = 0; j < 3; j++) {
                if (magnet[j][2] != magnet[j+1][6]) {
                    flag[j] = true;
                } else {
                    flag[j] = false;
                }
            }
            turnMagnet (m, cw);
            int lw = cw * (-1), rw = cw * (-1);
            for (int left = 1; m - left >= 0; left++) {
                if (m - left >= 0 && flag[m-left]) {
                    turnMagnet (m - left, lw);
                    lw *= -1;
                } else { break; }
            }
            for (int right = 1; m + right < 4; right++) {
                if (m + right < 4 && flag[m+right-1]) {
                    turnMagnet (m + right, rw);
                    rw *= -1;
                } else { break; }
            }
            printMagnet();
        }
        std::cout << "#" << tc << " " << getScore() << "\n";
    }
}