/**
 * swea 2819
 */
#include <bits/stdc++.h>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char grid[4][4];
std::set<std::string> quilt;

void dfs (std::string s, int px, int py) {
    s = s + grid[py][px];
    if (s.size() == 7) {
        quilt.insert(s);
        return;
    }
    for (int k = 0; k < 4; k++) {
        if (px+dx[k] >= 0 && px+dx[k] < 4 && py+dy[k] >= 0 && py+dy[k] < 4){
            dfs (s, px+dx[k], py+dy[k]);
        }
    }
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T, tc, i, j;
    std::cin >> T;
    for (tc = 1; tc <= T; ++tc)  {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                std::cin >> grid[i][j];
            }
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                std::string ept;
                dfs(ept, j, i);
            }
        }
        std::cout << "#" << tc << " " << quilt.size() << "\n";
        quilt.clear();
    }
}