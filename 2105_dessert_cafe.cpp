#include <bits/stdc++.h>

using namespace std;

int N;
int ground[20][20];
bool memomap[20][20][10];
bool isPath[20][20];
int dx[4] = {1, -1, -1, 1};     // URDL
int dy[4] = {1, 1, -1, -1};

void printMemo (void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << isPath[i][j] << " ";
        }
        cout << "\n";
    }
}

void resetMemo (void) {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            for (int k = 0; k < 10; k++) {
                memomap[i][j][k] = false;
            }
        }
    }
}

bool roundTripOn (int px, int py) {
    int curr, cx, cy;
    bool pathFlag = true;
    for (int i = 0; i < 4; i++) {
        cx = px+dx[i]; cy = py+dy[i];
        if (cx < 0 || cx >= N || cy < 0 || cy >= N) return false;
        curr = ground[cy][cx];
        if (memomap[py][px][curr]) pathFlag = false;
        else memomap[py][px][curr] = true;
    }
    return pathFlag;
}

int main (void) {
    int T, tc, i, j, ip;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        int max_visit = -1;
        cin >> N;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cin >> ground[i][j];
            }
        }
        resetMemo();
        for (i = 0; i < N-2; i++) {
            for (j = 1; j < N-1; j++) {
                isPath[i][j] = roundTripOn(j, i);
            }
        }
        cout << "#" << tc << "\n";
        printMemo();
    }
    return 0;
}