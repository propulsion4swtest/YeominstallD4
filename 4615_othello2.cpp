#include <iostream>
#include <vector>
 
int T, N, M, x, y, stone, black = 1, white = 2;
int game[8][8] = {0, };
 
void initGame (int N) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i >= N && j >= N) {
                game[i][j] = -1;
            } else {
                game[i][j] = 0;
            }
        }
    }
    game[N/2][N/2] = 2;
    game[N/2-1][N/2-1] = 2;
    game[N/2][N/2-1] = 1;
    game[N/2-1][N/2] = 1;
}

void check (int y, int x, int m_x, int m_y, int col, int rev) {
    std::vector<std::pair<int, int>> tracker;
    int checker = -1;
    y += m_y; x += m_x;
    while (y >= 0 && y < N && x >= 0 && x < N) {
        if (game[y][x] == rev) {
            tracker.push_back({x, y});
        }
        if (game[y][x] == col) {
            checker = 1;
            break;
        }
        if (game[y][x] == 0) {
            break;
        }
        y += m_y;
        x += m_x;
    }
    if (checker == 1 && !tracker.empty()) {
        for (int i = 0; i < tracker.size(); i++) {
            game[tracker.]
        }
    }
}
 
void checkUp (int col_y, int col_x, int col_stone, int rev_stone) {
    std::vector<int> tracker;
    int checker = -1;
    for (int p = col_y-1; p >= 0; p--) {
        if (game[p][col_x] == rev_stone) {
            tracker.push_back(p);
        }
        if (game[p][col_x] == col_stone) {
            checker = 1;
            break;
        }
        if (game[p][col_x] == 0) {
            break;
        }
    }
    if (checker == 1 && !tracker.empty()) {
        for (std::vector<int>::iterator it = tracker.begin(); it != tracker.end(); it++) {
            game[*it][col_x] = col_stone;
        }
    }
    tracker.clear();
}
 
void checkDown (int col_y, int col_x, int col_stone, int rev_stone) {
    std::vector<int> tracker;
    int checker = -1;
    for (int p = col_y+1; p < N; p++) {
        if (game[p][col_x] == rev_stone) {
            tracker.push_back(p);
        }
        if (game[p][col_x] == col_stone) {
            checker = 1;
            break;
        }
        if (game[p][col_x] == 0) {
            break;
        }
    }
    if (checker == 1 && !tracker.empty()) {
        for (std::vector<int>::iterator it = tracker.begin(); it != tracker.end(); it++) {
            game[*it][col_x] = col_stone;
        }
    }
    tracker.clear();
}
 
void checkLeft (int col_y, int col_x, int col_stone, int rev_stone) {
    std::vector<int> tracker;
    int checker = -1;
    for (int p = col_x-1; p >= 0; p--) {
        if (game[col_y][p] == rev_stone) {
            tracker.push_back(p);
        }
        if (game[col_y][p] == col_stone) {
            checker = 1;
            break;
        }
        if (game[col_y][p] == 0) {
            break;
        }
    }
    if (checker == 1 && !tracker.empty()) {
        for (std::vector<int>::iterator it = tracker.begin(); it != tracker.end(); it++) {
            game[col_y][*it] = col_stone;
        }
    }
    tracker.clear();
}
 
void checkRight (int col_y, int col_x, int col_stone, int rev_stone) {
    std::vector<int> tracker;
    int checker = -1;
    for (int p = col_x+1; p < N; p++) {
        if (game[col_y][p] == rev_stone) {
            tracker.push_back(p);
        }
        if (game[col_y][p] == col_stone) {
            checker = 1;
            break;
        }
        if (game[col_y][p] == 0) {
            break;
        }
    }
    if (checker == 1 && !tracker.empty()) {
        for (std::vector<int>::iterator it = tracker.begin(); it != tracker.end(); it++) {
            game[col_y][*it] = col_stone;
        }
    }
    tracker.clear();
}
 
