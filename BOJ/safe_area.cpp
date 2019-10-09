/**
 * boj 2468
 */
#include <iostream>
#include <cstring>
#include <queue>

#define __OOB__(x,y)    (x < 0 || x >= N || y < 0 || y >= N)

using namespace std;

int N;
int land[100][100];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

bool visited[100][100];

void bfs (int y, int x) {
    queue<int> coords;
    int pos_x, pos_y, next_x, next_y;
    coords.push(y); coords.push(x);
    while(!coords.empty()) {
        pos_y = coords.front(); coords.pop();
        pos_x = coords.front(); coords.pop();
        for (int i = 0; i < 4; i++) {
            next_y = pos_y + dir[i][0];
            next_x = pos_x + dir[i][1];
            if (!__OOB__(next_x, next_y) && !visited[next_y][next_x] && land[next_y][next_x] != 0) {
                visited[next_y][next_x] = true;
                coords.push(next_y); coords.push(next_x);
            }
        }
    }
}

int countArea (int cnt) {
    int c = 0;   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (land[i][j] != 0 && !visited[i][j]) {
                c++;
                visited[i][j] = true;
                bfs (i, j);
            }
        }
    }
    return max(c, cnt);
}

int main (void) {
    cin >> N;
    int remains = N * N;
    int hst = -1, lst = 101;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> land[i][j];
            hst = max(hst, land[i][j]);
            lst = min(lst, land[i][j]);
        }
    }
    if (hst == lst) {
        cout << 1 << "\n";
        return 0;
    }
    int cnt = 1, rain = lst - 1;
    while (remains > 1) {
        rain++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (land[i][j] == rain) {
                    land[i][j] = 0;
                    remains--;
                }
            }
        }
        cnt = countArea(cnt);
    }
    cout << cnt << "\n";

    return 0;
}