#include <iostream>
#include <vector>
 
int T, N, M, x, y, stone, black = 1, white = 2;
int game[8][8] = {0, };

int dx[8] = {0, 0, -1, 1, -1, 1, 1, -1};
int dy[8] = {1, -1, 0, 0, -1, -1, 1, 1};
 
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
            game[tracker.at(i).second][tracker.at(i).first] = col;
        }
    }
    tracker.clear();
}
 
int main(void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
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
            for (int i = 0; i < 8; i++) {
                check(y, x, dy[i], dx[i], stone, reverse);
            }
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