void checkRightUp (int col_y, int col_x, int col_stone, int rev_stone) {
    int tracker[8][2] = {-1, }; int p = 0;
    int checker = -1;
    int i = 1;
    col_y--;col_x++;
    while (col_y >= 0 && col_y < N && col_x >= 0 && col_x < N) {
        if (game[col_y][col_x] == rev_stone) {
            tracker[p][0] = col_y;
            tracker[p][1] = col_x;
            p++;
            col_y--;col_x++;
            continue;
        }
        if (game[col_y][col_x] == col_stone) {
            checker = 1;
            break;
        }
        if (game[col_y][col_x] == 0) {
            break;
        }
    }
    if (checker == 1 && tracker[0][0] != -1) {
        for (int it = 0; it != p; it++) {
            game[tracker[it][0]][tracker[it][1]] = col_stone;
        }
    }
}
 
void checkLeftDown (int col_y, int col_x, int col_stone, int rev_stone) {
    int tracker[8][2] = {-1, }; int p = 0;
    int checker = -1;
    col_y++; col_x--;
    while (col_y >= 0 && col_y < N && col_x >= 0 && col_x < N) {
        if (game[col_y][col_x] == rev_stone) {
            tracker[p][0] = col_y;
            tracker[p][1] = col_x;
            p++;
            col_y++; col_x--;
            continue;
        }
        if (game[col_y][col_x] == col_stone) {
            checker = 1;
            break;
        }
        if (game[col_y][col_x] == 0) {
            break;
        }
    }
    if (checker == 1 && tracker[0][0] != -1) {
        for (int it = 0; it != p; it++) {
            game[tracker[it][0]][tracker[it][1]] = col_stone;
        }
    }
}
 
void checkLeftUp (int col_y, int col_x, int col_stone, int rev_stone) {
    int tracker[8][2]; int p = 0;
    int checker = -1;
    col_y--; col_x--;
    while (col_y >= 0 && col_y < N && col_x >= 0 && col_x < N) {
        if (game[col_y][col_x] == rev_stone) {
            tracker[p][0] = col_y;
            tracker[p][1] = col_x;
            p++;
            col_y--; col_x--;
            continue;
        }
        if (game[col_y][col_x] == col_stone) {
            checker = 1;
            break;
        }
        if (game[col_y][col_x] == 0) {
            break;
        }
    }
    if (checker == 1 && tracker[0][0] != -1) {
        for (int it = 0; it != p; it++) {
            game[tracker[it][0]][tracker[it][1]] = col_stone;
        }
    }
}
 
void checkRightDown (int col_y, int col_x, int col_stone, int rev_stone) {
    int tracker[8][2] = {-1, }; int p = 0;
    int checker = -1;
    col_y++; col_x++;
    while (col_y >= 0 && col_y < N && col_x >= 0 && col_x < N) {
        if (game[col_y][col_x] == rev_stone) {
            tracker[p][0] = col_y;
            tracker[p][1] = col_x;
            p++;
            col_y++; col_x++;
            continue;
        }
        if (game[col_y][col_x] == col_stone) {
            checker = 1;
            break;
        }
        if (game[col_y][col_x] == 0) {
            break;
        }
    }
    if (checker == 1 && tracker[0][0] != -1) {
        for (int it = 0; it != p; it++) {
            game[tracker[it][0]][tracker[it][1]] = col_stone;
        }
    }
}
 
int main(void) {
    int reverse;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        std::cin >> N >> M;
        initGame(N);
        for (int turn = 0; turn < M; turn++) {
            std::cin >> x >> y >> stone;
            x -= 1; y -= 1;
            // change stones
            game[y][x] = stone;
             
            if (stone == 1) {
                reverse = 2;
            } else {
                reverse = 1;
            }
            // check col
            checkUp (y, x, stone, reverse);
            checkDown (y, x, stone, reverse);
            // check row
            checkLeft (y, x, stone, reverse);
            checkRight (y, x, stone, reverse);
            // check slash
            checkLeftDown (y, x, stone, reverse);
            checkLeftUp (y, x, stone, reverse);
            checkRightDown (y, x, stone, reverse);
            checkRightUp (y, x, stone, reverse);
        }
        black = 0; white = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (game[i][j] == 1) {
                    black++;
                }
                if (game[i][j] == 2) {
                    white++;
                }
            }
        }
 
        std::cout << "#" << tc << " " << black << " " << white << "\n";
        // clear game
 
    }
    return 0;
}