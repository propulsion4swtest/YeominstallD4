/**
 * swea 1953
 */
#include <bits/stdc++.h>

using namespace std;

int N, M, R, C, L;
int ug[50][50];
int q[300][2];
int front, rear, t;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[50][50];

// LUDR
bool pipemap[8][4] = {
    0, 0, 0, 0,
    1, 1, 1, 1,
    0, 1, 1, 0,
    1, 0, 0, 1,
    0, 1, 0, 1,
    0, 0, 1, 1,
    1, 0, 1, 0,
    1, 1, 0, 0
};

void resetVisited (void) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            visited[i][j] = 0;
        }
    }
}

bool isPipe (int y, int x, int dir) {
    return pipemap[ug[y][x]][dir];
}

bool isRange (int y, int x) {
    if (y < 0 || y >= R || x < 0 || x >= C) return false;
    return true;
}

int opposite (int dir) {
    switch(dir) {
        case 0:
            return 3;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 0;
    }
}

void dojuRange (int py, int px, int time) {
    resetVisited();
    front = 0, rear = 0, t = 0;
    int bx, by, cx, cy;
    q[rear][0] = py; q[rear][1] = px;
    visited[py][px] = true;
    ++rear; ++t;
    for (int i = 1; i < time; i++) {
        while (front != t) {
            by = q[front][0];
            bx = q[front][1];
            for (int j = 0; j < 4; j++) {
                if (!isPipe(by, bx, j)) continue;
                cy = by + dy[j];
                cx = bx + dx[j];
                if (!isPipe(cy, cx, opposite(j)) || visited[cy][cx]) continue;
                q[rear][0] = cy;
                q[rear][1] = cx;
                rear++;
                visited[cy][cx] = true;
            }
            front++;
        }
        t = rear;
    }
}

int PossRange (void) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) cnt++;
        }
    }
    return cnt;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, i, j;
    cin >> T;
    for (tc = 1; tc <= T; ++tc) {
        cin >> N >> M >> R >> C >> L;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                cin >> ug[i][j];
            }
        }
        dojuRange(R, C, L);
        cout << "#" << tc << " " << PossRange() << "\n";
    }
    return 0;
}